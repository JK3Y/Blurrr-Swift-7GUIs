
#ifndef BLURRRCORE_EXPORTS_H
#define BLURRRCORE_EXPORTS_H

#ifdef __cplusplus
extern "C" {
#endif


#ifndef DOXYGEN_SHOULD_IGNORE_THIS
        /** @cond DOXYGEN_SHOULD_IGNORE_THIS */
        
        /* Note: For Doxygen to produce clean output, you should set the 
         * PREDEFINED option to remove DECLSPEC, CALLCONVENTION, and
         * the DOXYGEN_SHOULD_IGNORE_THIS blocks.
         * PREDEFINED = DOXYGEN_SHOULD_IGNORE_THIS=1 DECLSPEC= CALLCONVENTION=
         */
        
        /** Windows needs to know explicitly which functions to export in a DLL. */
	
#ifdef BUILD_BLURRRCORE_AS_DLL
        #ifdef WIN32
                #define BLURRRCORE_EXPORT __declspec(dllexport)
        #elif defined(__GNUC__) && __GNUC__ >= 4
                #define BLURRRCORE_EXPORT __attribute__ ((visibility("default")))
        #else
                #define BLURRRCORE_EXPORT
        #endif
#else
        #define BLURRRCORE_EXPORT
#endif /* BUILD_BLURRRCORE_AS_DLL */

/* For Windows, by default, use the C calling convention */
#if defined(_WIN32)
	#define BLURRRCORE_CALL __cdecl
#else
	#define BLURRRCORE_CALL
#endif


/** @endcond DOXYGEN_SHOULD_IGNORE_THIS */
#endif /* DOXYGEN_SHOULD_IGNORE_THIS */


#ifdef __cplusplus
}
#endif

#endif /* BLURRRCORE_EXPORTS_H */
