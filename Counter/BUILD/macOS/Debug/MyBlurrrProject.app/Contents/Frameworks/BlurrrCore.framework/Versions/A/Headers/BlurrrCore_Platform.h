#ifndef BLURRRCORE_PLATFORM_H
#define BLURRRCORE_PLATFORM_H

#ifndef BLURRRCORE_EXPORTS_H
#include "BlurrrCore_Exports.h"
#endif

#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>


/**
 * Platform specific API
 */


/**
 * @brief Gets a string describing the OS family name.
 * @return A string constant with the name of the platform. Do not call free() on this string.
 * Values may be: iOS, tvOS, watchOS, macOS, Android, Windows, Linux.
 */
BLURRRCORE_EXPORT const char* BLURRRCORE_CALL BlurrrPlatform_GetOSFamilyString(void);

/**
 * @brief A grab bag function that returns true or false for various platform properties.
 * @param query_string Values may be: "Raspberry Pi", "iPhone", "iPad".
 * @return true or false depending if the property is true for the current platform.
 */
BLURRRCORE_EXPORT bool BLURRRCORE_CALL BlurrrPlatform_IsQuery(const char* query_string);


#if defined(__ANDROID__)
/**
 * @brief Sets the application context.
 * Many APIs on Android require a Context parameter, which is like a God-object. 
 * Android does not provide any helpful APIs to get this object, even though everything depends on it.
 * So a context must be provided in order for many functions to work in BlurrrCore.
 * Special exceptions are in the case of SDL and IUP which BlurrrCore has special knowledge of and will jump through hoops to use their APIs to get the Context.
 * You must always call this function if you are not creating a normal/proper IUP or SDL app.
 * @param This is a jobject from JNI of your Context. Activity is a kind of Context so you may use that. 
 * @note This will hold a strong reference to the object you pass in until changed or Quit.
 */
BLURRRCORE_EXPORT void BLURRRCORE_CALL BlurrrPlatformAndroid_SetApplicationContext(void* app_context);

/**
 * Returns the application context being used.
 * @return This is a jobject from JNI of the Context being used. void* is used to avoid needing to #include <jni.h> which brings in a lot of gunk.
 */
BLURRRCORE_EXPORT void* BLURRRCORE_CALL BlurrrPlatformAndroid_GetApplicationContext(void);

/**
 * Returns the JNIEnv.
 */
BLURRRCORE_EXPORT void* BLURRRCORE_CALL BlurrrPlatformAndroid_GetJNIEnv(void);

#elif _WIN32

#include <wchar.h>
/**
 * Convert from UTF8 to Windows wide string.
 * @return You must free this memory when you are done.
 * @see BlurrrCore_Free
 */
BLURRRCORE_EXPORT wchar_t* BLURRRCORE_CALL BlurrrPlatformWindows_CreateWINfromUTF8String(const char* input_str);

/**
 * Convert from Windows wide string to UTF8.
 * @return You must free this memory when you are done.
 * @see BlurrrCore_Free
 */
BLURRRCORE_EXPORT char* BLURRRCORE_CALL BlurrrPlatformWindows_CreateUTF8fromWINString(const wchar_t* input_wstr);


#endif 


#ifdef __cplusplus
}
#endif

#endif /* BLURRRCORE_PLATFORM_H */

