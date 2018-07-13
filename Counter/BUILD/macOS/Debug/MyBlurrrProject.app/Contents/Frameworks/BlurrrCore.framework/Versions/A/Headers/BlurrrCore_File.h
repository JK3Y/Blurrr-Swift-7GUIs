#ifndef BLURRRCORE_FILE_H
#define BLURRRCORE_FILE_H

#ifndef BLURRRCORE_EXPORTS_H
#include "BlurrrCore_Exports.h"
#endif

#ifdef __cplusplus
extern "C" {
#endif

#include <stddef.h>
#include <stdbool.h>
#include <stdint.h>

/**
 * FileSystem API
 */

struct BlurrrFileHandle;
typedef struct BlurrrFileHandle BlurrrFileHandle;


/**
 * Creates a directory.
 * This will not create intermediate subdirectories.
 * @see BlurrrFile_MakeDirectoryRecursively
 * @return returns true is successful. If the directory already exists, it will return true.
 */
BLURRRCORE_EXPORT bool BLURRRCORE_CALL BlurrrFile_MakeDirectory(const char* the_path);

/**
 * Creates a directory with any intermediate directories that would also need to be created.
 * @return returns true is successful. If the directory already exists, it will return true.
 */
BLURRRCORE_EXPORT bool BLURRRCORE_CALL BlurrrFile_MakeDirectoryRecursively(const char* the_path);


/**
 * Removes a directory.
 * The directory must be empty
 * @see BlurrrFile_RemoveDirectoryRecursively
 * @return returns true is successful.
 */
BLURRRCORE_EXPORT bool BLURRRCORE_CALL BlurrrFile_RemoveDirectory(const char* the_path);


/**
 * Removes a directory along with all its files and subdirectories.
 * @note You should use absolute paths.
 * @see BlurrrPath_GetRealPathString, BlurrrPath_CreateRealPathString.
 * @return returns true is successful.
 */
BLURRRCORE_EXPORT bool BLURRRCORE_CALL BlurrrFile_RemoveDirectoryRecursively(const char* the_path);

/**
 * Deletes a file
 * @return true if successful.
 */
BLURRRCORE_EXPORT bool BLURRRCORE_CALL BlurrrFile_RemoveFile(const char* the_file);

/**
 * Determines if a file exists.
 * @return true if successful.
 */
BLURRRCORE_EXPORT bool BLURRRCORE_CALL BlurrrFile_FileExists(const char* the_file);



/**
 * Changes the current working directory.
 * @return true if successful.
 * @see BlurrrPath_GetCurrentDirectoryString, BlurrrPath_CreateCurrentDirectoryString
 */
BLURRRCORE_EXPORT bool BLURRRCORE_CALL BlurrrFile_ChangeCurrentDirectory(const char* the_path);

/**
 * Copies a file.
 * @return true if successful.
 * @note Currently overwrites existing files.
 */
BLURRRCORE_EXPORT bool BLURRRCORE_CALL BlurrrFile_CopyFile(const char* src_file, const char* dst_file);

/**
 * Copies a directory recursively.
 * @return true if successful.
 */
BLURRRCORE_EXPORT bool BLURRRCORE_CALL BlurrrFile_CopyDirectory(const char* src_path, const char* dst_path);

/**
 * Renames a file or directory.
 * @return true if successful.
 */
BLURRRCORE_EXPORT bool BLURRRCORE_CALL BlurrrFile_Rename(const char* old_name, const char* new_name);

/**
 * Opens a file.
 * @return returns a file handle if successful.
 */
BLURRRCORE_EXPORT struct BlurrrFileHandle* BLURRRCORE_CALL BlurrrFile_Open(const char* file_name, const char* mode);

/**
 * Closes a file.
 * @return 0 on success.
 */
BLURRRCORE_EXPORT int BLURRRCORE_CALL BlurrrFile_Close(struct BlurrrFileHandle* file_handle);

/**
 * Reads data from a file.
 * @param file_handle The file_handle to read from.
 * @param data_buffer The data buffer to copy read data into
 * @param size Size in bytes of how long each nitem-object is.
 * @param nitems Number of items (objects) to read.
 * @return returns number of bytes read. Negative or short of requested value on error.
 */
BLURRRCORE_EXPORT size_t BLURRRCORE_CALL BlurrrFile_Read(struct BlurrrFileHandle* file_handle, char* data_buffer, size_t size, size_t nitems);

/**
 * Writes data to a file.
 * @param file_handle The file_handle to write.
 * @param data_buffer The data buffer to copy data from. 
 * @param size Size in bytes of how long each nitem-object is.
 * @param nitems Number of items (objects) to write.
 * @return returns number of bytes written. Negative or short of requested value on error.
 */
BLURRRCORE_EXPORT size_t BLURRRCORE_CALL BlurrrFile_Write(struct BlurrrFileHandle* file_handle, char* data_buffer, size_t size, size_t nitems);

/**
 * Gets the size of a file.
 * @param file_handle The file_handle.
 * @return Size in bytes.
 */
BLURRRCORE_EXPORT int64_t BLURRRCORE_CALL BlurrrFile_Size(struct BlurrrFileHandle* file_handle);

/**
 * Gets the size of a file.
 * @param file_handle The file_handle to write.
 * @param whence SEEK_SET, SEEK_CUR, SEEK_END from ANSI fseek().
 * @return Size in bytes.
 */
BLURRRCORE_EXPORT bool BLURRRCORE_CALL BlurrrFile_Seek(struct BlurrrFileHandle* file_handle, int64_t offset, int whence);

/**
 * Gets the current position of the file handle.
 * @param file_handle The file_handle.
 * @return Positin in bytes.
 */
BLURRRCORE_EXPORT int64_t BLURRRCORE_CALL BlurrrFile_Tell(struct BlurrrFileHandle* file_handle);

/**
 * Rewinds the position of the file handle to the beginning.
 * @param file_handle The file_handle.
 * @return  True on success.
 */
BLURRRCORE_EXPORT bool BLURRRCORE_CALL BlurrrFile_Rewind(struct BlurrrFileHandle* file_handle);



#ifdef __cplusplus
}
#endif

#endif /* BLURRRCORE_FILE_H */
