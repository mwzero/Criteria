#ifndef _ENGINE_COMMON_DEFINES_H_
#define _ENGINE_COMMON_DEFINES_H_

// TO_BE_EXPORTED

#ifdef _CRITERIA_STATIC_LIBRARY
	#define ENGINE_API
#else
#ifdef ENGINE_EXPORTS
	#define ENGINE_API __declspec(dllexport)
#else
	#define ENGINE_API __declspec(dllimport)
#endif
#endif

#ifdef WIN32
    #include "string.h"
#else
    #include <string>
#endif

typedef std::string String;

typedef struct
{
	int iCode;
	char* sMsg;
} Response;

#endif //_ENGINE_COMMON_DEFINES_H_

