#pragma once

#ifndef RAAIDDATAMANAGERDEFS
#define RAAIDDATAMANAGERDEFS

#ifdef raaWINDOWS
#pragma warning( disable : 4251 )
#pragma warning( disable : 4786 )
#pragma warning( disable : 4503 )
#pragma warning( disable : 4565 )
#pragma warning( disable : 4150 )
#pragma warning( disable : 4800 )
#pragma warning( disable : 4244 )
#pragma warning( disable : 4995 )

#ifdef _STATIC_RAAIDDATAMANAGER
#define RAAIDDATAMANAGER_DLL_DEF
#else
#ifdef RAAIDDATAMANAGER_EXPORTS
#define RAAIDDATAMANAGER_DLL_DEF __declspec(dllexport)
#else
#define RAAIDDATAMANAGER_DLL_DEF __declspec(dllimport)
#ifdef _DEBUG
#pragma comment(lib,"raaIDDataManagerD")
#else
#pragma comment(lib,"raaIDDataManagerR")
#endif
#endif 
#endif
#else
#define RAAIDDATAMANAGER_DLL_DEF
#endif
#endif

