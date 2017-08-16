
#ifndef __BOS_FILESYSTEM_H__
#define __BOS_FILESYSTEM_H__

//TO_BE_EXPORTED
#include "bOS.h"
#include "bOSStringBuffer.h"

namespace bOS
{
    namespace IO
    {
		typedef BOS_API std::vector<std::string> FilesList;

		enum FileAttribute
        {
            Exists      = 0x01,
	        RegularFile = 0x02,
	        Directory   = 0x04,
	        Hidden      = 0x08,
			ReadOnly    = 0x10
        };

        class BOS_API FileSystem
        {
            public:

                FileSystem();

                virtual ~FileSystem();

				static void ls(const std::string& sDir, FilesList& files, const char* acExtension);

				//deprecated
				static std::string getStringFile(const std::string& sFile);

				static void getStringFileBinary(const char* acFile, bOS::CoreString::StringBuffer& );

				static void getStringFile(const char* acFile, bOS::CoreString::StringBuffer&);

				static void saveStringFile(const char* acFile, std::string&);

				static std::string getFileName(const std::string& sPath, bool bRemoveExtention=false);

				static int getFileAttributeFlags( const std::string& sFile );

				static bool existFile(const std::string& sFile);

				static void deleteFile(const std::string& sFile);

            protected:

            private:

        };
    }
};

#endif //__BOS_FILESYSTEM_H__


