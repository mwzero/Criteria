#ifndef _BOS_SQL_FIELD_H_
#define _BOS_SQL_FIELD_H_

//TO_BE_EXPORTED
#include "bOS.h"

namespace bOS
{
	namespace SQL
	{
		class SQLField;
		typedef vector<SQLField> SQLFieldList;

		union FieldValue
		{
			char sValue[65535];
			long lValue;
			int iValue;
		};



		class BOS_API SQLField
		{
		public:

			enum FieldType
			{
				NONE,
				LONG,
				INT,
				STRING,
				NUMBER,
				DATE,
				LONGTEXT
			};

			SQLField(const char* acName, std::string& acValue);
			SQLField(const char* acName, const char* acValue);
			SQLField(const char* acName, long lValue);
			SQLField(const char* acName, int iValue);
			SQLField( const SQLField&);
			virtual ~SQLField();

			std::string sName;
			FieldType iType;
			unsigned int size;
			int decim_size;
			int nullable; // 0: NOT-NULL,1: NULL,2: NOT-KNOWN

			std::string getValue();
			FieldValue uValue;

		private:

		};
	}
}

#endif //_SQL_FIELD_H_
