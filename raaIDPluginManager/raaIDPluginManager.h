#pragma once

#include <string>
#include <map>

#include <QtXML/QDomNode>


#include "raaIDPluginManagerDefs.h"

#define RAAIDPLUGINMANAGER_SINGLETON
#define RAAIDPLUGINMANAGER_NO_PLUGIN

class raaIDPluginInterface;
class raaIDPluginTypeContainer;

typedef std::map<std::string, raaIDPluginTypeContainer*> raaIDPluginTypeContainers;

class RAAIDPLUGINMANAGER_DLL_DEF raaIDPluginManager
{
#ifdef RAAIDPLUGINMANAGER_SINGLETON
private:
	static unsigned int sm_uiInstance;
	static raaIDPluginManager* sm_pInstance;
	
public:
	static void start();
	static void stop();
	static raaIDPluginManager* instance();

protected:
#else
public:
#endif
	raaIDPluginManager();
	virtual ~raaIDPluginManager();
public:

	void loadPlugins();
	bool loadPlugin(std::string sConfig);


	raaIDPluginInterface* create(std::string sType, std::string sName, std::string sConfigFile);
	raaIDPluginInterface* create(std::string sName, std::string sConfigFile);

	template <class T> T* createPlugin(std::string sType, std::string sName, std::string sConfigFile);
	template <class T> T* createPlugin(std::string sName, std::string sConfigFile);

protected:
	std::string getText(QDomNode &node);

	raaIDPluginTypeContainers m_mTypeContainers;

};

#ifdef RAAIDPLUGINMANAGER_PLUGIN
#ifdef RAAIDPLUGINMANAGER_SINGLETON
extern "C" RAAIDPLUGINMANAGER_DLL_DEF void* raaIDPluginManagerCreate() {raaIDPluginManager::start(); return (void*)raaIDPluginManager::instance();};
#else
extern "C" RAAIDPLUGINMANAGER_DLL_DEF void* raaIDPluginManagerCreate() {return new raaIDPluginManager();};
#endif
#endif