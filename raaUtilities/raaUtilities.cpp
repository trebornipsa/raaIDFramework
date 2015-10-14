#include <windows.h>
#include <mmsystem.h>

#include <iostream>

#include "raaUtilities.h"

const float raaUtilities::csm_fPI=3.14159265f;

raaUtilities::raaUtilities(void)
{
}

raaUtilities::~raaUtilities(void)
{
}

std::string raaUtilities::envVar(std::string sName)
{
	char c[1024];
	int iBufSize=0;

	if(iBufSize=GetEnvironmentVariableA(sName.c_str(), c, 1024))
	{
		for(int i=0;i<iBufSize;i++)if(c[i]=='\\') c[i]='/';
		c[iBufSize]='\0';
		return std::string(c);
	}
	return std::string("");
}

void raaUtilities::setEnvVar(std::string sName, std::string sData)
{
	SetEnvironmentVariableA(sName.c_str(), sData.c_str());
}

bool raaUtilities::envVarExists(std::string sName)
{
	char c[1024];

	if(GetEnvironmentVariableA(sName.c_str(), c, 1024))
	{
		return true;
	}

	return false;
}

float raaUtilities::deg2rad(float f)
{
	return (f/180.0f)*csm_fPI;
}

float raaUtilities::rad2deg(float f)
{
	return (f/csm_fPI)*180.0f;
}

void raaUtilities::regWriteEntry(std::string sKey, std::string sEntry, std::string sStr)
{
	HKEY hKey;
	DWORD dw;

	std::string s;
	s=sStr;

	for(std::string::iterator it=s.begin();it!=s.end();it++) if((*it)=='/') (*it)='\\';
	s.append("\\");


	RegCreateKeyExA(HKEY_LOCAL_MACHINE, sKey.c_str(), 0, NULL, 0, 0, NULL, &hKey, &dw);

	if(hKey) RegCloseKey(hKey);
	hKey=0;

	RegOpenKeyExA(HKEY_LOCAL_MACHINE, sKey.c_str(),0,KEY_ALL_ACCESS,&hKey);

	if(hKey)
	{
		RegSetValueExA(hKey, sEntry.c_str(),0,REG_SZ,(CONST BYTE*)(s.c_str()), sizeof(const char)*(s.length())); 	
		RegCloseKey(hKey);
	}
}

void raaUtilities::regDeleteEntry(std::string sKey)
{
	std::string sTarget, sEntry;

	int i=0;
	if(sKey.find('\\')!=sKey.length())
	{
		i=sKey.find_last_of('\\');
		sTarget=sKey.substr(0, i);
		sEntry=sKey.substr(i+1, 0);
	}
	else
	{
		sEntry=sKey;
		sTarget="";
	}

	HKEY hKey;

	if(RegOpenKeyEx(HKEY_LOCAL_MACHINE, ansiToUnicode(sTarget),0,KEY_ALL_ACCESS,&hKey)==ERROR_SUCCESS)
	{
		RegDeleteKey(hKey, ansiToUnicode(sEntry));
		RegCloseKey(hKey);
	}
}

std::string raaUtilities::regReadEntry(std::string sKey, std::string sEntry)
{
	std::string sStr;
	HKEY hKey;
	DWORD dwType=REG_SZ, dwSize=8192*sizeof(char);

	if(RegOpenKeyExA(HKEY_LOCAL_MACHINE, sKey.c_str(),0,KEY_ALL_ACCESS,&hKey)==ERROR_SUCCESS)
	{
		if(hKey)
		{
			char c[8192];
			int i=RegQueryValueExA(hKey, sEntry.c_str(), 0, &dwType, (PBYTE)c, &dwSize);

			
			RegCloseKey(hKey);
			
			if(!i)
			{
				sStr=c;
			}
		}
	}
	return sStr;
}

bool raaUtilities::regExists(std::string sKey)
{
	HKEY hKey;
	DWORD dwType=REG_SZ, dwSize=1024*sizeof(char);

	if(RegOpenKeyEx(HKEY_LOCAL_MACHINE, ansiToUnicode(sKey),0,KEY_READ,&hKey)==ERROR_SUCCESS)
	{
		if(hKey) RegCloseKey(hKey);

		return true;
	}
	return false;	
}

BSTR raaUtilities::ansiToUnicode(std::string s)
{
	BSTR unicodestr=0;

	int iLen = ::MultiByteToWideChar(CP_ACP, 0, s.c_str(), s.length(), 0, 0);
	if (iLen > 0)
	{
		// Check whether conversion was successful
		unicodestr = ::SysAllocStringLen(0, iLen);
		::MultiByteToWideChar(CP_ACP, 0, s.c_str(), s.length(), unicodestr, iLen);
	}

	return unicodestr;
//	::SysFreeString(unicodestr);
}

std::string raaUtilities::unicodeToAnsi(BSTR s)
{
	std::string str;

	int lenA = ::WideCharToMultiByte(CP_ACP, 0, s, ::SysStringLen(s), 0, 0, NULL, NULL);
	if (lenA > 0)
	{
		char *c=(char*)_alloca(sizeof(char)+1);
		::WideCharToMultiByte(CP_ACP, 0, s, ::SysStringLen(s), c, lenA, NULL, NULL);
		c[lenA] = 0; // Set the null terminator yourself
		str=c;
	}
	return str;
}

void raaUtilities::freeUnicode(BSTR s)
{
	::SysFreeString(s);
}

void* raaUtilities::getLibrary(std::string sPath, std::string sName)
{
	std::string sFullName;
	if(sPath.length()) sFullName = sPath + "\\" + sName;
	else sFullName = sName;

#ifdef _DEBUG
	sFullName += "D.dll";
#else
	sFullName += "R.dll";
#endif

	return ::LoadLibrary(ansiToUnicode(sFullName));
}

void* raaUtilities::getLibraryFunction(void* pvLib,std::string sFunctionName)
{
	if(pvLib && sFunctionName.length())
	{
		return ::GetProcAddress((HMODULE)pvLib, sFunctionName.c_str());
	}
	return 0;
}

raaTime raaUtilities::time()
{
	return timeGetTime();
}
