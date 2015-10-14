#pragma once

#ifndef RAAIDINTERFACESDEFS
#define RAAIDINTERFACESDEFS

#ifdef raaWINDOWS
#pragma warning( disable : 4251 )
#pragma warning( disable : 4786 )
#pragma warning( disable : 4503 )
#pragma warning( disable : 4565 )
#pragma warning( disable : 4150 )
#pragma warning( disable : 4800 )
#pragma warning( disable : 4244 )
#pragma warning( disable : 4995 )

#ifdef _STATIC_RAAIDINTERFACES
#define RAAIDINTERFACES_DLL_DEF
#else
#ifdef RAAIDINTERFACES_EXPORTS
#define RAAIDINTERFACES_DLL_DEF __declspec(dllexport)
#else
#define RAAIDINTERFACES_DLL_DEF __declspec(dllimport)
#ifdef _DEBUG
#pragma comment(lib,"raaIDInterfacesD")
#else
#pragma comment(lib,"raaIDInterfacesR")
#endif
#endif 
#endif
#else
#define RAAIDINTERFACES_DLL_DEF
#endif
#endif

