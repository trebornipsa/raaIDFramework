#pragma once

#include "raaClassTemplateDefs.h"

#define RAACLASSTEMPLATE_NO_SINGLETON
#define RAACLASSTEMPLATE_NO_PLUGIN

class RAACLASSTEMPLATE_DLL_DEF $rootnamespace$
{
#ifdef RAACLASSTEMPLATE_SINGLETON
private:
	static unsigned int sm_uiInstance;
	static $rootnamespace$* sm_pInstance;
	
public:
	static void start();
	static void stop();
	static $rootnamespace$* instance();

protected:
#else
public:
#endif
	$rootnamespace$();
	virtual ~$rootnamespace$();
};

#ifdef RAACLASSTEMPLATE_PLUGIN
#ifdef RAACLASSTEMPLATE_SINGLETON
extern "C" RAACLASSTEMPLATE_DLL_DEF void* raaClassTemplateCreate() {$rootnamespace$::start(); return (void*)$rootnamespace$::instance();};
#else
extern "C" RAACLASSTEMPLATE_DLL_DEF void* raaClassTemplateCreate() {return new $rootnamespace$();};
#endif
#endif