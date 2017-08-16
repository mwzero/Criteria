#ifndef __BOS_SQL_SQLITE3_CONNECTION_DATA_H__
#define __BOS_SQL_SQLITE3_CONNECTION_DATA_H__

//TO_BE_EXPORTED

#include "bOS.h"

#include "bOSSQLConnectionData.h"

namespace bOS
{
	namespace SQL
	{
		namespace SQLite3
		{
			class BOS_API SQLiteConnectionData : public bOS::SQL::SQLConnectionData
			{
			public:

				SQLiteConnectionData();
				~SQLiteConnectionData();

				void init(SQLConnectionData*);

				std::string sDB;
				std::string sPath;
			};
		}
	}
}


#endif //__BOS_SQL_SQLITE3_CONNECTION_DATA_H__
