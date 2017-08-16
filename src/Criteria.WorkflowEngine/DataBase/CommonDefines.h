#ifndef _DATABASE_COMMON_DEFINES_H
#define _DATABASE_COMMON_DEFINES_H

//TO_BE_EXPORTED

//#pragma warning (disable: 4251)
//#pragma warning (disable: 4786)

#include "bOS/bOS.h"
#include "bOS/bOSStringUtils.h"
#include "bOS/bOSStringBuffer.h"
using namespace bOS::CoreString;

#ifdef DATABASE_EXPORTS
	#define DATABASE_API __declspec(dllexport)
#else
	#define DATABASE_API __declspec(dllimport)
#endif

#include "bOS/Tracer.h"

#endif //_DATABASE_COMMON_DEFINES_H

