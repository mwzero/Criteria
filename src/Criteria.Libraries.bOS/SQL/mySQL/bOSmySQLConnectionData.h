#ifndef __BOS_SQL_MYSQL_CONNECTION_DATA_H__
#define __BOS_SQL_MYSQL_CONNECTION_DATA_H__

//TO_BE_EXPORTED

#include "bOS.h"

#include "bOSSQLConnectionData.h"

namespace bOS
{
	namespace SQL
	{
		namespace mySQL
		{
			class BOS_API mySQLConnectionData : public bOS::SQL::SQLConnectionData
			{
			public:

				mySQLConnectionData();
				~mySQLConnectionData();

				void init(SQLConnectionData*);

				std::string sHost;
				unsigned int iPort;
				std::string sDB;
				std::string sUser;
				std::string sPassword;
			};
		}
	}
}


#endif //__BOS_SQL_MYSQL_CONNECTION_DATA_H__
