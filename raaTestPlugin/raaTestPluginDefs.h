#pragma once

#ifndef RAATESTPLUGINDEFS
#define RAATESTPLUGINDEFS

#ifdef raaWINDOWS
#pragma warning( disable : 4251 )
#pragma warning( disable : 4786 )
#pragma warning( disable : 4503 )
#pragma warning( disable : 4565 )
#pragma warning( disable : 4150 )
#pragma warning( disable : 4800 )
#pragma warning( disable : 4244 )
#pragma warning( disable : 4995 )

#ifdef _STATIC_RAATESTPLUGIN
#define RAATESTPLUGIN_DLL_DEF
#else
#ifdef RAATESTPLUGIN_EXPORTS
#define RAATESTPLUGIN_DLL_DEF __declspec(dllexport)
#else
#define RAATESTPLUGIN_DLL_DEF __declspec(dllimport)
#ifdef _DEBUG
#pragma comment(lib,"raaTestPluginD")
#else
#pragma comment(lib,"raaTestPluginR")
#endif
#endif 
#endif
#else
#define RAATESTPLUGIN_DLL_DEF
#endif
#endif

