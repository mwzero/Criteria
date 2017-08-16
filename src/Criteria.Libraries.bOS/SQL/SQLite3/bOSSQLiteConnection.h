#ifndef __BOS_SQLITE3_CONNECTION_H__
#define __BOS_SQLITE3_CONNECTION_H__

//TO_BE_EXPORTED
#include "bOS.h"

#include "bOSSQLConnection.h"

#include "bOSSQLiteConnectionData.h"

#include "CppSQLite3.h"

namespace bOS
{
    namespace SQL
    {
		namespace SQLite3
		{
			class BOS_API SQLiteConnection : public bOS::SQL::SQLConnection
			{
				public:

                    SQLiteConnection(SQLiteConnectionData* data);
					~SQLiteConnection();

					bool isConnected();
					long execute( const char* acSql );
					long executePrepare( SQLCommands& ) {return 0;}
					ResultSet* executeQuery( const char* acSql );
					ResultSet* executeQuery(const char* acSql,int iCursorType,bool bScrollable);

					unsigned long getAutoIncrement() { return 0;}

					//Transaction Manager
					void beginTrans();
					void commit();
					void rollback();
					bool supportTransaction();

				protected:

				private:



					void open();
					void close();

					/**************************************/
					bool bConnected;
					std::string	sDB;
					/**************************************/


					CppSQLite3DB sqlliteDB;
					/************************************/

					friend class SQLConnectionManager;
			};
		}
    }
};

#endif //__BOS_SQLITE3_CONNECTION_H__
