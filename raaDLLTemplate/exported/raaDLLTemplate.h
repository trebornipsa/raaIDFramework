#pragma once

#include "$raaProjectName$Defs.h"

#define $raaSingleton$
#define $raaPlugin$

class $raaProjectNameCaps$_DLL_DEF $raaProjectName$
{
#ifdef $raaProjectNameCaps$_SINGLETON
private:
	static unsigned int sm_uiInstance;
	static $raaProjectName$* sm_pInstance;
	
public:
	static void start();
	static void stop();
	static $raaProjectName$* instance();

protected:
#else
public:
#endif
	$raaProjectName$();
	virtual ~$raaProjectName$();
};

#ifdef $raaProjectNameCaps$_PLUGIN
#ifdef $raaProjectNameCaps$_SINGLETON
extern "C" $raaProjectNameCaps$_DLL_DEF void* $raaProjectName$Create() {$raaProjectName$::start(); return (void*)$raaProjectName$::instance();};
#else
extern "C" $raaProjectNameCaps$_DLL_DEF void* $raaProjectName$Create() {return new $raaProjectName$();};
#endif
#endif