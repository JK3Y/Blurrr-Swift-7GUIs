
#ifndef BLURRRCORE_RANDOM_H
#define BLURRRCORE_RANDOM_H

#ifndef BLURRRCORE_EXPORTS_H
#include "BlurrrCore_Exports.h"
#endif



#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

/**
Initializes the psuedo-random number generator with a seed.
*/
BLURRRCORE_EXPORT void BlurrrRandom_Seed(uint32_t seed);
	
/**
Generates a unsigned integer random number on [0,0xffffffff]-interval.
*/
BLURRRCORE_EXPORT uint32_t BLURRRCORE_CALL BlurrrRandom_GetUint32(void);
/**
Generates a random floating number on [0,1]-interval.
*/
BLURRRCORE_EXPORT double BLURRRCORE_CALL BlurrrRandom_GetDouble(void);
/**
Generates a random floating number on [0,1]-interval.
*/
BLURRRCORE_EXPORT float BLURRRCORE_CALL BlurrrRandom_GetFloat(void);

/**
Generates a unsigned integer random number on [min,max]-interval.
*/
BLURRRCORE_EXPORT uint32_t BLURRRCORE_CALL BlurrrRandom_GetUint32InRange(uint32_t min, uint32_t max);
/**
Generates an integer random number on [min,max]-interval.
*/
BLURRRCORE_EXPORT int32_t BLURRRCORE_CALL BlurrrRandom_GetSint32InRange(int32_t min, int32_t max);
/**
Generates a floating random number on [min,max]-interval.
*/
BLURRRCORE_EXPORT double BLURRRCORE_CALL BlurrrRandom_GetDoubleInRange(double min, double max);
/**
Generates a floating random number on [min,max]-interval.
*/
BLURRRCORE_EXPORT float BLURRRCORE_CALL BlurrrRandom_GetFloatInRange(float min, float max);


#ifdef __cplusplus
}
#endif


#endif /* BLURRRCORE_RANDOM_H */

