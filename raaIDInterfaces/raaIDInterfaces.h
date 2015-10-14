#pragma once

#include "raaIDInterfacesDefs.h"

#define RAAIDINTERFACES_SINGLETON
#define RAAIDINTERFACES_NO_PLUGIN

class RAAIDINTERFACES_DLL_DEF raaIDInterfaces
{
#ifdef RAAIDINTERFACES_SINGLETON
private:
	static unsigned int sm_uiInstance;
	static raaIDInterfaces* sm_pInstance;
	
public:
	static void start();
	static void stop();
	static raaIDInterfaces* instance();

protected:
#else
public:
#endif
	raaIDInterfaces();
	virtual ~raaIDInterfaces();
};

#ifdef RAAIDINTERFACES_PLUGIN
#ifdef RAAIDINTERFACES_SINGLETON
extern "C" RAAIDINTERFACES_DLL_DEF void* raaIDInterfacesCreate() {raaIDInterfaces::start(); return (void*)raaIDInterfaces::instance();};
#else
extern "C" RAAIDINTERFACES_DLL_DEF void* raaIDInterfacesCreate() {return new raaIDInterfaces();};
#endif
#endif