#ifndef BLURRRCORE_LOG_H
#define BLURRRCORE_LOG_H

#ifndef BLURRRCORE_EXPORTS_H
#include "BlurrrCore_Exports.h"
#endif

#ifdef __cplusplus
extern "C" {
#endif

#include <stdarg.h>

/**
 * Log API
 */

/**
 * Writes message to system log.
 * Writes message to system log. Use your platform's native log viewer to see the messages.
 * Mac OS X: Console.app
 * iOS: Xcode
 * Android: adb logcat
 * Linux: /var/log/syslog (GUI frontends exist, e.g. Ubuntu File Log Viewer)
 * Windows: Event Viewer management console in Administrative Tools
 *
 * Additionally: Most output will be visible while debugging.
 * Xcode: Output will appear in the Xcode console.
 * Android: Android Studio shows output in the Android Monitor tab.
 * Linux: Also echos output to stderr.
 * Windows: OutputDebugString is used so it can be seen in the Visual Studio output console.
 */
BLURRRCORE_EXPORT void BLURRRCORE_CALL BlurrrLog_SysLogv(const char* fmt, va_list argp);

/**
 * Writes message to system log.
 * Writes message to system log. Use your platform's native log viewer to see the messages.
 * Mac OS X: Console.app
 * iOS: Xcode
 * Android: adb logcat
 * Linux: /var/log/syslog (GUI frontends exist, e.g. Ubuntu File Log Viewer)
 * Windows: Event Viewer management console in Administrative Tools
 *
 * Additionally: Most output will be visible while debugging.
 * Xcode: Output will appear in the Xcode console.
 * Android: Android Studio shows output in the Android Monitor tab.
 * Linux: Also echos output to stderr.
 * Windows: OutputDebugString is used so it can be seen in the Visual Studio output console.
 */
BLURRRCORE_EXPORT void BLURRRCORE_CALL BlurrrLog_SysLog(const char* fmt, ...);



#ifdef __cplusplus
}
#endif

#endif /* BLURRRCORE_LOG_H */
