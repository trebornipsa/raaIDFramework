#pragma once

#include <list>

#include <QtXml/QDomDocument>

#include <string>
#include "raaIDPluginManagerDefs.h"

class raaIDPluginFactory;
class raaIDPluginInterface;

typedef std::list<raaIDPluginInterface*> raaIDPlugins;

class RAAIDPLUGINMANAGER_DLL_DEF raaIDPluginContainer
{
public:
	raaIDPluginContainer(std::string sName, void* pvLib, raaIDPluginFactory *pFactory);
	virtual ~raaIDPluginContainer();

	std::string name();

	raaIDPluginInterface* create(QDomDocument &doc);
	void release(raaIDPluginInterface *pPlugin);

	template<class T> T* createPlugin(QDomDocument& doc) {return (T*)create(doc);}

	unsigned int numInstances();

private:
	std::string m_sName;
	void* m_pvLib;
	raaIDPluginFactory *m_pFactory;

	raaIDPlugins m_lPlugins;
};

