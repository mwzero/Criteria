#ifndef _BOS_WIN32_H_
#define _BOS_WIN32_H_

//TO_BE_EXPORTED
#define _BOS_ON_WIN32_

#ifdef _BOS_STATIC_LIBRARY
	#define BOS_API
#else
	#ifdef BOS_EXPORTS
		#define BOS_API __declspec(dllexport)
	#else
		#define BOS_API __declspec(dllimport)
	#endif
#endif

#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif

#ifndef IT_USE_STD_IOSTREAM
#define IT_USE_STD_IOSTREAM
#endif

//include std window headers
#include <process.h>
#include <windows.h>
#include <commctrl.h>
#include <shlobj.h>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <list>
#include <map>
#include <fstream>
#include <iostream>
#include <strstream>
#include <assert.h>
#include <time.h>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <sys/timeb.h>
#include <algorithm>
#include <typeinfo>

//SOCKET
#include <winsock2.h>
typedef SOCKET socket_type;
typedef int socklen_t;

#include <string>
#include <streambuf>
#include <ostream>
#include <stdexcept>
#include <sstream>

using namespace std;


#define SLASH "\\"
#define NEWLINE	"\n"

typedef HANDLE	MUTEX;
typedef HANDLE	BOS_THREAD;
typedef HANDLE	PROCESS;
typedef HANDLE  SEMAPHORE;
//
typedef size_t	SIZE_INT;

#endif //_BOS_WIN32_H_
