#pragma once

#include "raaIDCoreDefs.h"

#define RAAIDCORE_SINGLETON
#define RAAIDCORE_NO_PLUGIN

class RAAIDCORE_DLL_DEF raaIDCore
{
#ifdef RAAIDCORE_SINGLETON
private:
	static unsigned int sm_uiInstance;
	static raaIDCore* sm_pInstance;
	
public:
	static void start();
	static void stop();
	static raaIDCore* instance();

protected:
#else
public:
#endif
	raaIDCore();
	virtual ~raaIDCore();
};

#ifdef RAAIDCORE_PLUGIN
#ifdef RAAIDCORE_SINGLETON
extern "C" RAAIDCORE_DLL_DEF void* raaIDCoreCreate() {raaIDCore::start(); return (void*)raaIDCore::instance();};
#else
extern "C" RAAIDCORE_DLL_DEF void* raaIDCoreCreate() {return new raaIDCore();};
#endif
#endif