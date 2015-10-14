#include "raaTestPlugin.h"

#ifdef RAATESTPLUGIN_SINGLETON
unsigned int raaTestPlugin::sm_uiInstance=0;
raaTestPlugin* raaTestPlugin::sm_pInstance=0;

void raaTestPlugin::initialise(QDomDocument& doc)
{
}

void raaTestPlugin::finalise()
{
}

void raaTestPlugin::start()
{
	if(!sm_uiInstance++&&!sm_pInstance) new raaTestPlugin();
}

void raaTestPlugin::stop()
{
	if(!--sm_uiInstance&&sm_pInstance) delete sm_pInstance;
}

raaTestPlugin* raaTestPlugin::instance()
{
	return sm_pInstance;
}
#endif

void raaTestPlugin::initialise(QDomDocument& doc)
{
}

void raaTestPlugin::finalise()
{
}

raaTestPlugin::raaTestPlugin()
{
#ifdef RAATESTPLUGIN_SINGLETON
	if(!sm_pInstance) sm_pInstance=this;
#endif
}

raaTestPlugin::~raaTestPlugin()
{
#ifdef RAATESTPLUGIN_SINGLETON
	if(sm_pInstance==this) sm_pInstance=0;
#endif
}

raaTestPluginFactory::raaTestPluginFactory()
{
}

raaTestPluginFactory::~raaTestPluginFactory()
{
}

raaIDPluginInterface* raaTestPluginFactory::create()
{
	return new raaTestPlugin();
}