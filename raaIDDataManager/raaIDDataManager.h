#pragma once

#include "raaIDDataManagerDefs.h"

#define RAAIDDATAMANAGER_SINGLETON
#define RAAIDDATAMANAGER_NO_PLUGIN

class RAAIDDATAMANAGER_DLL_DEF raaIDDataManager
{
#ifdef RAAIDDATAMANAGER_SINGLETON
private:
	static unsigned int sm_uiInstance;
	static raaIDDataManager* sm_pInstance;
	
public:
	static void start();
	static void stop();
	static raaIDDataManager* instance();

protected:
#else
public:
#endif
	raaIDDataManager();
	virtual ~raaIDDataManager();
};

#ifdef RAAIDDATAMANAGER_PLUGIN
#ifdef RAAIDDATAMANAGER_SINGLETON
extern "C" RAAIDDATAMANAGER_DLL_DEF void* raaIDDataManagerCreate() {raaIDDataManager::start(); return (void*)raaIDDataManager::instance();};
#else
extern "C" RAAIDDATAMANAGER_DLL_DEF void* raaIDDataManagerCreate() {return new raaIDDataManager();};
#endif
#endif