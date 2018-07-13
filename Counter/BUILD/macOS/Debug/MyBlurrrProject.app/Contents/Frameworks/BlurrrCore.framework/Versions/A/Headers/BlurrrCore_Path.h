#ifndef BLURRRCORE_PATH_H
#define BLURRRCORE_PATH_H

#ifndef BLURRRCORE_EXPORTS_H
#include "BlurrrCore_Exports.h"
#endif

#ifdef __cplusplus
extern "C" {
#endif

#include <stddef.h>

/**
 * Same as SDL_GetBasePath() except that the Info.plist tricks are ignored on Apple platforms and it always returns the directory containing the .app bundle instead of the resource directory.
 * @note Apple users: This is directory containing the .app bundle, i.e. one directory above the Mac/Cocoa notion of the [mainBundle bundlePath]. This assumes you are building a proper .app bundle and not a flat exectuable.
 * @param string_array The buffer the result will be written into. Maybe NULL if you just want the return length.
 * @param array_length The length of the string_array buffer.
 * @return Returns the length needed for the resulting string, including the +1 for the \0 terminator. This value will return 0 if the resulting string is/would-be NULL. 
 * The passed in string will be null terminated if the value would be NULL.
 */
BLURRRCORE_EXPORT size_t BLURRRCORE_CALL BlurrrPath_GetBaseDirectoryString(char* string_array, size_t array_length);
/**
 * Same as SDL_GetBasePath() except that the Info.plist tricks are ignored on Apple platforms and it always returns the directory containing the .app bundle instead of the resource directory.
 * @note Apple users: This is directory containing the .app bundle, i.e. one directory above the Mac/Cocoa notion of the [mainBundle bundlePath]. This assumes you are building a proper .app bundle and not a flat exectuable.
 * Must free with BlurrrCore_Free.
 * @note Mac users: This is the top-level of the bundle, not the Mac/Cocoa notion of the [mainBundle exectuablePath].
 * @return Returns the string for the path to the executable directory. You must free this with BlurrrCore_Free when you are done.
 * This can return NULL (e.g. as SDL_GetBasePath() does for Android).
 */
BLURRRCORE_EXPORT char* BLURRRCORE_CALL BlurrrPath_CreateBaseDirectoryString(void);


/**
 * Directory where the executable is located. On most platforms, this is the same as SDL_GetBasePath().
 * @note Apple users: This is the directory containing the Cocoa [mainBundle exectuablePath].
 * @param string_array The buffer the result will be written into. Maybe NULL if you just want the return length.
 * @param array_length The length of the string_array buffer.
 * @return Returns the length needed for the resulting string, including the +1 for the \0 terminator. This value will return 0 if the resulting string is/would-be NULL. 
 * The passed in string will be null terminated if the value would be NULL.
 */
BLURRRCORE_EXPORT size_t BLURRRCORE_CALL BlurrrPath_GetExecutableDirectoryString(char* string_array, size_t array_length);
/**
 * Directory where the executable is located. On most platforms, this is the same as SDL_GetBasePath().
 * Must free with BlurrrCore_Free.
 * @note Apple users: This is the directory containing the Cocoa [mainBundle exectuablePath].
 * @return Returns the string for the path to the executable directory. You must free this with BlurrrCore_Free when you are done.
 * This can return NULL (e.g. as SDL_GetBasePath() does for Android).
 */
BLURRRCORE_EXPORT char* BLURRRCORE_CALL BlurrrPath_CreateExecutableDirectoryString(void);


/**
 * Returns a string to where modules (a.k.a plugins) are located. This will end with a trailing slash.
 * @param string_array The buffer the result will be written into. Maybe NULL if you just want the return length.
 * @param array_length The length of the string_array buffer.
 * @return Returns the length needed for the resulting string, including the +1 for the \0 terminator. This value will return 0 if the resulting string is/would-be NULL.
 * The passed in string will be null terminated if the value would be NULL.
 */
BLURRRCORE_EXPORT size_t BLURRRCORE_CALL BlurrrPath_GetModuleDirectoryString(char* string_array, size_t array_length);
/**
 * Returns a string to where modules (a.k.a plugins) are located. This will end with a trailing slash.
 * Must free with BlurrrCore_Free.
 * @return Returns the string for the path to the executable directory. You must free this with BlurrrCore_Free when you are done.
 * This can return NULL (e.g. as SDL_GetBasePath() does for Android).
 */
BLURRRCORE_EXPORT char* BLURRRCORE_CALL BlurrrPath_CreateModuleDirectoryString(void);


/**
 * Returns a string to where resources are located. This will end with a trailing slash.
 * @param string_array The buffer the result will be written into. Maybe NULL if you just want the return length.
 * @param array_length The length of the string_array buffer.
 * @return Returns the length needed for the resulting string, including the +1 for the \0 terminator. This value will return 0 if the resulting string is/would-be NULL.
 * The passed in string will be null terminated if the value would be NULL.
 */
BLURRRCORE_EXPORT size_t BLURRRCORE_CALL BlurrrPath_GetResourceDirectoryString(char* string_array, size_t array_length);
/**
 * Returns a string to where resources are located. This will end with a trailing slash.
 * Must free with BlurrrCore_Free.
 * @return Returns the string for the path to the executable directory. You must free this with BlurrrCore_Free when you are done.
 * This can return NULL (e.g. as SDL_GetBasePath() does for Android).
 */
BLURRRCORE_EXPORT char* BLURRRCORE_CALL BlurrrPath_CreateResourceDirectoryString(void);


/**
 * @brief Returns a string to where the cache directory is located. This will end with a trailing slash.
 * The cache directory is intended as a temporary directory, but slightly longer lived on some platforms than the temporary directory.
 * @param string_array The buffer the result will be written into. Maybe NULL if you just want the return length.
 * @param array_length The length of the string_array buffer.
 * @param organization_name Your reverse URI organization name, e.g. com.blurrrsdk
 * @param app_name The name of your app, e.g. MyBlurrrProj
 * @note Both the org and app strings may become part of a directory name, so please follow these rules:
 * Try to use the same org string (including case-sensitivity) for all your applications that use this function.
 * Always use a unique app string for each one, and make sure it never changes for an app once you've decided on it.
 * Unicode characters are legal, as long as it's UTF-8 encoded, only use letters, numbers, and spaces. 
 * The intention of this feature is to model how OS X, iOS, and Android create application identifiers.
 * So in the above example, the directory result would create com.blurrrsdk.MyBlurrrProj
 * @return Returns the length needed for the resulting string, including the +1 for the \0 terminator. This value will return 0 if the resulting string is/would-be NULL.
 * The passed in string will be null terminated if the value would be NULL.
 */
BLURRRCORE_EXPORT size_t BLURRRCORE_CALL BlurrrPath_GetCacheDirectoryString(char* string_array, size_t array_length, const char* organization_name, const char* app_name);
/**
 * Returns a string to where the cache directory is located. This will end with a trailing slash.
 * Must free with BlurrrCore_Free.
 * The cache directory is intended as a temporary directory, but slightly longer lived on some platforms than the temporary directory. 
 * @param organization_name Your reverse URI organization name, e.g. com.blurrrsdk
 * @param app_name The name of your app, e.g. MyBlurrrProj
 * @note Both the org and app strings may become part of a directory name, so please follow these rules:
 * Try to use the same org string (including case-sensitivity) for all your applications that use this function.
 * Always use a unique app string for each one, and make sure it never changes for an app once you've decided on it.
 * Unicode characters are legal, as long as it's UTF-8 encoded, only use letters, numbers, and spaces. 
 * The intention of this feature is to model how OS X, iOS, and Android create application identifiers.
 * So in the above example, the directory result would create com.blurrrsdk.MyBlurrrProj
 * @return Returns the string for the path to the executable directory. You must free this with BlurrrCore_Free when you are done.
 * This can return NULL (e.g. as SDL_GetBasePath() does for Android).
 */
BLURRRCORE_EXPORT char* BLURRRCORE_CALL BlurrrPath_CreateCacheDirectoryString(const char* organization_name, const char* app_name);


/**
 * Returns a string to where the temp directory is located. This will end with a trailing slash.
 * @param string_array The buffer the result will be written into. Maybe NULL if you just want the return length.
 * @param array_length The length of the string_array buffer.
 * @param organization_name Your reverse URI organization name, e.g. com.blurrrsdk
 * @param app_name The name of your app, e.g. MyBlurrrProj
 * @note Both the org and app strings may become part of a directory name, so please follow these rules:
 * Try to use the same org string (including case-sensitivity) for all your applications that use this function.
 * Always use a unique app string for each one, and make sure it never changes for an app once you've decided on it.
 * Unicode characters are legal, as long as it's UTF-8 encoded, only use letters, numbers, and spaces. 
 * The intention of this feature is to model how OS X, iOS, and Android create application identifiers.
 * So in the above example, the directory result would create com.blurrrsdk.MyBlurrrProj
 * @return Returns the length needed for the resulting string, including the +1 for the \0 terminator. This value will return 0 if the resulting string is/would-be NULL.
 * The passed in string will be null terminated if the value would be NULL.
 */
BLURRRCORE_EXPORT size_t BLURRRCORE_CALL BlurrrPath_GetTemporaryDirectoryString(char* string_array, size_t array_length, const char* organization_name, const char* app_name);
/**
 * Returns a string to where the temp directory is located. This will end with a trailing slash.
 * Must free with BlurrrCore_Free.
 * @param organization_name Your reverse URI organization name, e.g. com.blurrrsdk
 * @param app_name The name of your app, e.g. MyBlurrrProj
 * @note Both the org and app strings may become part of a directory name, so please follow these rules:
 * Try to use the same org string (including case-sensitivity) for all your applications that use this function.
 * Always use a unique app string for each one, and make sure it never changes for an app once you've decided on it.
 * Unicode characters are legal, as long as it's UTF-8 encoded, only use letters, numbers, and spaces. 
 * The intention of this feature is to model how OS X, iOS, and Android create application identifiers.
 * So in the above example, the directory result would create com.blurrrsdk.MyBlurrrProj
 * @return Returns the string for the path to the executable directory. You must free this with BlurrrCore_Free when you are done.
 * This can return NULL (e.g. as SDL_GetBasePath() does for Android).
 */
BLURRRCORE_EXPORT char* BLURRRCORE_CALL BlurrrPath_CreateTemporaryDirectoryString(const char* organization_name, const char* app_name);


/**
 * Returns a string to where the preference directory is located. This will end with a trailing slash.
 * @param string_array The buffer the result will be written into. Maybe NULL if you just want the return length.
 * @param array_length The length of the string_array buffer.
 * @param organization_name Your reverse URI organization name, e.g. com.blurrrsdk
 * @param app_name The name of your app, e.g. MyBlurrrProj
 * @note Both the org and app strings may become part of a directory name, so please follow these rules:
 * Try to use the same org string (including case-sensitivity) for all your applications that use this function.
 * Always use a unique app string for each one, and make sure it never changes for an app once you've decided on it.
 * Unicode characters are legal, as long as it's UTF-8 encoded, only use letters, numbers, and spaces. 
 * The intention of this feature is to model how OS X, iOS, and Android create application identifiers.
 * So in the above example, the directory result would create com.blurrrsdk.MyBlurrrProj
 * @note On most plaforms, this calls SDL_GetPrefPath(). But on Android, SDL_GetPrefPath() returns NULL, so creates a directory inside SDL_AndroidGetInternalStoragePath().
 * @return Returns the length needed for the resulting string, including the +1 for the \0 terminator. This value will return 0 if the resulting string is/would-be NULL.
 * The passed in string will be null terminated if the value would be NULL.
 */
BLURRRCORE_EXPORT size_t BLURRRCORE_CALL BlurrrPath_GetPreferenceDirectoryString(char* string_array, size_t array_length, const char* organization_name, const char* app_name);
/**
 * Returns a string to where the preference directory is located. This will end with a trailing slash.
 * Must free with BlurrrCore_Free.
 * @param organization_name Your reverse URI organization name, e.g. com.blurrrsdk
 * @param app_name The name of your app, e.g. MyBlurrrProj
 * @note Both the org and app strings may become part of a directory name, so please follow these rules:
 * Try to use the same org string (including case-sensitivity) for all your applications that use this function.
 * Always use a unique app string for each one, and make sure it never changes for an app once you've decided on it.
 * Unicode characters are legal, as long as it's UTF-8 encoded, only use letters, numbers, and spaces. 
 * The intention of this feature is to model how OS X, iOS, and Android create application identifiers.
 * So in the above example, the directory result would create com.blurrrsdk.MyBlurrrProj
 * @note On most plaforms, this calls SDL_GetPrefPath(). But on Android, SDL_GetPrefPath() returns NULL, so creates a directory inside SDL_AndroidGetInternalStoragePath().
 * @return Returns the string for the path to the preference directory. You must free this with BlurrrCore_Free when you are done.
 * This can return NULL (e.g. as SDL_GetBasePath() does for Android).
 */
BLURRRCORE_EXPORT char* BLURRRCORE_CALL BlurrrPath_CreatePreferenceDirectoryString(const char* organization_name, const char* app_name);


/**
 * Returns a string to where the documents directory is located. This will end with a trailing slash.
 * @param string_array The buffer the result will be written into. Maybe NULL if you just want the return length.
 * @param array_length The length of the string_array buffer.
 * @note On Linux, this will try $HOME/Documents and possibly a few other permutations, and then fallback to $HOME. If that is not available, it will return NULL.
 * On Android, it attempts to return Environment.getExternalStorageDirectory() + "/Documents/"
 * and will try to create the Documents directory if not available (for maximum compatbility).
 * (DIRECTORY_DOCUMENTS requires 4.4+). 
 * Additionally, Android must set the proper permissions:
 * android.permission.READ_EXTERNAL_STORAGE, android.permission.WRITE_EXTERNAL_STORAGE.
 * SDL_AndroidGetExternalStorageState() can get you the current permissions at runtime if you need check.
 * On OSX, beware of Mac Sandboxing (Powerbox). The only way to read/write to files outside the sandbox is through native file panels. Use NativeFileDialog which ships with BlurrrSDK.
 * @return Returns the string for the path to the documents directory. 
 * This can return NULL.
 */
BLURRRCORE_EXPORT size_t BLURRRCORE_CALL BlurrrPath_GetDocumentDirectoryString(char* string_array, size_t array_length);

/**
 * Returns a string to where the documents directory is located. This will end with a trailing slash.
 * Must free with BlurrrCore_Free.
 * @note On Linux, this will try $HOME/Documents and possibly a few other permutations, and then fallback to $HOME. If that is not available, it will return NULL.
 * On Android, it attempts to return Environment.getExternalStorageDirectory() + "/Documents/"
 * and will try to create the Documents directory if not available (for maximum compatbility).
 * (DIRECTORY_DOCUMENTS requires 4.4+). 
 * Additionally, Android must set the proper permissions:
 * android.permission.READ_EXTERNAL_STORAGE, android.permission.WRITE_EXTERNAL_STORAGE.
 * SDL_AndroidGetExternalStorageState() can get you the current permissions at runtime if you need check.
 * On OSX, beware of Mac Sandboxing. The only way to read/write to files outside the sandbox is through native file panels. Use NativeFileDialog which ships with BlurrrSDK.
 * @return Returns the string for the path to the documents directory. You must free this with BlurrrCore_Free when you are done.
 * This can return NULL.
 */
BLURRRCORE_EXPORT char* BLURRRCORE_CALL BlurrrPath_CreateDocumentDirectoryString(void);





/**
 * Returns a canonicalized absolute pathname.
 * @param string_array The buffer the result will be written into. Maybe NULL if you just want the return length.
 * @param array_length The length of the string_array buffer.
 * @param path_name The path to convert.
 * @note Uses realpath on Unix, GetFullPathNameA on Windows. For cross-platform purposes, there is no trailing slash included.
 * @return Returns the length needed for the resulting string, including the +1 for the \0 terminator. This value will return 0 if the resulting string is/would-be NULL.
 * The passed in string will be null terminated if the value would be NULL.
 */
BLURRRCORE_EXPORT size_t BLURRRCORE_CALL BlurrrPath_GetRealPathString(char* string_array, size_t array_length, const char* path_name);

/**
 * Returns a canonicalized absolute pathname.
 * Must free with BlurrrCore_Free.
 * @param path_name The path to convert.
 * @note Uses realpath on Unix, GetFullPathNameA on Windows. For cross-platform purposes, there is no trailing slash included.
 * @return Returns the length needed for the resulting string, including the +1 for the \0 terminator. This value will return 0 if the resulting string is/would-be NULL.
 * The passed in string will be null terminated if the value would be NULL.
 * This can return NULL on error.
 */
BLURRRCORE_EXPORT char* BLURRRCORE_CALL BlurrrPath_CreateRealPathString(const char* path_name);


/**
 * Gets the current working directory.
 * @param string_array The buffer the result will be written into. Maybe NULL if you just want the return length.
 * @param array_length The length of the string_array buffer.
 * @return Returns the length needed for the resulting string, including the +1 for the \0 terminator. This value will return 0 if the resulting string is/would-be NULL.
 * The passed in string will be null terminated if the value would be NULL.
 */
BLURRRCORE_EXPORT size_t BLURRRCORE_CALL BlurrrPath_GetCurrentDirectoryString(char* string_array, size_t array_length);

/**
 * Gets the current working directory.
 * Must free with BlurrrCore_Free.
 * @return Returns the length needed for the resulting string, including the +1 for the \0 terminator. This value will return 0 if the resulting string is/would-be NULL.
 * The passed in string will be null terminated if the value would be NULL.
 * This can return NULL on error.
 */
BLURRRCORE_EXPORT char* BLURRRCORE_CALL BlurrrPath_CreateCurrentDirectoryString(void);


/**
 * Gets the platform's general Preference directory. This is not your app's preference directory, and you should @see BlurrrPath_GetPreferenceDirectoryString for that.
 * @param string_array The buffer the result will be written into. Maybe NULL if you just want the return length.
 * @param array_length The length of the string_array buffer.
 * @return Returns the length needed for the resulting string, including the +1 for the \0 terminator. This value will return 0 if the resulting string is/would-be NULL.
 * The passed in string will be null terminated if the value would be NULL.
 * @note This will generally not work or be useful in sandboxed environments. So for example, this API should not be used on iOS, Android, or Mac App Store type apps. This is mostly useful for non-sandboxed tools, such as BlurrrGenProj.
 * Apple: NSLibraryDirectory/Preferences -> e.g. /Users/steve/Library/Preferences/
 * Linux: $XDG_HOME, $HOME, or getpwuid_r -> /Users/linus/
 * Windows: SHGetFolderPath with CSIDL_APPDATA -> C:\Users\bill\AppData\Roaming\
*/
BLURRRCORE_EXPORT size_t BLURRRCORE_CALL BlurrrPath_GetPlatformPreferenceDirectoryString(char* string_array, size_t array_length);

/**
 * Gets the platform's general Preference directory. This is not your app's preference directory, and you should @see BlurrrPath_GetPreferenceDirectoryString for that.
 * Must free with BlurrrCore_Free.
 * @return Returns the length needed for the resulting string, including the +1 for the \0 terminator. This value will return 0 if the resulting string is/would-be NULL.
 * The passed in string will be null terminated if the value would be NULL.
 * This can return NULL on error.
 * Apple: NSLibraryDirectory/Preferences -> e.g. /Users/steve/Library/Preferences/
 * Linux: $XDG_HOME, $HOME, or getpwuid_r -> /Users/linus/
 * Windows: SHGetFolderPath with CSIDL_APPDATA -> C:\Users\bill\AppData\Roaming\
  * @note This will generally not work or be useful in sandboxed environments. So for example, this API should not be used on iOS, Android, or Mac App Store type apps. This is mostly useful for non-sandboxed tools, such as BlurrrGenProj.
 */
BLURRRCORE_EXPORT char* BLURRRCORE_CALL BlurrrPath_CreatePlatformPreferenceDirectoryString(void);

/**
 * Gets the home directory of the current user. In most cases, you should not use this and instead @see BlurrrPath_GetPreferenceDirectoryString.
 * @param string_array The buffer the result will be written into. Maybe NULL if you just want the return length.
 * @param array_length The length of the string_array buffer.
 * @return Returns the length needed for the resulting string, including the +1 for the \0 terminator. This value will return 0 if the resulting string is/would-be NULL.
 * The passed in string will be null terminated if the value would be NULL.
 * Apple: Uses NSHomeDirectory() -> e.g. /Users/steve/
 * Linux: $XDG_HOME, $HOME, or getpwuid_r -> /Users/linus/
 * Windows: SHGetFolderPath with CSIDL_PROFILE -> C:\Users\bill\
 * @note This will generally not work or be useful in sandboxed environments. So for example, this API should not be used on iOS, Android, or Mac App Store type apps. This is mostly useful for non-sandboxed tools, such as BlurrrGenProj.
 */
BLURRRCORE_EXPORT size_t BLURRRCORE_CALL BlurrrPath_GetHomeDirectoryString(char* string_array, size_t array_length);

/**
 * Gets the home directory of the current user. In most cases, you should not use this and instead @see BlurrrPath_GetPreferenceDirectoryString.
 * Must free with BlurrrCore_Free.
 * @return Returns the length needed for the resulting string, including the +1 for the \0 terminator. This value will return 0 if the resulting string is/would-be NULL.
 * The passed in string will be null terminated if the value would be NULL.
 * This can return NULL on error.
 * Apple: NSHomeDirectory() -> e.g. /Users/steve/
 * Linux: $HOME, or getpwuid_r -> /Users/linus/
 * Windows: SHGetFolderPath with CSIDL_PROFILE -> C:\Users\bill\
 * @note This will generally not work or be useful in sandboxed environments. So for example, this API should not be used on iOS, Android, or Mac App Store type apps. This is mostly useful for non-sandboxed tools, such as BlurrrGenProj.
 */
BLURRRCORE_EXPORT char* BLURRRCORE_CALL BlurrrPath_CreateHomeDirectoryString(void);







#ifdef __cplusplus
}
#endif

#endif /* BLURRRCORE_H */
