#include "CommonDefines.h"

#include "bOS.h"

#include "bOSSystem.h"
using namespace bOS::CoreSystem;

#include "bOSFile.h"
using namespace bOS::IO;

#include "bOSFileSystemException.h"
using namespace bOS::Exception;

File::File(const char* acFileName)
{
	sFileName = acFileName;
}

File::~File()
{
}

