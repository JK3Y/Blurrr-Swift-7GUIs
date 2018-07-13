#ifndef BLURRRCORE_PROCESS_H
#define BLURRRCORE_PROCESS_H

#ifndef BLURRRCORE_EXPORTS_H
#include "BlurrrCore_Exports.h"
#endif

#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>
#include <stddef.h>

/**
 * @brief Opens a URL in another app.
 * @detailed This is a fire-and-forget way to open a URL in another app. This does not block. There is nothing to clean up.
 * @return Returns false if it was detected that opening the URL failed. Returns true otherwise.
 * It is possible for process to still fail but the platform may not be able to provide a return status 
 * value at the invocation point so do not put too much credence in this value.
 * @note Expect your app to lose focus when this happens.
 */
BLURRRCORE_EXPORT bool BLURRRCORE_CALL BlurrrProcess_OpenURL(const char* the_url);


struct BlurrrProcessInfo;

/**
 * Executes a new process.
 * On Unix, this is posix_spawnp. On Windows, this is CreateProcess.
 * @executable_command The executable to run. Absolute path recommended. This makes its own copy of data so you may change/free your argument after this call.
 * @argv array of string arguments. Must be NULL terminated. This makes its own copy of data so you may change/free your argument after this call.
 * @working_directory The full path to the current working directory for the process to start in. May be NULL to use the current working directory.
 * @return Returns an object representing the process.
 * @note You must 'pump' the process periodically to make sure pipe data is being handled, etc. Call BlurrrProcess_UpdateProcess with the returned object until the process ends.
 * @note This is only available on some platforms. (Available: Linux, OS X, Windows, Raspbian. Not available: iOS, Android) 
 * @see BlurrrProcess_UpdateProcess
 */
BLURRRCORE_EXPORT struct BlurrrProcessInfo* BLURRRCORE_CALL BlurrrProcess_CreateProcess(const char* executable_command, char* argv[], const char* working_directory);

/**
 * Frees the memory of the BlurrrProcessInfo.
 * The process should have ended before calling this.
 * Freeing while a process is still running is undefined and may cause leaks or bad things to happen.
 */
BLURRRCORE_EXPORT void BLURRRCORE_CALL BlurrrProcess_FreeProcessInfo(struct BlurrrProcessInfo* process_info);

/**
 * This updates the running process and returns to you whether the process is still running or not.
 * You must call this periodically until the process finishes.
 * This function does things such as reading/clearing the stdout/stderr buffers and updates its
 * internal copies of this data.
 * @return Returns 1 if still running, 0 if no longer running.
 */
BLURRRCORE_EXPORT int BLURRRCORE_CALL BlurrrProcess_UpdateProcess(struct BlurrrProcessInfo* process_info);
// Process must be finished first before this returns a valid value.
BLURRRCORE_EXPORT int BLURRRCORE_CALL BlurrrProcess_GetExitCode(struct BlurrrProcessInfo* process_info);

/**
 * Gets the stdout string of the process.
 * Pointer to internal memory that can change. Make your own copy if you need to save. Do not free this pointer.
 * This pointer and its contents may change/update with every call to UpdateProcess.
 * Use GetStdOutBufferSize to get the number of bytes read into this buffer.
 * This buffer will keep accumulating (appending) until you call ClearStdOutBuffer.
 * If your data and process is small and short, you might just wait until the process finishes and copy out this data.
 * But if you have a long process or generate a lot of data, you may want to read as you go, and call Clear to limit how much data is accumulated internally.
 * Also as a convenience, the character after the last byte will always be a NULL terminator, so if you know you have plain text data,
 * you can treat the buffer as a string. Note that in this case that strlen == BufferSize, as both don't count the NULL as part of the string.
 * @return A pointer containing a copy of the stdout string.
 * @see BlurrrProcess_GetStdOutBufferSize BlurrrProcess_ClearStdOutBuffer
 */
BLURRRCORE_EXPORT const char* BLURRRCORE_CALL BlurrrProcess_GetStdOutBuffer(struct BlurrrProcessInfo* process_info);

/**
 * Gets the stderr string of the process.
 * Pointer to internal memory that can change. Make your own copy if you need to save. Do not free this pointer.
 * This pointer and its contents may change/update with every call to UpdateProcess.
 * Use GetStdErrBufferSize to get the number of bytes read into this buffer.
 * This buffer will keep accumulating (appending) until you call ClearStdErrBuffer.
 * If your data and process is small and short, you might just wait until the process finishes and copy out this data.
 * But if you have a long process or generate a lot of data, you may want to read as you go, and call Clear to limit how much data is accumulated internally.
 * Also as a convenience, the character after the last byte will always be a NULL terminator, so if you know you have plain text data,
 * you can treat the buffer as a string. Note that in this case that strlen == BufferSize, as both don't count the NULL as part of the string.
 * @return A pointer containing a copy of the stderr string.
 * @see BlurrrProcess_GetStdErrBufferSize BlurrrProcess_ClearStdErrBuffer
 */
BLURRRCORE_EXPORT const char* BLURRRCORE_CALL BlurrrProcess_GetStdErrBuffer(struct BlurrrProcessInfo* process_info);

/**
 * Gets the number of bytes currently used in the StdOutBuffer.
 * This is useful, for example, if you want to memcpy out all the data from the buffer into your own copy.
 * Also as a convenience, the character after the last byte will always be a NULL terminator, so if you know you have plain text data,
 * you can treat the buffer as a string. Note that in this case that strlen == BufferSize, as both don't count the NULL as part of the string.
 * @return The number of bytes currently in the StdOutBuffer.
 */
BLURRRCORE_EXPORT size_t BLURRRCORE_CALL BlurrrProcess_GetStdOutBufferSize(struct BlurrrProcessInfo* blurrr_process_info);
/**
 * Gets the number of bytes currently used in the StdErrBuffer.
 * This is useful, for example, if you want to memcpy out all the data from the buffer into your own copy.
 * Also as a convenience, the character after the last byte will always be a NULL terminator, so if you know you have plain text data,
 * you can treat the buffer as a string. Note that in this case that strlen == BufferSize, as both don't count the NULL as part of the string.
 * @return The number of bytes currently in the StdErrBuffer.
 */
BLURRRCORE_EXPORT size_t BLURRRCORE_CALL BlurrrProcess_GetStdErrBufferSize(struct BlurrrProcessInfo* blurrr_process_info);

/**
 * This clears/resets the data in the StdOut buffer.
 * This is effectively like marking the data as read, so the next Update pass can reuse the buffer and overwrite the data rather than constantly appending.
 * This is useful, for example, if you are reading the buffer every Update iteration and only care about the new data since the previous iteration. Otherwise, the buffer will continue to append everything and your buffer will contain all the data since the start of the process.
 * For long processes that generate lots of output, you should consider using your data as you and call this function to limit how much memory is accumulated internally.
 */
BLURRRCORE_EXPORT void BLURRRCORE_CALL BlurrrProcess_ClearStdOutBuffer(struct BlurrrProcessInfo* blurrr_process_info);
/**
 * This clears/resets the data in the StdErr buffer.
 * This is effectively like marking the data as read, so the next Update pass can reuse the buffer and overwrite the data rather than constantly appending.
 * This is useful, for example, if you are reading the buffer every Update iteration and only care about the new data since the previous iteration. Otherwise, the buffer will continue to append everything and your buffer will contain all the data since the start of the process.
 * For long processes that generate lots of output, you should consider using your data as you and call this function to limit how much memory is accumulated internally.
 */
BLURRRCORE_EXPORT void BLURRRCORE_CALL BlurrrProcess_ClearStdErrBuffer(struct BlurrrProcessInfo* blurrr_process_info);


/**
 * Kills a process.
 * This probably shouldn't use and you should let the process end naturally.
 * Use as a last resort. Side-effects are operating system dependent.
 * @note This is only available on some platforms. (Available: Linux, OS X, Windows, Raspbian. Not available: iOS, Android) 
 */
BLURRRCORE_EXPORT void BLURRRCORE_CALL BlurrrProcess_KillProcess(struct BlurrrProcessInfo* blurrr_process_info);


#ifdef __cplusplus
}
#endif

#endif /* BLURRRCORE_PROCESS_H */

