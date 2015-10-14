#pragma once

#ifndef RAACLASSTEMPLATEDEFS
#define RAACLASSTEMPLATEDEFS

#ifdef raaWINDOWS
#pragma warning( disable : 4251 )
#pragma warning( disable : 4786 )
#pragma warning( disable : 4503 )
#pragma warning( disable : 4565 )
#pragma warning( disable : 4150 )
#pragma warning( disable : 4800 )
#pragma warning( disable : 4244 )
#pragma warning( disable : 4995 )

#ifdef _STATIC_RAACLASSTEMPLATE
#define RAACLASSTEMPLATE_DLL_DEF
#else
#ifdef RAACLASSTEMPLATE_EXPORTS
#define RAACLASSTEMPLATE_DLL_DEF __declspec(dllexport)
#else
#define RAACLASSTEMPLATE_DLL_DEF __declspec(dllimport)
#ifdef _DEBUG
#pragma comment(lib,"raaClassTemplateD")
#else
#pragma comment(lib,"raaClassTemplateR")
#endif
#endif 
#endif
#else
#define RAACLASSTEMPLATE_DLL_DEF
#endif
#endif

