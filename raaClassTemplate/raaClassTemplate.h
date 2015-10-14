#pragma once

#include "raaClassTemplateDefs.h"

#define RAACLASSTEMPLATE_NO_SINGLETON
#define RAACLASSTEMPLATE_NO_PLUGIN

class RAACLASSTEMPLATE_DLL_DEF raaClassTemplate
{
#ifdef RAACLASSTEMPLATE_SINGLETON
private:
	static unsigned int sm_uiInstance;
	static raaClassTemplate* sm_pInstance;
	
public:
	static void start();
	static void stop();
	static raaClassTemplate* instance();

protected:
#else
public:
#endif
	raaClassTemplate();
	virtual ~raaClassTemplate();
};

#ifdef RAACLASSTEMPLATE_PLUGIN
#ifdef RAACLASSTEMPLATE_SINGLETON
extern "C" RAACLASSTEMPLATE_DLL_DEF void* raaClassTemplateCreate() {raaClassTemplate::start(); return (void*)raaClassTemplate::instance();};
#else
extern "C" RAACLASSTEMPLATE_DLL_DEF void* raaClassTemplateCreate() {return new raaClassTemplate();};
#endif
#endif