#ifndef __BOS_MYSQL_CONNECTION_H__
#define __BOS_MYSQL_CONNECTION_H__

//TO_BE_EXPORTED
#include "bOS.h"

#include "bOSSQLConnection.h"

#include "bOSmySQLConnectionData.h"

#include <windows.h>
#include "mysql/mysql.h"

namespace bOS
{
    namespace SQL
    {
		namespace mySQL
		{
			class BOS_API mySQLConnection : public bOS::SQL::SQLConnection
			{
				public:

                    mySQLConnection(mySQLConnectionData* data);
					~mySQLConnection();

					bool isConnected();
					long execute( const char* acSql );
					long executePrepare( SQLCommands& );
					ResultSet* executeQuery( const char* acSql );
					ResultSet* executeQuery(const char* acSql,int iCursorType,bool bScrollable);

					long getAutoIncrement();

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
					std::string sHost;
					int iPort;
					std::string sDB;
					std::string sUser;
					std::string sPwd;
					/**************************************/


					/************************************/
					MYSQL mySql;
					MYSQL* connection;

					friend class SQLConnectionManager;
			};
		}
    }
};

#endif //__BOS_MYSQL_CONNECTION_H__
