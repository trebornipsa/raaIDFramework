#pragma once

#include <QtXml/QDomDocument>

#include <raaIDPluginManager/raaIDPluginInterface.h>

#include "raaTestPluginDefs.h"

#define RAATESTPLUGIN_NO_SINGLETON
#define RAATESTPLUGIN_PLUGIN

class raaTestPluginFactory;

class RAATESTPLUGIN_DLL_DEF raaTestPlugin: public raaIDPluginInterface
{
	friend raaTestPluginFactory;
public:
	void initialise(QDomDocument& doc) override;
protected:
	void finalise() override;
private:

#ifdef RAATESTPLUGIN_SINGLETON
private:
	static unsigned int sm_uiInstance;
	static raaTestPlugin* sm_pInstance;
	
public:
	static void start();
	static void stop();
	static raaTestPlugin* instance();

protected:
#else
public:
#endif
	raaTestPlugin();
	virtual ~raaTestPlugin();
};

class RAATESTPLUGIN_DLL_DEF raaTestPluginFactory : public raaIDPluginFactory
{
public:
	raaTestPluginFactory();
	virtual ~raaTestPluginFactory();

	virtual raaIDPluginInterface* create();
};


#ifdef RAATESTPLUGIN_PLUGIN
#ifdef RAATESTPLUGIN_SINGLETON
extern "C" RAATESTPLUGIN_DLL_DEF void* raaTestPluginCreate() {raaTestPlugin::start(); return (void*)raaTestPlugin::instance();};
#else
extern "C" RAATESTPLUGIN_DLL_DEF void* raaTestPluginFactoryCreate() {return new raaTestPlugin();};
#endif
#endif