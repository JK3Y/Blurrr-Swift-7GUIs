#ifndef BLURRRCORE_H
#define BLURRRCORE_H

#ifndef BLURRRCORE_EXPORTS_H
#include "BlurrrCore_Exports.h"
#endif

#ifndef BLURRRCORE_FILE_H
#include "BlurrrCore_File.h"
#endif

#ifndef BLURRRCORE_LOG_H
#include "BlurrrCore_Log.h"
#endif

#ifndef BLURRRCORE_PATH_H
#include "BlurrrCore_Path.h"
#endif

#ifndef BLURRRCORE_PLATFORM_H
#include "BlurrrCore_Platform.h"
#endif

#ifndef BLURRRCORE_PROCESS_H
#include "BlurrrCore_Process.h"
#endif

#ifndef BLURRRCORE_STDLIB_H
#include "BlurrrCore_Stdlib.h"
#endif

#ifndef BLURRRCORE_RANDOM_H
#include "BlurrrCore_Random.h"
#endif

#ifndef BLURRRCORE_TIMER_H
#include "BlurrrCore_TimeTicker.h"
#endif



#ifdef __cplusplus
extern "C" {
#endif

#include <stddef.h>
#include <stdarg.h>

/**
 * Init function for BlurrrCore.
 * @return Returns 1.
 * @see BlurrrCore_Quit
 */
BLURRRCORE_EXPORT int BLURRRCORE_CALL BlurrrCore_Init(void);


/**
 * Quit function for BlurrrCore.
 * @see BlurrrCore_Init
 */
BLURRRCORE_EXPORT void BLURRRCORE_CALL BlurrrCore_Quit(void);

/**
 * Frees dynamically allocated memory, typically by Create functions.
 * @note When compiled with SDL (normal case) this calls SDL_free. But for correctness, you should use this with Blurrr functions instead of SDL_free.
 */
BLURRRCORE_EXPORT void BLURRRCORE_CALL BlurrrCore_Free(void* the_data);

/**
 * Gets the last error message that was set.
 * @return string containing the error message.
 */
BLURRRCORE_EXPORT const char* BLURRRCORE_CALL BlurrrCore_GetError(void);

/**
 * Gets the last error message that was set.
 * @return string containing the error message.
 */
BLURRRCORE_EXPORT void BLURRRCORE_CALL BlurrrCore_SetError(const char* fmt, ...);

/**
 * Sets the error message.
 */
BLURRRCORE_EXPORT void BLURRRCORE_CALL BlurrrCore_SetError(const char* fmt, ...);

/**
 * Sets the error message.
 */
BLURRRCORE_EXPORT void BLURRRCORE_CALL BlurrrCore_SetErrorv(const char* fmt, va_list argp);



#ifdef __cplusplus
}
#endif

#endif /* BLURRRCORE_H */

