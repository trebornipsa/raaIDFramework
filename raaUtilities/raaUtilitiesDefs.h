#ifndef RAAUTILITIESDEFS
#define RAAUTILITIESDEFS

#ifdef WIN32
#pragma warning( disable : 4251 )
#pragma warning( disable : 4786 )
#pragma warning( disable : 4503 )
#pragma warning( disable : 4565 )
#pragma warning( disable : 4150 )
#pragma warning( disable : 4800 )
#pragma warning( disable : 4244 )
#pragma warning( disable : 4995 )

#ifdef _STATIC_RAAUTILITIES
#define RAAUTILITIES_DLL_DEF
#else
#ifdef RAAUTILITIES_EXPORTS
#define RAAUTILITIES_DLL_DEF __declspec(dllexport)
#else
#define RAAUTILITIES_DLL_DEF __declspec(dllimport)
#ifdef _DEBUG
#pragma comment(lib,"raaUtilitiesD")
#else
#pragma comment(lib,"raaUtilitiesR")
#endif
#endif 
#endif
#else
#define RAAUTILITIES_DLL_DEF
#endif

#endif