#ifndef BLURRRCORE_TIMETICKER_H
#define BLURRRCORE_TIMETICKER_H

/**
	This is an abstraction around SDL_GetTicks() and works like a stop watch. 
	Unlike SDL_GetTicks(), this can count independently of the system clock, 
	which is useful for things like pausing the game.
	This also has a time scale factor which can allow for things like "bullet time".
	This also allows multiple, independent instances.
*/

#ifndef BLURRRCORE_EXPORTS_H
#include "BlurrrCore_Exports.h"
#endif


/* Set up for C function definitions, even when using C++ */
#ifdef __cplusplus
extern "C" {
#endif
	
/* Optional API symbol name rewrite to help avoid duplicate symbol conflicts.
	For example:   -DBLURRRCORE_TIME_TICKER_NAMESPACE_PREFIX=ALmixer
*/
	
#if defined(BLURRRCORE_TIME_TICKER_NAMESPACE_PREFIX)
	#define BLURRRCORE_TIME_TICKER_RENAME_PUBLIC_SYMBOL_WITH_NAMESPACE(namespace, symbol) namespace##symbol
	#define BLURRRCORE_TIME_TICKER_RENAME_PUBLIC_SYMBOL(symbol) BLURRRCORE_TIME_TICKER_RENAME_PUBLIC_SYMBOL_WITH_NAMESPACE(BLURRRCORE_TIME_TICKER_NAMESPACE_PREFIX, symbol)
	
	#define BlurrrTicker_Create			BLURRRCORE_TIME_TICKER_RENAME_PUBLIC_SYMBOL(BlurrrTicker_Create)
	#define BlurrrTicker_Free			BLURRRCORE_TIME_TICKER_RENAME_PUBLIC_SYMBOL(BlurrrTicker_Free)
	#define BlurrrTicker_Start			BLURRRCORE_TIME_TICKER_RENAME_PUBLIC_SYMBOL(BlurrrTicker_Start)
	#define BlurrrTicker_Stop			BLURRRCORE_TIME_TICKER_RENAME_PUBLIC_SYMBOL(BlurrrTicker_Stop)
	#define BlurrrTicker_Reset			BLURRRCORE_TIME_TICKER_RENAME_PUBLIC_SYMBOL(BlurrrTicker_Reset)
	#define BlurrrTicker_GetTime		BLURRRCORE_TIME_TICKER_RENAME_PUBLIC_SYMBOL(BlurrrTicker_GetTime)
	#define BlurrrTicker_UpdateTime		BLURRRCORE_TIME_TICKER_RENAME_PUBLIC_SYMBOL(BlurrrTicker_UpdateTime)
	#define BlurrrTicker_SetSpeed		BLURRRCORE_TIME_TICKER_RENAME_PUBLIC_SYMBOL(BlurrrTicker_SetSpeed)
	#define BlurrrTicker_GetSpeed		BLURRRCORE_TIME_TICKER_RENAME_PUBLIC_SYMBOL(BlurrrTicker_GetSpeed)

#endif /* defined(BLURRRCORE_TIME_TICKER_NAMESPACE_PREFIX) */

#include <stdint.h>
#include <stdbool.h>
	
struct BlurrrTicker;
typedef struct BlurrrTicker BlurrrTicker;

/**
Creates a new instance of a BlurrrTicker object.
@see BlurrrTicker_Free
*/
extern BLURRRCORE_EXPORT struct BlurrrTicker* BLURRRCORE_CALL BlurrrTicker_Create(void);

/**
Frees the instance of a BlurrrTicker object.
@see BlurrrTicker_Create
*/
extern BLURRRCORE_EXPORT void BLURRRCORE_CALL BlurrrTicker_Free(struct BlurrrTicker* time_ticker);

/**
Starts/resumes the clock.
*/
extern BLURRRCORE_EXPORT void BLURRRCORE_CALL BlurrrTicker_Start(struct BlurrrTicker* time_ticker);

/**
Stops the clock.
Call BlurrrTicker_Start to resume the clock.
@see BlurrrTicker_Start
*/
extern BLURRRCORE_EXPORT void BLURRRCORE_CALL BlurrrTicker_Stop(struct BlurrrTicker* time_ticker);

/**
Stops the clock and sets the clock time to zero.
@see BlurrrTicker_Start
*/
extern BLURRRCORE_EXPORT void BLURRRCORE_CALL BlurrrTicker_Reset(struct BlurrrTicker* time_ticker);

/**
Gets the clock's current time in milliseconds.
@note This value will not update until you call BlurrrTicker_UpdateTime.
@see BlurrrTicker_UpdateTime
*/
extern BLURRRCORE_EXPORT uint32_t BLURRRCORE_CALL BlurrrTicker_GetTime(struct BlurrrTicker* time_ticker);

/**
Updates the clock.
You are expected to call this function every frame, or whenever you need the most up-to-date time.
The typical use case is you call this at the beginning of the frame. 
Then you use the returned value (or BlurrrTicker_GetTime which is the same value)
for the rest of the frame. The idea is that all your game objects are sync'd
to this moment in time, whereas if you had repeatedly called this function
(or SDL_GetTicks), time would keep incrementing and you get snapshots of 
all the objects you want to evaluate for the same frame at slightly different
milliseconds in time (which is generally what you do not want).
Use BlurrrTicker_GetTime() to get the time without updating it.
@return Returns the new current time as a convenience.
@see BlurrrTicker_GetTime
*/
extern BLURRRCORE_EXPORT uint32_t BLURRRCORE_CALL BlurrrTicker_UpdateTime(struct BlurrrTicker* time_ticker);
/**
Sets a time scale factor to affect how fast the ticker increments.
The default speed is 1.0.
Setting to 0.5 halves the speed. Setting to 2.0 doubles the speed.
*/
extern BLURRRCORE_EXPORT void BLURRRCORE_CALL BlurrrTicker_SetSpeed(struct BlurrrTicker* time_ticker, double new_speed);
/**
Gets the current time scale factor.
@see BlurrrTicker_SetSpeed
*/
extern BLURRRCORE_EXPORT double BLURRRCORE_CALL BlurrrTicker_GetSpeed(struct BlurrrTicker* time_ticker);

#ifdef __cplusplus
}
#endif


/**
Experimental: Sets the current time.
This is very dangerous and may break things and may be removed.
However, it can be useful for debugging tricks.
*/
extern BLURRRCORE_EXPORT void BLURRRCORE_CALL BlurrrTicker_SetTime(struct BlurrrTicker* time_ticker, uint32_t new_time);

/**
Experimental: Allows for incrementing time a fixed amount on every BlurrrTicker_UpdateTime call.
This will set how much to increment on every call.
Default is 16, as in 16 ms per frame.
*/
extern BLURRRCORE_EXPORT void BLURRRCORE_CALL BlurrrTicker_SetFixedStepSize(struct BlurrrTicker* time_ticker, uint32_t step_increment);
extern BLURRRCORE_EXPORT uint32_t BLURRRCORE_CALL BlurrrTicker_GetFixedStepSize(struct BlurrrTicker* time_ticker);

/**
Experimental: Allows for incrementing time a fixed amount on every BlurrrTicker_UpdateTime call.
Setting to true will enable this mode. Default is false.
*/
extern BLURRRCORE_EXPORT void BLURRRCORE_CALL BlurrrTicker_EnableFixedStepMode(struct BlurrrTicker* time_ticker, bool is_enabled);

/**
Experimental: Allows for incrementing time a fixed amount on every BlurrrTicker_UpdateTime call.
Default is false.
 */
extern BLURRRCORE_EXPORT bool BLURRRCORE_CALL BlurrrTicker_IsFixedStepModeEnabled(struct BlurrrTicker* time_ticker);


#endif /* BLURRRCORE_TIMETICKER_H */
