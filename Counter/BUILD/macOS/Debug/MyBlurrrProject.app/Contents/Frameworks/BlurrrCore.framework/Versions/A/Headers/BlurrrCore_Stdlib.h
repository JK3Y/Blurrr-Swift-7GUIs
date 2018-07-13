#ifndef BLURRRCORE_STDLIB_H
#define BLURRRCORE_STDLIB_H

#ifndef BLURRRCORE_EXPORTS_H
#include "BlurrrCore_Exports.h"
#endif

#ifdef __cplusplus
extern "C" {
#endif

#include <stddef.h>

/**
 * C standard library helper
 */

/**
 * strlcpy
 */
BLURRRCORE_EXPORT size_t BLURRRCORE_CALL BlurrrStdlib_strlcpy(char *dst, const char *src, size_t maxlen);

/**
 * strlcat
 */
BLURRRCORE_EXPORT size_t BLURRRCORE_CALL BlurrrStdlib_strlcat(char *dst, const char *src, size_t maxlen);

/**
 * strdup
 * @see BlurrrCore_Free
 */
BLURRRCORE_EXPORT char* BLURRRCORE_CALL BlurrrStdlib_strdup(const char* str);


#ifdef __cplusplus
}
#endif

#endif /* BLURRRCORE_STDLIB_H */
