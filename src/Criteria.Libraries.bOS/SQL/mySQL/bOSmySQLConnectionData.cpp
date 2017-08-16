#include "CommonDefines.h"

#include "bOSmySQLConnectionData.h"
using namespace bOS::SQL::mySQL;

mySQLConnectionData::mySQLConnectionData() : bOS::SQL::SQLConnectionData()
{
    this->iPort = 3306;
}

mySQLConnectionData::~mySQLConnectionData()
{
}

void mySQLConnectionData::init(SQLConnectionData* connData)
{
	mySQLConnectionData* mysql = (mySQLConnectionData*)connData;

	this->sHost = mysql->sHost;
	this->iPort = mysql->iPort;
	this->sDB = mysql->sDB;
	this->sUser = mysql->sUser;
	this->sPassword = mysql->sPassword;
}
