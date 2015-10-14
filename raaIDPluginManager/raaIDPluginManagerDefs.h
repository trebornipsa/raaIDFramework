#pragma once

#ifndef RAAIDPLUGINMANAGERDEFS
#define RAAIDPLUGINMANAGERDEFS

#ifdef raaWINDOWS
#pragma warning( disable : 4251 )
#pragma warning( disable : 4786 )
#pragma warning( disable : 4503 )
#pragma warning( disable : 4565 )
#pragma warning( disable : 4150 )
#pragma warning( disable : 4800 )
#pragma warning( disable : 4244 )
#pragma warning( disable : 4995 )

#ifdef _STATIC_RAAIDPLUGINMANAGER
#define RAAIDPLUGINMANAGER_DLL_DEF
#else
#ifdef RAAIDPLUGINMANAGER_EXPORTS
#define RAAIDPLUGINMANAGER_DLL_DEF __declspec(dllexport)
#else
#define RAAIDPLUGINMANAGER_DLL_DEF __declspec(dllimport)
#ifdef _DEBUG
#pragma comment(lib,"raaIDPluginManagerD")
#else
#pragma comment(lib,"raaIDPluginManagerR")
#endif
#endif 
#endif
#else
#define RAAIDPLUGINMANAGER_DLL_DEF
#endif
#endif

