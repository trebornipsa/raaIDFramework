#pragma once

#ifndef RAAIDCOREDEFS
#define RAAIDCOREDEFS

#ifdef raaWINDOWS
#pragma warning( disable : 4251 )
#pragma warning( disable : 4786 )
#pragma warning( disable : 4503 )
#pragma warning( disable : 4565 )
#pragma warning( disable : 4150 )
#pragma warning( disable : 4800 )
#pragma warning( disable : 4244 )
#pragma warning( disable : 4995 )

#ifdef _STATIC_RAAIDCORE
#define RAAIDCORE_DLL_DEF
#else
#ifdef RAAIDCORE_EXPORTS
#define RAAIDCORE_DLL_DEF __declspec(dllexport)
#else
#define RAAIDCORE_DLL_DEF __declspec(dllimport)
#ifdef _DEBUG
#pragma comment(lib,"raaIDCoreD")
#else
#pragma comment(lib,"raaIDCoreR")
#endif
#endif 
#endif
#else
#define RAAIDCORE_DLL_DEF
#endif
#endif

