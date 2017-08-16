#include "CommonDefines.h"

#include "bOS.h"

#include "bOSStringBuffer.h"
using namespace bOS::CoreString;

#include "bOSSystem.h"
using namespace bOS::CoreSystem;

#include "bOSFileSystem.h"
using namespace bOS::IO;

#include "bOSFileSystemException.h"
using namespace bOS::Exception;

using namespace std;

FileSystem::FileSystem()
{
}

FileSystem::~FileSystem()
{
}

void FileSystem::ls(const std::string& sDir, FilesList& files, const char* acExtension)
{
#ifdef _BOS_ON_WIN32_

	WIN32_FIND_DATA FindFileData;
	HANDLE hFind;

	char* sourceDir = new char[sDir.size()+4];
	strcpy(sourceDir,sDir.c_str());
	strcat(sourceDir,"\\*");

	hFind=FindFirstFile((LPCTSTR)sourceDir,&FindFileData);
	if (hFind == INVALID_HANDLE_VALUE)
	{
		throw FileSystemException();
	}


	while ( FindNextFile(hFind, &FindFileData) )
	{
		if ( (!strcmp(FindFileData.cFileName,".")) || (!strcmp(FindFileData.cFileName, "..")) )
			continue;


		if ( (acExtension != NULL) )
		{

			std::string sFile=FindFileData.cFileName;

			int iPos = sFile.find_last_of(".");
			if (( iPos == string::npos) || (strcmp(acExtension, sFile.substr(iPos).c_str()) ) )
				continue;
		}



		files.push_back(FindFileData.cFileName);
	}

	if (GetLastError() != ERROR_NO_MORE_FILES)
	{
		FindClose(hFind);
		throw FileSystemException(READ_ERROR);
	}

	FindClose(hFind);

	#else // _BOS_ON_SOLARIS_ _BOS_ON_HP_
    #endif
}

std::string FileSystem::getStringFile(const std::string& sFile)
{
	std::string sReturn;
	ifstream _file;
	_file.open( sFile.c_str() );
	if ( _file.fail() )
	{
		_file.clear();
		throw FileSystemException(PATH_NOTFOUND);

	}
	std::string sRecord;
	try
	{
        while ( getline(_file, sRecord) )
		{
			if ( _file.fail() )
				throw FileSystemException(READ_ERROR);

			if ( !sRecord.empty()  )
            {
				sReturn += sRecord;
            }
		}

		if ( _file.rdbuf()->is_open() )
			_file.close();
	}
	catch ( exception e)
	{
		throw FileSystemException(e.what());
	}

	return sReturn;
}

void FileSystem::getStringFileBinary(const char* acFile , bOS::CoreString::StringBuffer& sBuf)
{
	std::string sReturn;

	FILE *stream;

   if( (stream  = fopen( acFile, "rb" )) == NULL )
   {
		throw FileSystemException(PATH_NOTFOUND);
   }

   int numread;
   char acRecord[1000];

   try
   {
	while (( numread = fread( acRecord, sizeof( char ), 1000, stream )) ==  1000 )
	{
		sBuf.append (acRecord, 1000);
	}

	if ( numread > 0 )
	{
		sBuf.append (acRecord, numread);
	}
   }
	catch ( exception e)
	{
		throw FileSystemException(e.what());
	}

   fclose( stream );
}

void FileSystem::saveStringFile(const char* acFile, std::string& sValue)
{
	ofstream strmFile (acFile);
	if ( strmFile.is_open() )
	{
		try
		{
			strmFile << sValue;
			strmFile.close();
		}
		catch ( exception e)
		{
			throw FileSystemException(e.what());
		}
	}
	else
	{
		throw FileSystemException(PATH_NOTFOUND);
	}
}

void FileSystem::getStringFile(const char* acFile, bOS::CoreString::StringBuffer& sFileBody)
{
	ifstream _file;
	_file.open( acFile );
	if ( _file.fail() )
	{
		_file.clear();
		throw FileSystemException(PATH_NOTFOUND);
	}

	std::string sRecord;
	try
	{
        while ( getline(_file, sRecord) )
		{
			if ( _file.fail() )
				throw FileSystemException(READ_ERROR);

			if ( !sRecord.empty()  )
            {
				sFileBody.append (sRecord);
            }
		}

		//Close file
		if ( _file.rdbuf()->is_open() )
			_file.close();
	}
	catch ( exception e)
	{
		throw FileSystemException(e.what());
	}
}

std::string FileSystem::getFileName(const std::string& sPath, bool bRemoveExtention)
{
	std::string sFileName=sPath;
	int i=0;

    while ( ( i = sFileName.find_first_of(SLASH) ) != string::npos)
    {
        sFileName = sFileName.substr( i + 1 );
    }

	if ( bRemoveExtention && (( i = sFileName.find_last_of(".") ) != string::npos) )
    {
        sFileName = sFileName.substr( 0, i );
    }

	return sFileName;
}

int FileSystem::getFileAttributeFlags( const std::string& sFile )
{
	int ret = 0;

#ifdef _BOS_ON_WIN32_

	DWORD dwAttrs = GetFileAttributes( sFile.c_str() );
	if ( dwAttrs != (DWORD)-1 )
	{
		ret = FileAttribute(Exists);

		if (dwAttrs & FILE_ATTRIBUTE_DIRECTORY)
			ret |= FileAttribute(Directory);
		else
			ret |= FileAttribute(RegularFile);

		if (dwAttrs & FILE_ATTRIBUTE_HIDDEN)
            ret |= FileAttribute(Hidden);

		if (dwAttrs & FILE_ATTRIBUTE_READONLY)
            ret |= FileAttribute(ReadOnly);
	}

#else
	struct stat myStat;
	if ( stat( sFile.c_str(), &myStat ) == 0)
	{
		int ret = FileAttribute(Exists);
		if ( myStat.st_mode & S_IFDIR )
            ret |= FileAttribute(Directory);

		if ( myStat.st_mode & S_IFREG )
            ret |= FileAttribute(RegularFile);

		if ( (myStat.st_mode & S_IWUSR) == 0)
            ret |= FileAttribute(ReadOnly);

	}
#endif

	return ret;
}

bool FileSystem::existFile(const std::string& sFile)
{
	return FileSystem::getFileAttributeFlags(sFile) & FileAttribute(Exists);
}

void FileSystem::deleteFile(const std::string& sFile)
{
	bool bError = true;

#ifdef _BOS_ON_WIN32_
	BOOL bSuccess;
	if ( FileSystem::getFileAttributeFlags(sFile) & Directory )
		bSuccess = RemoveDirectory( sFile.c_str() );
	else
		bSuccess = DeleteFile( sFile.c_str() );

	if ( bSuccess )
		bError = false;

	if ( bError )
	{
		std::string sMsgErr = System::getErrorString(GetLastError());
		throw FileSystemException(sMsgErr);
	}
#else
    //int result = remove( path.c_str() );
    int result = remove( sFile.c_str() );
	if ( result == 0 )
		bError = false;


    if ( bError )
	{
		throw FileSystemException(strerror(errno));
	}

#endif


}
