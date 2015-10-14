#pragma once

#ifndef $raaProjectNameCaps$DEFS
#define $raaProjectNameCaps$DEFS

#ifdef raaWINDOWS
#pragma warning( disable : 4251 )
#pragma warning( disable : 4786 )
#pragma warning( disable : 4503 )
#pragma warning( disable : 4565 )
#pragma warning( disable : 4150 )
#pragma warning( disable : 4800 )
#pragma warning( disable : 4244 )
#pragma warning( disable : 4995 )

#ifdef _STATIC_$raaProjectNameCaps$
#define $raaProjectNameCaps$_DLL_DEF
#else
#ifdef $raaProjectNameCaps$_EXPORTS
#define $raaProjectNameCaps$_DLL_DEF __declspec(dllexport)
#else
#define $raaProjectNameCaps$_DLL_DEF __declspec(dllimport)
#ifdef _DEBUG
#pragma comment(lib,"$raaProjectName$D")
#else
#pragma comment(lib,"$raaProjectName$R")
#endif
#endif 
#endif
#else
#define $raaProjectNameCaps$_DLL_DEF
#endif
#endif

