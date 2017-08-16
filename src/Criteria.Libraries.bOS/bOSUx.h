#ifndef _BOS_UX_H_
#define _BOS_UX_H_

//TO_BE_EXPORTED
#define _BOS_ON_UX_
#define _BOS_ON_HP_

#define BOS_API

#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif

#ifndef IT_USE_STD_IOSTREAM
#define IT_USE_STD_IOSTREAM
#endif

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#include <fcntl.h>           /* For O_* constants */
#include <sys/stat.h>        /* For mode constants */
#include <semaphore.h>
#include <dlfcn.h>           /* For dlopen  RTLD_NOW | RTLD_GLOBAL */

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
#include <errno.h>
#include <sys/timeb.h>
#include <algorithm>
#include <typeinfo>
#include <sys/wait.h>
#include <sys/time.h>

typedef int socket_type;
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <arpa/inet.h>

#include <cstring>
#include <cstdarg>

#include <streambuf>
#include <ostream>
#include <stdexcept>
#include <sstream>

using namespace std;

#define SLASH "/"			//linux
#define NEWLINE	"\r"		//linux

typedef void *HANDLE;

typedef HANDLE	MUTEX;
typedef HANDLE	BOS_THREAD;
typedef HANDLE	PROCESS;
typedef HANDLE  SEMAPHORE;
typedef int64_t longlong;

//
typedef size_t	SIZE_INT;

typedef unsigned long        SOCKET;

#define INVALID_SOCKET  (SOCKET)(~0)
#define SOCKET_ERROR            (-1)

#endif //_BOS_UX_H_
