#------------------------------------------------------------------------------#
# This makefile was generated by 'cbp2make' tool rev.147                       #
#------------------------------------------------------------------------------#


WORKDIR = %cd%

CC = gcc.exe
CXX = g++.exe
AR = ar.exe
LD = gcc.exe
WINDRES = windres.exe

INC = -I. -I.\\CodeManager -I.\\IO -I.\\Network -I.\\Network\\SMTP -I.\\Utils -I.\\Core -I.\\System -I.\\Exception -I.\\String -I.\\XML -I.\\XML\\XSLT -I.\\XML\\Data\\FileSystem -I.\\XML\\Data -I.\\Collections -I.\\SQL -I.\\SQL\\mySQL -ISQL\\SQLite3 -ISQL\\SQLite3\\3rdLibraries -I..\\..\\include -I%MINGW_HOME%\\msys\\1.0\\opt\\xerces-c-3.1.4\\src
CFLAGS = -W -O0 -DWIN32 -D_DEBUG -D_WINDOWS -D_USRDLL -D_CODEMANAGER_TRACE_ON_ -DBOS_EXPORTS -DCODEMANAGER_EXPORTS
RESINC = 
LIBDIR = -L..\\..\\lib
LIB = %MINGW_HOME%\\lib\\libws2_32.a libxerces-c.dll.a ..\\..\\lib\\libmySQL.lib
LDFLAGS = 

INC_RELEASE_WIN32 = $(INC) -I. -I.\CodeManager -I.\IO -I.\Network -I.\Network\SMTP -I.\Utils -I.\Core -I.\System -I.\Exception -I.\String -I.\XML -I.\XML\XSLT -I.\XML\Data\FileSystem -I.\XML\Data -I.\Collections -I.\SQL -I.\SQL\mySQL -I..\..\include
CFLAGS_RELEASE_WIN32 = $(CFLAGS) -O2 -std=c++11 -W -DWIN32 -D_WIN32 -D_WINDOWS -D_USRDLL -DBOS_EXPORTS -DCODEMANAGER_EXPORTS -DCRT_NONSTDC_NO_DEPRECATE
RESINC_RELEASE_WIN32 = $(RESINC) -I. -I.\CodeManager -I.\IO -I.\Network -I.\Network\SMTP -I.\Utils -I.\Core -I.\System -I.\Exception -I.\String -I.\XML -I.\XML\XSLT -I.\XML\Data\FileSystem -I.\XML\Data -I.\Collections -I.\SQL -I.\SQL\mySQL
RCFLAGS_RELEASE_WIN32 = $(RCFLAGS)
LIBDIR_RELEASE_WIN32 = $(LIBDIR) -L..\..\lib
LIB_RELEASE_WIN32 = $(LIB)
LDFLAGS_RELEASE_WIN32 = $(LDFLAGS)
OBJDIR_RELEASE_WIN32 = $(TARGET_OUTPUT_DIR)$(TARGET_OUTPUT_BASENAME)
DEP_RELEASE_WIN32 = 
OUT_RELEASE_WIN32 = \\Libraries.dll

INC_DEBUG_WIN32 = $(INC) -I. -I.\CodeManager -I.\IO -I.\Network -I.\Network\SMTP -I.\Utils -I.\Core -I.\System -I.\Exception -I.\String -I.\XML -I.\XML\XSLT -I.\XML\Data\FileSystem -I.\XML\Data -I.\Collections -I.\SQL -I.\SQL\mySQL
CFLAGS_DEBUG_WIN32 = $(CFLAGS) -std=c++11 -Wall -g -DWIN32 -D_WIN32 -D_WINDOWS -D_USRDLL -DBOS_EXPORTS -DCODEMANAGER_EXPORTS -DCRT_NONSTDC_NO_DEPRECATE
RESINC_DEBUG_WIN32 = $(RESINC)
RCFLAGS_DEBUG_WIN32 = $(RCFLAGS)
LIBDIR_DEBUG_WIN32 = $(LIBDIR) -L..\..\lib
LIB_DEBUG_WIN32 = $(LIB)
LDFLAGS_DEBUG_WIN32 = $(LDFLAGS)
OBJDIR_DEBUG_WIN32 = $(TARGET_OUTPUT_DIR)$(TARGET_OUTPUT_BASENAME)
DEP_DEBUG_WIN32 = 
OUT_DEBUG_WIN32 = \\LibrariesD.dll

OBJ_RELEASE_WIN32 = $(OBJDIR_RELEASE_WIN32)\\Utils\\bOSDate.o $(OBJDIR_RELEASE_WIN32)\\System\\bOSSystem.o $(OBJDIR_RELEASE_WIN32)\\System\\bOSProcess.o $(OBJDIR_RELEASE_WIN32)\\String\\bOSStringUtils.o $(OBJDIR_RELEASE_WIN32)\\String\\bOSStringBuffer.o $(OBJDIR_RELEASE_WIN32)\\String\\bOSString.o $(OBJDIR_RELEASE_WIN32)\\SQL\\mySQL\\bOSmySQLResultSetMetaData.o $(OBJDIR_RELEASE_WIN32)\\SQL\\mySQL\\bOSmySQLResultSetField.o $(OBJDIR_RELEASE_WIN32)\\SQL\\mySQL\\bOSmySQLResultSet.o $(OBJDIR_RELEASE_WIN32)\\SQL\\mySQL\\bOSmySQLConnectionData.o $(OBJDIR_RELEASE_WIN32)\\SQL\\mySQL\\bOSmySQLConnection.o $(OBJDIR_RELEASE_WIN32)\\SQL\\bOSSQLTable.o $(OBJDIR_RELEASE_WIN32)\\SQL\\bOSSQLSmartConnection.o $(OBJDIR_RELEASE_WIN32)\\SQL\\bOSSQLField.o $(OBJDIR_RELEASE_WIN32)\\SQL\\bOSSQLConnectionPool.o $(OBJDIR_RELEASE_WIN32)\\bOS.o $(OBJDIR_RELEASE_WIN32)\\XML\\bOSXMLNode.o $(OBJDIR_RELEASE_WIN32)\\XML\\bOSXMLHelper.o $(OBJDIR_RELEASE_WIN32)\\XML\\bOSXMLAttribute.o $(OBJDIR_RELEASE_WIN32)\\XML\\XSLT\\bOSXSLTManager.o $(OBJDIR_RELEASE_WIN32)\\XML\\Data\\bOSXMLObjectSet.o $(OBJDIR_RELEASE_WIN32)\\XML\\Data\\bOSXMLObject.o $(OBJDIR_RELEASE_WIN32)\\XML\\Data\\FileSystem\\bOSXMLFile.o $(OBJDIR_RELEASE_WIN32)\\XML\\Data\\FileSystem\\bOSXMLDirectory.o $(OBJDIR_RELEASE_WIN32)\\Utils\\bOSUniqueID.o $(OBJDIR_RELEASE_WIN32)\\Utils\\bOSTimer.o $(OBJDIR_RELEASE_WIN32)\\Utils\\bOSTime.o $(OBJDIR_RELEASE_WIN32)\\Utils\\bOSDateTime.o $(OBJDIR_RELEASE_WIN32)\\IO\\bOSFileSystem.o $(OBJDIR_RELEASE_WIN32)\\IO\\bOSFile.o $(OBJDIR_RELEASE_WIN32)\\Exception\\bOSException.o $(OBJDIR_RELEASE_WIN32)\\Core\\bOSThread.o $(OBJDIR_RELEASE_WIN32)\\Core\\bOSSmartLocker.o $(OBJDIR_RELEASE_WIN32)\\Core\\bOSSemaphore.o $(OBJDIR_RELEASE_WIN32)\\Core\\bOSMutex.o $(OBJDIR_RELEASE_WIN32)\\Collections\\bOSCollectionEntry.o $(OBJDIR_RELEASE_WIN32)\\Collections\\bOSCollection.o $(OBJDIR_RELEASE_WIN32)\\CodeManager\\Tracer.o $(OBJDIR_RELEASE_WIN32)\\CodeManager\\CodeTracer.o $(OBJDIR_RELEASE_WIN32)\\CodeManager\\CodeItem.o $(OBJDIR_RELEASE_WIN32)\\SQL\\bOSSQLConnectionManager.o $(OBJDIR_RELEASE_WIN32)\\SQL\\bOSSQLConnection.o $(OBJDIR_RELEASE_WIN32)\\SQL\\bOSSQLCommands.o $(OBJDIR_RELEASE_WIN32)\\SQL\\bOSSQLCommand.o $(OBJDIR_RELEASE_WIN32)\\SQL\\bOSResultSetRecord.o $(OBJDIR_RELEASE_WIN32)\\SQL\\bOSResultSetMetaData.o $(OBJDIR_RELEASE_WIN32)\\SQL\\bOSResultSetField.o $(OBJDIR_RELEASE_WIN32)\\SQL\\bOSResultSet.o $(OBJDIR_RELEASE_WIN32)\\Network\\bOSSockets.o $(OBJDIR_RELEASE_WIN32)\\Network\\bOSSocketException.o

OBJ_DEBUG_WIN32 = $(OBJDIR_DEBUG_WIN32)\\Utils\\bOSDate.o $(OBJDIR_DEBUG_WIN32)\\System\\bOSSystem.o $(OBJDIR_DEBUG_WIN32)\\System\\bOSProcess.o $(OBJDIR_DEBUG_WIN32)\\String\\bOSStringUtils.o $(OBJDIR_DEBUG_WIN32)\\String\\bOSStringBuffer.o $(OBJDIR_DEBUG_WIN32)\\String\\bOSString.o $(OBJDIR_DEBUG_WIN32)\\SQL\\mySQL\\bOSmySQLResultSetMetaData.o $(OBJDIR_DEBUG_WIN32)\\SQL\\mySQL\\bOSmySQLResultSetField.o $(OBJDIR_DEBUG_WIN32)\\SQL\\mySQL\\bOSmySQLResultSet.o $(OBJDIR_DEBUG_WIN32)\\SQL\\mySQL\\bOSmySQLConnectionData.o $(OBJDIR_DEBUG_WIN32)\\SQL\\mySQL\\bOSmySQLConnection.o $(OBJDIR_DEBUG_WIN32)\\SQL\\bOSSQLTable.o $(OBJDIR_DEBUG_WIN32)\\SQL\\bOSSQLSmartConnection.o $(OBJDIR_DEBUG_WIN32)\\SQL\\bOSSQLField.o $(OBJDIR_DEBUG_WIN32)\\SQL\\bOSSQLConnectionPool.o $(OBJDIR_DEBUG_WIN32)\\bOS.o $(OBJDIR_DEBUG_WIN32)\\XML\\bOSXMLNode.o $(OBJDIR_DEBUG_WIN32)\\XML\\bOSXMLHelper.o $(OBJDIR_DEBUG_WIN32)\\XML\\bOSXMLAttribute.o $(OBJDIR_DEBUG_WIN32)\\XML\\XSLT\\bOSXSLTManager.o $(OBJDIR_DEBUG_WIN32)\\XML\\Data\\bOSXMLObjectSet.o $(OBJDIR_DEBUG_WIN32)\\XML\\Data\\bOSXMLObject.o $(OBJDIR_DEBUG_WIN32)\\XML\\Data\\FileSystem\\bOSXMLFile.o $(OBJDIR_DEBUG_WIN32)\\XML\\Data\\FileSystem\\bOSXMLDirectory.o $(OBJDIR_DEBUG_WIN32)\\Utils\\bOSUniqueID.o $(OBJDIR_DEBUG_WIN32)\\Utils\\bOSTimer.o $(OBJDIR_DEBUG_WIN32)\\Utils\\bOSTime.o $(OBJDIR_DEBUG_WIN32)\\Utils\\bOSDateTime.o $(OBJDIR_DEBUG_WIN32)\\IO\\bOSFileSystem.o $(OBJDIR_DEBUG_WIN32)\\IO\\bOSFile.o $(OBJDIR_DEBUG_WIN32)\\Exception\\bOSException.o $(OBJDIR_DEBUG_WIN32)\\Core\\bOSThread.o $(OBJDIR_DEBUG_WIN32)\\Core\\bOSSmartLocker.o $(OBJDIR_DEBUG_WIN32)\\Core\\bOSSemaphore.o $(OBJDIR_DEBUG_WIN32)\\Core\\bOSMutex.o $(OBJDIR_DEBUG_WIN32)\\Collections\\bOSCollectionEntry.o $(OBJDIR_DEBUG_WIN32)\\Collections\\bOSCollection.o $(OBJDIR_DEBUG_WIN32)\\CodeManager\\Tracer.o $(OBJDIR_DEBUG_WIN32)\\CodeManager\\CodeTracer.o $(OBJDIR_DEBUG_WIN32)\\CodeManager\\CodeItem.o $(OBJDIR_DEBUG_WIN32)\\SQL\\bOSSQLConnectionManager.o $(OBJDIR_DEBUG_WIN32)\\SQL\\bOSSQLConnection.o $(OBJDIR_DEBUG_WIN32)\\SQL\\bOSSQLCommands.o $(OBJDIR_DEBUG_WIN32)\\SQL\\bOSSQLCommand.o $(OBJDIR_DEBUG_WIN32)\\SQL\\bOSResultSetRecord.o $(OBJDIR_DEBUG_WIN32)\\SQL\\bOSResultSetMetaData.o $(OBJDIR_DEBUG_WIN32)\\SQL\\bOSResultSetField.o $(OBJDIR_DEBUG_WIN32)\\SQL\\bOSResultSet.o $(OBJDIR_DEBUG_WIN32)\\Network\\bOSSockets.o $(OBJDIR_DEBUG_WIN32)\\Network\\bOSSocketException.o

all: release_win32 debug_win32

clean: clean_release_win32 clean_debug_win32

after_release_win32: 

release_win32: before_release_win32 out_release_win32 after_release_win32

out_release_win32: before_release_win32 $(OBJ_RELEASE_WIN32) $(DEP_RELEASE_WIN32)
	$(LD) -shared $(LIBDIR_RELEASE_WIN32) $(OBJ_RELEASE_WIN32)  -o $(OUT_RELEASE_WIN32) $(LDFLAGS_RELEASE_WIN32) $(LIB_RELEASE_WIN32)

$(OBJDIR_RELEASE_WIN32)\\Utils\\bOSDate.o: Utils\\bOSDate.cpp
	$(CXX) $(CFLAGS_RELEASE_WIN32) $(INC_RELEASE_WIN32) -c Utils\\bOSDate.cpp -o $(OBJDIR_RELEASE_WIN32)\\Utils\\bOSDate.o

$(OBJDIR_RELEASE_WIN32)\\System\\bOSSystem.o: System\\bOSSystem.cpp
	$(CXX) $(CFLAGS_RELEASE_WIN32) $(INC_RELEASE_WIN32) -c System\\bOSSystem.cpp -o $(OBJDIR_RELEASE_WIN32)\\System\\bOSSystem.o

$(OBJDIR_RELEASE_WIN32)\\System\\bOSProcess.o: System\\bOSProcess.cpp
	$(CXX) $(CFLAGS_RELEASE_WIN32) $(INC_RELEASE_WIN32) -c System\\bOSProcess.cpp -o $(OBJDIR_RELEASE_WIN32)\\System\\bOSProcess.o

$(OBJDIR_RELEASE_WIN32)\\String\\bOSStringUtils.o: String\\bOSStringUtils.cpp
	$(CXX) $(CFLAGS_RELEASE_WIN32) $(INC_RELEASE_WIN32) -c String\\bOSStringUtils.cpp -o $(OBJDIR_RELEASE_WIN32)\\String\\bOSStringUtils.o

$(OBJDIR_RELEASE_WIN32)\\String\\bOSStringBuffer.o: String\\bOSStringBuffer.cpp
	$(CXX) $(CFLAGS_RELEASE_WIN32) $(INC_RELEASE_WIN32) -c String\\bOSStringBuffer.cpp -o $(OBJDIR_RELEASE_WIN32)\\String\\bOSStringBuffer.o

$(OBJDIR_RELEASE_WIN32)\\String\\bOSString.o: String\\bOSString.cpp
	$(CXX) $(CFLAGS_RELEASE_WIN32) $(INC_RELEASE_WIN32) -c String\\bOSString.cpp -o $(OBJDIR_RELEASE_WIN32)\\String\\bOSString.o

$(OBJDIR_RELEASE_WIN32)\\SQL\\mySQL\\bOSmySQLResultSetMetaData.o: SQL\\mySQL\\bOSmySQLResultSetMetaData.cpp
	$(CXX) $(CFLAGS_RELEASE_WIN32) $(INC_RELEASE_WIN32) -c SQL\\mySQL\\bOSmySQLResultSetMetaData.cpp -o $(OBJDIR_RELEASE_WIN32)\\SQL\\mySQL\\bOSmySQLResultSetMetaData.o

$(OBJDIR_RELEASE_WIN32)\\SQL\\mySQL\\bOSmySQLResultSetField.o: SQL\\mySQL\\bOSmySQLResultSetField.cpp
	$(CXX) $(CFLAGS_RELEASE_WIN32) $(INC_RELEASE_WIN32) -c SQL\\mySQL\\bOSmySQLResultSetField.cpp -o $(OBJDIR_RELEASE_WIN32)\\SQL\\mySQL\\bOSmySQLResultSetField.o

$(OBJDIR_RELEASE_WIN32)\\SQL\\mySQL\\bOSmySQLResultSet.o: SQL\\mySQL\\bOSmySQLResultSet.cpp
	$(CXX) $(CFLAGS_RELEASE_WIN32) $(INC_RELEASE_WIN32) -c SQL\\mySQL\\bOSmySQLResultSet.cpp -o $(OBJDIR_RELEASE_WIN32)\\SQL\\mySQL\\bOSmySQLResultSet.o

$(OBJDIR_RELEASE_WIN32)\\SQL\\mySQL\\bOSmySQLConnectionData.o: SQL\\mySQL\\bOSmySQLConnectionData.cpp
	$(CXX) $(CFLAGS_RELEASE_WIN32) $(INC_RELEASE_WIN32) -c SQL\\mySQL\\bOSmySQLConnectionData.cpp -o $(OBJDIR_RELEASE_WIN32)\\SQL\\mySQL\\bOSmySQLConnectionData.o

$(OBJDIR_RELEASE_WIN32)\\SQL\\mySQL\\bOSmySQLConnection.o: SQL\\mySQL\\bOSmySQLConnection.cpp
	$(CXX) $(CFLAGS_RELEASE_WIN32) $(INC_RELEASE_WIN32) -c SQL\\mySQL\\bOSmySQLConnection.cpp -o $(OBJDIR_RELEASE_WIN32)\\SQL\\mySQL\\bOSmySQLConnection.o

$(OBJDIR_RELEASE_WIN32)\\SQL\\bOSSQLTable.o: SQL\\bOSSQLTable.cpp
	$(CXX) $(CFLAGS_RELEASE_WIN32) $(INC_RELEASE_WIN32) -c SQL\\bOSSQLTable.cpp -o $(OBJDIR_RELEASE_WIN32)\\SQL\\bOSSQLTable.o

$(OBJDIR_RELEASE_WIN32)\\SQL\\bOSSQLSmartConnection.o: SQL\\bOSSQLSmartConnection.cpp
	$(CXX) $(CFLAGS_RELEASE_WIN32) $(INC_RELEASE_WIN32) -c SQL\\bOSSQLSmartConnection.cpp -o $(OBJDIR_RELEASE_WIN32)\\SQL\\bOSSQLSmartConnection.o

$(OBJDIR_RELEASE_WIN32)\\SQL\\bOSSQLField.o: SQL\\bOSSQLField.cpp
	$(CXX) $(CFLAGS_RELEASE_WIN32) $(INC_RELEASE_WIN32) -c SQL\\bOSSQLField.cpp -o $(OBJDIR_RELEASE_WIN32)\\SQL\\bOSSQLField.o

$(OBJDIR_RELEASE_WIN32)\\SQL\\bOSSQLConnectionPool.o: SQL\\bOSSQLConnectionPool.cpp
	$(CXX) $(CFLAGS_RELEASE_WIN32) $(INC_RELEASE_WIN32) -c SQL\\bOSSQLConnectionPool.cpp -o $(OBJDIR_RELEASE_WIN32)\\SQL\\bOSSQLConnectionPool.o

$(OBJDIR_RELEASE_WIN32)\\bOS.o: bOS.cpp
	$(CXX) $(CFLAGS_RELEASE_WIN32) $(INC_RELEASE_WIN32) -c bOS.cpp -o $(OBJDIR_RELEASE_WIN32)\\bOS.o

$(OBJDIR_RELEASE_WIN32)\\XML\\bOSXMLNode.o: XML\\bOSXMLNode.cpp
	$(CXX) $(CFLAGS_RELEASE_WIN32) $(INC_RELEASE_WIN32) -c XML\\bOSXMLNode.cpp -o $(OBJDIR_RELEASE_WIN32)\\XML\\bOSXMLNode.o

$(OBJDIR_RELEASE_WIN32)\\XML\\bOSXMLHelper.o: XML\\bOSXMLHelper.cpp
	$(CXX) $(CFLAGS_RELEASE_WIN32) $(INC_RELEASE_WIN32) -c XML\\bOSXMLHelper.cpp -o $(OBJDIR_RELEASE_WIN32)\\XML\\bOSXMLHelper.o

$(OBJDIR_RELEASE_WIN32)\\XML\\bOSXMLAttribute.o: XML\\bOSXMLAttribute.cpp
	$(CXX) $(CFLAGS_RELEASE_WIN32) $(INC_RELEASE_WIN32) -c XML\\bOSXMLAttribute.cpp -o $(OBJDIR_RELEASE_WIN32)\\XML\\bOSXMLAttribute.o

$(OBJDIR_RELEASE_WIN32)\\XML\\XSLT\\bOSXSLTManager.o: XML\\XSLT\\bOSXSLTManager.cpp
	$(CXX) $(CFLAGS_RELEASE_WIN32) $(INC_RELEASE_WIN32) -c XML\\XSLT\\bOSXSLTManager.cpp -o $(OBJDIR_RELEASE_WIN32)\\XML\\XSLT\\bOSXSLTManager.o

$(OBJDIR_RELEASE_WIN32)\\XML\\Data\\bOSXMLObjectSet.o: XML\\Data\\bOSXMLObjectSet.cpp
	$(CXX) $(CFLAGS_RELEASE_WIN32) $(INC_RELEASE_WIN32) -c XML\\Data\\bOSXMLObjectSet.cpp -o $(OBJDIR_RELEASE_WIN32)\\XML\\Data\\bOSXMLObjectSet.o

$(OBJDIR_RELEASE_WIN32)\\XML\\Data\\bOSXMLObject.o: XML\\Data\\bOSXMLObject.cpp
	$(CXX) $(CFLAGS_RELEASE_WIN32) $(INC_RELEASE_WIN32) -c XML\\Data\\bOSXMLObject.cpp -o $(OBJDIR_RELEASE_WIN32)\\XML\\Data\\bOSXMLObject.o

$(OBJDIR_RELEASE_WIN32)\\XML\\Data\\FileSystem\\bOSXMLFile.o: XML\\Data\\FileSystem\\bOSXMLFile.cpp
	$(CXX) $(CFLAGS_RELEASE_WIN32) $(INC_RELEASE_WIN32) -c XML\\Data\\FileSystem\\bOSXMLFile.cpp -o $(OBJDIR_RELEASE_WIN32)\\XML\\Data\\FileSystem\\bOSXMLFile.o

$(OBJDIR_RELEASE_WIN32)\\XML\\Data\\FileSystem\\bOSXMLDirectory.o: XML\\Data\\FileSystem\\bOSXMLDirectory.cpp
	$(CXX) $(CFLAGS_RELEASE_WIN32) $(INC_RELEASE_WIN32) -c XML\\Data\\FileSystem\\bOSXMLDirectory.cpp -o $(OBJDIR_RELEASE_WIN32)\\XML\\Data\\FileSystem\\bOSXMLDirectory.o

$(OBJDIR_RELEASE_WIN32)\\Utils\\bOSUniqueID.o: Utils\\bOSUniqueID.cpp
	$(CXX) $(CFLAGS_RELEASE_WIN32) $(INC_RELEASE_WIN32) -c Utils\\bOSUniqueID.cpp -o $(OBJDIR_RELEASE_WIN32)\\Utils\\bOSUniqueID.o

$(OBJDIR_RELEASE_WIN32)\\Utils\\bOSTimer.o: Utils\\bOSTimer.cpp
	$(CXX) $(CFLAGS_RELEASE_WIN32) $(INC_RELEASE_WIN32) -c Utils\\bOSTimer.cpp -o $(OBJDIR_RELEASE_WIN32)\\Utils\\bOSTimer.o

$(OBJDIR_RELEASE_WIN32)\\Utils\\bOSTime.o: Utils\\bOSTime.cpp
	$(CXX) $(CFLAGS_RELEASE_WIN32) $(INC_RELEASE_WIN32) -c Utils\\bOSTime.cpp -o $(OBJDIR_RELEASE_WIN32)\\Utils\\bOSTime.o

$(OBJDIR_RELEASE_WIN32)\\Utils\\bOSDateTime.o: Utils\\bOSDateTime.cpp
	$(CXX) $(CFLAGS_RELEASE_WIN32) $(INC_RELEASE_WIN32) -c Utils\\bOSDateTime.cpp -o $(OBJDIR_RELEASE_WIN32)\\Utils\\bOSDateTime.o

$(OBJDIR_RELEASE_WIN32)\\IO\\bOSFileSystem.o: IO\\bOSFileSystem.cpp
	$(CXX) $(CFLAGS_RELEASE_WIN32) $(INC_RELEASE_WIN32) -c IO\\bOSFileSystem.cpp -o $(OBJDIR_RELEASE_WIN32)\\IO\\bOSFileSystem.o

$(OBJDIR_RELEASE_WIN32)\\IO\\bOSFile.o: IO\\bOSFile.cpp
	$(CXX) $(CFLAGS_RELEASE_WIN32) $(INC_RELEASE_WIN32) -c IO\\bOSFile.cpp -o $(OBJDIR_RELEASE_WIN32)\\IO\\bOSFile.o

$(OBJDIR_RELEASE_WIN32)\\Exception\\bOSException.o: Exception\\bOSException.cpp
	$(CXX) $(CFLAGS_RELEASE_WIN32) $(INC_RELEASE_WIN32) -c Exception\\bOSException.cpp -o $(OBJDIR_RELEASE_WIN32)\\Exception\\bOSException.o

$(OBJDIR_RELEASE_WIN32)\\Core\\bOSThread.o: Core\\bOSThread.cpp
	$(CXX) $(CFLAGS_RELEASE_WIN32) $(INC_RELEASE_WIN32) -c Core\\bOSThread.cpp -o $(OBJDIR_RELEASE_WIN32)\\Core\\bOSThread.o

$(OBJDIR_RELEASE_WIN32)\\Core\\bOSSmartLocker.o: Core\\bOSSmartLocker.cpp
	$(CXX) $(CFLAGS_RELEASE_WIN32) $(INC_RELEASE_WIN32) -c Core\\bOSSmartLocker.cpp -o $(OBJDIR_RELEASE_WIN32)\\Core\\bOSSmartLocker.o

$(OBJDIR_RELEASE_WIN32)\\Core\\bOSSemaphore.o: Core\\bOSSemaphore.cpp
	$(CXX) $(CFLAGS_RELEASE_WIN32) $(INC_RELEASE_WIN32) -c Core\\bOSSemaphore.cpp -o $(OBJDIR_RELEASE_WIN32)\\Core\\bOSSemaphore.o

$(OBJDIR_RELEASE_WIN32)\\Core\\bOSMutex.o: Core\\bOSMutex.cpp
	$(CXX) $(CFLAGS_RELEASE_WIN32) $(INC_RELEASE_WIN32) -c Core\\bOSMutex.cpp -o $(OBJDIR_RELEASE_WIN32)\\Core\\bOSMutex.o

$(OBJDIR_RELEASE_WIN32)\\Collections\\bOSCollectionEntry.o: Collections\\bOSCollectionEntry.cpp
	$(CXX) $(CFLAGS_RELEASE_WIN32) $(INC_RELEASE_WIN32) -c Collections\\bOSCollectionEntry.cpp -o $(OBJDIR_RELEASE_WIN32)\\Collections\\bOSCollectionEntry.o

$(OBJDIR_RELEASE_WIN32)\\Collections\\bOSCollection.o: Collections\\bOSCollection.cpp
	$(CXX) $(CFLAGS_RELEASE_WIN32) $(INC_RELEASE_WIN32) -c Collections\\bOSCollection.cpp -o $(OBJDIR_RELEASE_WIN32)\\Collections\\bOSCollection.o

$(OBJDIR_RELEASE_WIN32)\\CodeManager\\Tracer.o: CodeManager\\Tracer.cpp
	$(CXX) $(CFLAGS_RELEASE_WIN32) $(INC_RELEASE_WIN32) -c CodeManager\\Tracer.cpp -o $(OBJDIR_RELEASE_WIN32)\\CodeManager\\Tracer.o

$(OBJDIR_RELEASE_WIN32)\\CodeManager\\CodeTracer.o: CodeManager\\CodeTracer.cpp
	$(CXX) $(CFLAGS_RELEASE_WIN32) $(INC_RELEASE_WIN32) -c CodeManager\\CodeTracer.cpp -o $(OBJDIR_RELEASE_WIN32)\\CodeManager\\CodeTracer.o

$(OBJDIR_RELEASE_WIN32)\\CodeManager\\CodeItem.o: CodeManager\\CodeItem.cpp
	$(CXX) $(CFLAGS_RELEASE_WIN32) $(INC_RELEASE_WIN32) -c CodeManager\\CodeItem.cpp -o $(OBJDIR_RELEASE_WIN32)\\CodeManager\\CodeItem.o

$(OBJDIR_RELEASE_WIN32)\\SQL\\bOSSQLConnectionManager.o: SQL\\bOSSQLConnectionManager.cpp
	$(CXX) $(CFLAGS_RELEASE_WIN32) $(INC_RELEASE_WIN32) -c SQL\\bOSSQLConnectionManager.cpp -o $(OBJDIR_RELEASE_WIN32)\\SQL\\bOSSQLConnectionManager.o

$(OBJDIR_RELEASE_WIN32)\\SQL\\bOSSQLConnection.o: SQL\\bOSSQLConnection.cpp
	$(CXX) $(CFLAGS_RELEASE_WIN32) $(INC_RELEASE_WIN32) -c SQL\\bOSSQLConnection.cpp -o $(OBJDIR_RELEASE_WIN32)\\SQL\\bOSSQLConnection.o

$(OBJDIR_RELEASE_WIN32)\\SQL\\bOSSQLCommands.o: SQL\\bOSSQLCommands.cpp
	$(CXX) $(CFLAGS_RELEASE_WIN32) $(INC_RELEASE_WIN32) -c SQL\\bOSSQLCommands.cpp -o $(OBJDIR_RELEASE_WIN32)\\SQL\\bOSSQLCommands.o

$(OBJDIR_RELEASE_WIN32)\\SQL\\bOSSQLCommand.o: SQL\\bOSSQLCommand.cpp
	$(CXX) $(CFLAGS_RELEASE_WIN32) $(INC_RELEASE_WIN32) -c SQL\\bOSSQLCommand.cpp -o $(OBJDIR_RELEASE_WIN32)\\SQL\\bOSSQLCommand.o

$(OBJDIR_RELEASE_WIN32)\\SQL\\bOSResultSetRecord.o: SQL\\bOSResultSetRecord.cpp
	$(CXX) $(CFLAGS_RELEASE_WIN32) $(INC_RELEASE_WIN32) -c SQL\\bOSResultSetRecord.cpp -o $(OBJDIR_RELEASE_WIN32)\\SQL\\bOSResultSetRecord.o

$(OBJDIR_RELEASE_WIN32)\\SQL\\bOSResultSetMetaData.o: SQL\\bOSResultSetMetaData.cpp
	$(CXX) $(CFLAGS_RELEASE_WIN32) $(INC_RELEASE_WIN32) -c SQL\\bOSResultSetMetaData.cpp -o $(OBJDIR_RELEASE_WIN32)\\SQL\\bOSResultSetMetaData.o

$(OBJDIR_RELEASE_WIN32)\\SQL\\bOSResultSetField.o: SQL\\bOSResultSetField.cpp
	$(CXX) $(CFLAGS_RELEASE_WIN32) $(INC_RELEASE_WIN32) -c SQL\\bOSResultSetField.cpp -o $(OBJDIR_RELEASE_WIN32)\\SQL\\bOSResultSetField.o

$(OBJDIR_RELEASE_WIN32)\\SQL\\bOSResultSet.o: SQL\\bOSResultSet.cpp
	$(CXX) $(CFLAGS_RELEASE_WIN32) $(INC_RELEASE_WIN32) -c SQL\\bOSResultSet.cpp -o $(OBJDIR_RELEASE_WIN32)\\SQL\\bOSResultSet.o

$(OBJDIR_RELEASE_WIN32)\\Network\\bOSSockets.o: Network\\bOSSockets.cpp
	$(CXX) $(CFLAGS_RELEASE_WIN32) $(INC_RELEASE_WIN32) -c Network\\bOSSockets.cpp -o $(OBJDIR_RELEASE_WIN32)\\Network\\bOSSockets.o

$(OBJDIR_RELEASE_WIN32)\\Network\\bOSSocketException.o: Network\\bOSSocketException.cpp
	$(CXX) $(CFLAGS_RELEASE_WIN32) $(INC_RELEASE_WIN32) -c Network\\bOSSocketException.cpp -o $(OBJDIR_RELEASE_WIN32)\\Network\\bOSSocketException.o

clean_release_win32: 
	cmd /c del /f $(OBJ_RELEASE_WIN32) $(OUT_RELEASE_WIN32)
	cmd /c rd $(OBJDIR_RELEASE_WIN32)\\Utils
	cmd /c rd $(OBJDIR_RELEASE_WIN32)\\System
	cmd /c rd $(OBJDIR_RELEASE_WIN32)\\String
	cmd /c rd $(OBJDIR_RELEASE_WIN32)\\SQL\\mySQL
	cmd /c rd $(OBJDIR_RELEASE_WIN32)\\SQL
	cmd /c rd $(OBJDIR_RELEASE_WIN32)
	cmd /c rd $(OBJDIR_RELEASE_WIN32)\\XML
	cmd /c rd $(OBJDIR_RELEASE_WIN32)\\XML\\XSLT
	cmd /c rd $(OBJDIR_RELEASE_WIN32)\\XML\\Data
	cmd /c rd $(OBJDIR_RELEASE_WIN32)\\XML\\Data\\FileSystem
	cmd /c rd $(OBJDIR_RELEASE_WIN32)\\IO
	cmd /c rd $(OBJDIR_RELEASE_WIN32)\\Exception
	cmd /c rd $(OBJDIR_RELEASE_WIN32)\\Core
	cmd /c rd $(OBJDIR_RELEASE_WIN32)\\Collections
	cmd /c rd $(OBJDIR_RELEASE_WIN32)\\CodeManager
	cmd /c rd $(OBJDIR_RELEASE_WIN32)\\Network

after_debug_win32: 

debug_win32: before_debug_win32 out_debug_win32 after_debug_win32

out_debug_win32: before_debug_win32 $(OBJ_DEBUG_WIN32) $(DEP_DEBUG_WIN32)
	$(LD) -shared $(LIBDIR_DEBUG_WIN32) $(OBJ_DEBUG_WIN32)  -o $(OUT_DEBUG_WIN32) $(LDFLAGS_DEBUG_WIN32) $(LIB_DEBUG_WIN32)

$(OBJDIR_DEBUG_WIN32)\\Utils\\bOSDate.o: Utils\\bOSDate.cpp
	$(CXX) $(CFLAGS_DEBUG_WIN32) $(INC_DEBUG_WIN32) -c Utils\\bOSDate.cpp -o $(OBJDIR_DEBUG_WIN32)\\Utils\\bOSDate.o

$(OBJDIR_DEBUG_WIN32)\\System\\bOSSystem.o: System\\bOSSystem.cpp
	$(CXX) $(CFLAGS_DEBUG_WIN32) $(INC_DEBUG_WIN32) -c System\\bOSSystem.cpp -o $(OBJDIR_DEBUG_WIN32)\\System\\bOSSystem.o

$(OBJDIR_DEBUG_WIN32)\\System\\bOSProcess.o: System\\bOSProcess.cpp
	$(CXX) $(CFLAGS_DEBUG_WIN32) $(INC_DEBUG_WIN32) -c System\\bOSProcess.cpp -o $(OBJDIR_DEBUG_WIN32)\\System\\bOSProcess.o

$(OBJDIR_DEBUG_WIN32)\\String\\bOSStringUtils.o: String\\bOSStringUtils.cpp
	$(CXX) $(CFLAGS_DEBUG_WIN32) $(INC_DEBUG_WIN32) -c String\\bOSStringUtils.cpp -o $(OBJDIR_DEBUG_WIN32)\\String\\bOSStringUtils.o

$(OBJDIR_DEBUG_WIN32)\\String\\bOSStringBuffer.o: String\\bOSStringBuffer.cpp
	$(CXX) $(CFLAGS_DEBUG_WIN32) $(INC_DEBUG_WIN32) -c String\\bOSStringBuffer.cpp -o $(OBJDIR_DEBUG_WIN32)\\String\\bOSStringBuffer.o

$(OBJDIR_DEBUG_WIN32)\\String\\bOSString.o: String\\bOSString.cpp
	$(CXX) $(CFLAGS_DEBUG_WIN32) $(INC_DEBUG_WIN32) -c String\\bOSString.cpp -o $(OBJDIR_DEBUG_WIN32)\\String\\bOSString.o

$(OBJDIR_DEBUG_WIN32)\\SQL\\mySQL\\bOSmySQLResultSetMetaData.o: SQL\\mySQL\\bOSmySQLResultSetMetaData.cpp
	$(CXX) $(CFLAGS_DEBUG_WIN32) $(INC_DEBUG_WIN32) -c SQL\\mySQL\\bOSmySQLResultSetMetaData.cpp -o $(OBJDIR_DEBUG_WIN32)\\SQL\\mySQL\\bOSmySQLResultSetMetaData.o

$(OBJDIR_DEBUG_WIN32)\\SQL\\mySQL\\bOSmySQLResultSetField.o: SQL\\mySQL\\bOSmySQLResultSetField.cpp
	$(CXX) $(CFLAGS_DEBUG_WIN32) $(INC_DEBUG_WIN32) -c SQL\\mySQL\\bOSmySQLResultSetField.cpp -o $(OBJDIR_DEBUG_WIN32)\\SQL\\mySQL\\bOSmySQLResultSetField.o

$(OBJDIR_DEBUG_WIN32)\\SQL\\mySQL\\bOSmySQLResultSet.o: SQL\\mySQL\\bOSmySQLResultSet.cpp
	$(CXX) $(CFLAGS_DEBUG_WIN32) $(INC_DEBUG_WIN32) -c SQL\\mySQL\\bOSmySQLResultSet.cpp -o $(OBJDIR_DEBUG_WIN32)\\SQL\\mySQL\\bOSmySQLResultSet.o

$(OBJDIR_DEBUG_WIN32)\\SQL\\mySQL\\bOSmySQLConnectionData.o: SQL\\mySQL\\bOSmySQLConnectionData.cpp
	$(CXX) $(CFLAGS_DEBUG_WIN32) $(INC_DEBUG_WIN32) -c SQL\\mySQL\\bOSmySQLConnectionData.cpp -o $(OBJDIR_DEBUG_WIN32)\\SQL\\mySQL\\bOSmySQLConnectionData.o

$(OBJDIR_DEBUG_WIN32)\\SQL\\mySQL\\bOSmySQLConnection.o: SQL\\mySQL\\bOSmySQLConnection.cpp
	$(CXX) $(CFLAGS_DEBUG_WIN32) $(INC_DEBUG_WIN32) -c SQL\\mySQL\\bOSmySQLConnection.cpp -o $(OBJDIR_DEBUG_WIN32)\\SQL\\mySQL\\bOSmySQLConnection.o

$(OBJDIR_DEBUG_WIN32)\\SQL\\bOSSQLTable.o: SQL\\bOSSQLTable.cpp
	$(CXX) $(CFLAGS_DEBUG_WIN32) $(INC_DEBUG_WIN32) -c SQL\\bOSSQLTable.cpp -o $(OBJDIR_DEBUG_WIN32)\\SQL\\bOSSQLTable.o

$(OBJDIR_DEBUG_WIN32)\\SQL\\bOSSQLSmartConnection.o: SQL\\bOSSQLSmartConnection.cpp
	$(CXX) $(CFLAGS_DEBUG_WIN32) $(INC_DEBUG_WIN32) -c SQL\\bOSSQLSmartConnection.cpp -o $(OBJDIR_DEBUG_WIN32)\\SQL\\bOSSQLSmartConnection.o

$(OBJDIR_DEBUG_WIN32)\\SQL\\bOSSQLField.o: SQL\\bOSSQLField.cpp
	$(CXX) $(CFLAGS_DEBUG_WIN32) $(INC_DEBUG_WIN32) -c SQL\\bOSSQLField.cpp -o $(OBJDIR_DEBUG_WIN32)\\SQL\\bOSSQLField.o

$(OBJDIR_DEBUG_WIN32)\\SQL\\bOSSQLConnectionPool.o: SQL\\bOSSQLConnectionPool.cpp
	$(CXX) $(CFLAGS_DEBUG_WIN32) $(INC_DEBUG_WIN32) -c SQL\\bOSSQLConnectionPool.cpp -o $(OBJDIR_DEBUG_WIN32)\\SQL\\bOSSQLConnectionPool.o

$(OBJDIR_DEBUG_WIN32)\\bOS.o: bOS.cpp
	$(CXX) $(CFLAGS_DEBUG_WIN32) $(INC_DEBUG_WIN32) -c bOS.cpp -o $(OBJDIR_DEBUG_WIN32)\\bOS.o

$(OBJDIR_DEBUG_WIN32)\\XML\\bOSXMLNode.o: XML\\bOSXMLNode.cpp
	$(CXX) $(CFLAGS_DEBUG_WIN32) $(INC_DEBUG_WIN32) -c XML\\bOSXMLNode.cpp -o $(OBJDIR_DEBUG_WIN32)\\XML\\bOSXMLNode.o

$(OBJDIR_DEBUG_WIN32)\\XML\\bOSXMLHelper.o: XML\\bOSXMLHelper.cpp
	$(CXX) $(CFLAGS_DEBUG_WIN32) $(INC_DEBUG_WIN32) -c XML\\bOSXMLHelper.cpp -o $(OBJDIR_DEBUG_WIN32)\\XML\\bOSXMLHelper.o

$(OBJDIR_DEBUG_WIN32)\\XML\\bOSXMLAttribute.o: XML\\bOSXMLAttribute.cpp
	$(CXX) $(CFLAGS_DEBUG_WIN32) $(INC_DEBUG_WIN32) -c XML\\bOSXMLAttribute.cpp -o $(OBJDIR_DEBUG_WIN32)\\XML\\bOSXMLAttribute.o

$(OBJDIR_DEBUG_WIN32)\\XML\\XSLT\\bOSXSLTManager.o: XML\\XSLT\\bOSXSLTManager.cpp
	$(CXX) $(CFLAGS_DEBUG_WIN32) $(INC_DEBUG_WIN32) -c XML\\XSLT\\bOSXSLTManager.cpp -o $(OBJDIR_DEBUG_WIN32)\\XML\\XSLT\\bOSXSLTManager.o

$(OBJDIR_DEBUG_WIN32)\\XML\\Data\\bOSXMLObjectSet.o: XML\\Data\\bOSXMLObjectSet.cpp
	$(CXX) $(CFLAGS_DEBUG_WIN32) $(INC_DEBUG_WIN32) -c XML\\Data\\bOSXMLObjectSet.cpp -o $(OBJDIR_DEBUG_WIN32)\\XML\\Data\\bOSXMLObjectSet.o

$(OBJDIR_DEBUG_WIN32)\\XML\\Data\\bOSXMLObject.o: XML\\Data\\bOSXMLObject.cpp
	$(CXX) $(CFLAGS_DEBUG_WIN32) $(INC_DEBUG_WIN32) -c XML\\Data\\bOSXMLObject.cpp -o $(OBJDIR_DEBUG_WIN32)\\XML\\Data\\bOSXMLObject.o

$(OBJDIR_DEBUG_WIN32)\\XML\\Data\\FileSystem\\bOSXMLFile.o: XML\\Data\\FileSystem\\bOSXMLFile.cpp
	$(CXX) $(CFLAGS_DEBUG_WIN32) $(INC_DEBUG_WIN32) -c XML\\Data\\FileSystem\\bOSXMLFile.cpp -o $(OBJDIR_DEBUG_WIN32)\\XML\\Data\\FileSystem\\bOSXMLFile.o

$(OBJDIR_DEBUG_WIN32)\\XML\\Data\\FileSystem\\bOSXMLDirectory.o: XML\\Data\\FileSystem\\bOSXMLDirectory.cpp
	$(CXX) $(CFLAGS_DEBUG_WIN32) $(INC_DEBUG_WIN32) -c XML\\Data\\FileSystem\\bOSXMLDirectory.cpp -o $(OBJDIR_DEBUG_WIN32)\\XML\\Data\\FileSystem\\bOSXMLDirectory.o

$(OBJDIR_DEBUG_WIN32)\\Utils\\bOSUniqueID.o: Utils\\bOSUniqueID.cpp
	$(CXX) $(CFLAGS_DEBUG_WIN32) $(INC_DEBUG_WIN32) -c Utils\\bOSUniqueID.cpp -o $(OBJDIR_DEBUG_WIN32)\\Utils\\bOSUniqueID.o

$(OBJDIR_DEBUG_WIN32)\\Utils\\bOSTimer.o: Utils\\bOSTimer.cpp
	$(CXX) $(CFLAGS_DEBUG_WIN32) $(INC_DEBUG_WIN32) -c Utils\\bOSTimer.cpp -o $(OBJDIR_DEBUG_WIN32)\\Utils\\bOSTimer.o

$(OBJDIR_DEBUG_WIN32)\\Utils\\bOSTime.o: Utils\\bOSTime.cpp
	$(CXX) $(CFLAGS_DEBUG_WIN32) $(INC_DEBUG_WIN32) -c Utils\\bOSTime.cpp -o $(OBJDIR_DEBUG_WIN32)\\Utils\\bOSTime.o

$(OBJDIR_DEBUG_WIN32)\\Utils\\bOSDateTime.o: Utils\\bOSDateTime.cpp
	$(CXX) $(CFLAGS_DEBUG_WIN32) $(INC_DEBUG_WIN32) -c Utils\\bOSDateTime.cpp -o $(OBJDIR_DEBUG_WIN32)\\Utils\\bOSDateTime.o

$(OBJDIR_DEBUG_WIN32)\\IO\\bOSFileSystem.o: IO\\bOSFileSystem.cpp
	$(CXX) $(CFLAGS_DEBUG_WIN32) $(INC_DEBUG_WIN32) -c IO\\bOSFileSystem.cpp -o $(OBJDIR_DEBUG_WIN32)\\IO\\bOSFileSystem.o

$(OBJDIR_DEBUG_WIN32)\\IO\\bOSFile.o: IO\\bOSFile.cpp
	$(CXX) $(CFLAGS_DEBUG_WIN32) $(INC_DEBUG_WIN32) -c IO\\bOSFile.cpp -o $(OBJDIR_DEBUG_WIN32)\\IO\\bOSFile.o

$(OBJDIR_DEBUG_WIN32)\\Exception\\bOSException.o: Exception\\bOSException.cpp
	$(CXX) $(CFLAGS_DEBUG_WIN32) $(INC_DEBUG_WIN32) -c Exception\\bOSException.cpp -o $(OBJDIR_DEBUG_WIN32)\\Exception\\bOSException.o

$(OBJDIR_DEBUG_WIN32)\\Core\\bOSThread.o: Core\\bOSThread.cpp
	$(CXX) $(CFLAGS_DEBUG_WIN32) $(INC_DEBUG_WIN32) -c Core\\bOSThread.cpp -o $(OBJDIR_DEBUG_WIN32)\\Core\\bOSThread.o

$(OBJDIR_DEBUG_WIN32)\\Core\\bOSSmartLocker.o: Core\\bOSSmartLocker.cpp
	$(CXX) $(CFLAGS_DEBUG_WIN32) $(INC_DEBUG_WIN32) -c Core\\bOSSmartLocker.cpp -o $(OBJDIR_DEBUG_WIN32)\\Core\\bOSSmartLocker.o

$(OBJDIR_DEBUG_WIN32)\\Core\\bOSSemaphore.o: Core\\bOSSemaphore.cpp
	$(CXX) $(CFLAGS_DEBUG_WIN32) $(INC_DEBUG_WIN32) -c Core\\bOSSemaphore.cpp -o $(OBJDIR_DEBUG_WIN32)\\Core\\bOSSemaphore.o

$(OBJDIR_DEBUG_WIN32)\\Core\\bOSMutex.o: Core\\bOSMutex.cpp
	$(CXX) $(CFLAGS_DEBUG_WIN32) $(INC_DEBUG_WIN32) -c Core\\bOSMutex.cpp -o $(OBJDIR_DEBUG_WIN32)\\Core\\bOSMutex.o

$(OBJDIR_DEBUG_WIN32)\\Collections\\bOSCollectionEntry.o: Collections\\bOSCollectionEntry.cpp
	$(CXX) $(CFLAGS_DEBUG_WIN32) $(INC_DEBUG_WIN32) -c Collections\\bOSCollectionEntry.cpp -o $(OBJDIR_DEBUG_WIN32)\\Collections\\bOSCollectionEntry.o

$(OBJDIR_DEBUG_WIN32)\\Collections\\bOSCollection.o: Collections\\bOSCollection.cpp
	$(CXX) $(CFLAGS_DEBUG_WIN32) $(INC_DEBUG_WIN32) -c Collections\\bOSCollection.cpp -o $(OBJDIR_DEBUG_WIN32)\\Collections\\bOSCollection.o

$(OBJDIR_DEBUG_WIN32)\\CodeManager\\Tracer.o: CodeManager\\Tracer.cpp
	$(CXX) $(CFLAGS_DEBUG_WIN32) $(INC_DEBUG_WIN32) -c CodeManager\\Tracer.cpp -o $(OBJDIR_DEBUG_WIN32)\\CodeManager\\Tracer.o

$(OBJDIR_DEBUG_WIN32)\\CodeManager\\CodeTracer.o: CodeManager\\CodeTracer.cpp
	$(CXX) $(CFLAGS_DEBUG_WIN32) $(INC_DEBUG_WIN32) -c CodeManager\\CodeTracer.cpp -o $(OBJDIR_DEBUG_WIN32)\\CodeManager\\CodeTracer.o

$(OBJDIR_DEBUG_WIN32)\\CodeManager\\CodeItem.o: CodeManager\\CodeItem.cpp
	$(CXX) $(CFLAGS_DEBUG_WIN32) $(INC_DEBUG_WIN32) -c CodeManager\\CodeItem.cpp -o $(OBJDIR_DEBUG_WIN32)\\CodeManager\\CodeItem.o

$(OBJDIR_DEBUG_WIN32)\\SQL\\bOSSQLConnectionManager.o: SQL\\bOSSQLConnectionManager.cpp
	$(CXX) $(CFLAGS_DEBUG_WIN32) $(INC_DEBUG_WIN32) -c SQL\\bOSSQLConnectionManager.cpp -o $(OBJDIR_DEBUG_WIN32)\\SQL\\bOSSQLConnectionManager.o

$(OBJDIR_DEBUG_WIN32)\\SQL\\bOSSQLConnection.o: SQL\\bOSSQLConnection.cpp
	$(CXX) $(CFLAGS_DEBUG_WIN32) $(INC_DEBUG_WIN32) -c SQL\\bOSSQLConnection.cpp -o $(OBJDIR_DEBUG_WIN32)\\SQL\\bOSSQLConnection.o

$(OBJDIR_DEBUG_WIN32)\\SQL\\bOSSQLCommands.o: SQL\\bOSSQLCommands.cpp
	$(CXX) $(CFLAGS_DEBUG_WIN32) $(INC_DEBUG_WIN32) -c SQL\\bOSSQLCommands.cpp -o $(OBJDIR_DEBUG_WIN32)\\SQL\\bOSSQLCommands.o

$(OBJDIR_DEBUG_WIN32)\\SQL\\bOSSQLCommand.o: SQL\\bOSSQLCommand.cpp
	$(CXX) $(CFLAGS_DEBUG_WIN32) $(INC_DEBUG_WIN32) -c SQL\\bOSSQLCommand.cpp -o $(OBJDIR_DEBUG_WIN32)\\SQL\\bOSSQLCommand.o

$(OBJDIR_DEBUG_WIN32)\\SQL\\bOSResultSetRecord.o: SQL\\bOSResultSetRecord.cpp
	$(CXX) $(CFLAGS_DEBUG_WIN32) $(INC_DEBUG_WIN32) -c SQL\\bOSResultSetRecord.cpp -o $(OBJDIR_DEBUG_WIN32)\\SQL\\bOSResultSetRecord.o

$(OBJDIR_DEBUG_WIN32)\\SQL\\bOSResultSetMetaData.o: SQL\\bOSResultSetMetaData.cpp
	$(CXX) $(CFLAGS_DEBUG_WIN32) $(INC_DEBUG_WIN32) -c SQL\\bOSResultSetMetaData.cpp -o $(OBJDIR_DEBUG_WIN32)\\SQL\\bOSResultSetMetaData.o

$(OBJDIR_DEBUG_WIN32)\\SQL\\bOSResultSetField.o: SQL\\bOSResultSetField.cpp
	$(CXX) $(CFLAGS_DEBUG_WIN32) $(INC_DEBUG_WIN32) -c SQL\\bOSResultSetField.cpp -o $(OBJDIR_DEBUG_WIN32)\\SQL\\bOSResultSetField.o

$(OBJDIR_DEBUG_WIN32)\\SQL\\bOSResultSet.o: SQL\\bOSResultSet.cpp
	$(CXX) $(CFLAGS_DEBUG_WIN32) $(INC_DEBUG_WIN32) -c SQL\\bOSResultSet.cpp -o $(OBJDIR_DEBUG_WIN32)\\SQL\\bOSResultSet.o

$(OBJDIR_DEBUG_WIN32)\\Network\\bOSSockets.o: Network\\bOSSockets.cpp
	$(CXX) $(CFLAGS_DEBUG_WIN32) $(INC_DEBUG_WIN32) -c Network\\bOSSockets.cpp -o $(OBJDIR_DEBUG_WIN32)\\Network\\bOSSockets.o

$(OBJDIR_DEBUG_WIN32)\\Network\\bOSSocketException.o: Network\\bOSSocketException.cpp
	$(CXX) $(CFLAGS_DEBUG_WIN32) $(INC_DEBUG_WIN32) -c Network\\bOSSocketException.cpp -o $(OBJDIR_DEBUG_WIN32)\\Network\\bOSSocketException.o

clean_debug_win32: 
	cmd /c del /f $(OBJ_DEBUG_WIN32) $(OUT_DEBUG_WIN32)
	cmd /c rd $(OBJDIR_DEBUG_WIN32)\\Utils
	cmd /c rd $(OBJDIR_DEBUG_WIN32)\\System
	cmd /c rd $(OBJDIR_DEBUG_WIN32)\\String
	cmd /c rd $(OBJDIR_DEBUG_WIN32)\\SQL\\mySQL
	cmd /c rd $(OBJDIR_DEBUG_WIN32)\\SQL
	cmd /c rd $(OBJDIR_DEBUG_WIN32)
	cmd /c rd $(OBJDIR_DEBUG_WIN32)\\XML
	cmd /c rd $(OBJDIR_DEBUG_WIN32)\\XML\\XSLT
	cmd /c rd $(OBJDIR_DEBUG_WIN32)\\XML\\Data
	cmd /c rd $(OBJDIR_DEBUG_WIN32)\\XML\\Data\\FileSystem
	cmd /c rd $(OBJDIR_DEBUG_WIN32)\\IO
	cmd /c rd $(OBJDIR_DEBUG_WIN32)\\Exception
	cmd /c rd $(OBJDIR_DEBUG_WIN32)\\Core
	cmd /c rd $(OBJDIR_DEBUG_WIN32)\\Collections
	cmd /c rd $(OBJDIR_DEBUG_WIN32)\\CodeManager
	cmd /c rd $(OBJDIR_DEBUG_WIN32)\\Network

.PHONY: before_release_win32 after_release_win32 clean_release_win32 before_debug_win32 after_debug_win32 clean_debug_win32

