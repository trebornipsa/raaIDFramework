#pragma once

#ifndef RAADLLTEMPLATEDEFS
#define RAADLLTEMPLATEDEFS

#ifdef WIN32
#pragma warning( disable : 4251 )
#pragma warning( disable : 4786 )
#pragma warning( disable : 4503 )
#pragma warning( disable : 4565 )
#pragma warning( disable : 4150 )
#pragma warning( disable : 4800 )
#pragma warning( disable : 4244 )
#pragma warning( disable : 4995 )

#ifdef _STATIC_RAADLLTEMPLATE
#define RAADLLTEMPLATE_DLL_DEF
#else
#ifdef RAADLLTEMPLATE_EXPORTS
#define RAADLLTEMPLATE_DLL_DEF __declspec(dllexport)
#else
#define RAADLLTEMPLATE_DLL_DEF __declspec(dllimport)
#ifdef _DEBUG
#pragma comment(lib,"raaDLLTemplateD")
#else
#pragma comment(lib,"raaDLLTemplateR")
#endif
#endif 
#endif
#else
#define RAADLLTEMPLATE_DLL_DEF
#endif

