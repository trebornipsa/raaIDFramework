#pragma once

#include "windows.h"

#include <string>

#include "raaUtilitiesDefs.h"

typedef HANDLE raaThreadHandle;
typedef HANDLE raaMutexHandle;
typedef unsigned int raaThreadProcessor;
typedef DWORD raaThreadID;
typedef DWORD raaTime;

class RAAUTILITIES_DLL_DEF raaUtilities
{
public:
	raaUtilities(void);
	virtual ~raaUtilities(void);

	const static float csm_fPI;
	
	static std::string envVar(std::string sName);
	static void setEnvVar(std::string sName, std::string sData);
	static bool envVarExists(std::string sName);

	static bool regExists(std::string sKey);
	static void regWriteEntry(std::string sKey, std::string sEntry, std::string sStr);
	static void regDeleteEntry(std::string sKey);
	static std::string regReadEntry(std::string sKey, std::string sEntry);

	static float deg2rad(float f);
	static float rad2deg(float f);

	static BSTR ansiToUnicode(std::string s);
	static std::string unicodeToAnsi(BSTR s);
	static void freeUnicode(BSTR s);

	static void* getLibrary(std::string sPath, std::string sName);
	static void* getLibraryFunction(void* pvLib, std::string sFunctionName);


	static raaTime time();
};
