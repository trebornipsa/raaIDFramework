#pragma once

#include <map>

#include "raaIDPluginManagerDefs.h"

class raaIDPluginContainer;

typedef std::map<std::string, raaIDPluginContainer*> raaIDPluginContainers;

class RAAIDPLUGINMANAGER_DLL_DEF raaIDPluginTypeContainer
{
public:
	raaIDPluginTypeContainer(std::string sType);
	virtual ~raaIDPluginTypeContainer();

	bool nameExists(std::string sComntainerName);

	bool addContainer(raaIDPluginContainer *pContainer);

	raaIDPluginInterface* create(std::string sName, QDomDocument &doc);

private:
	std::string m_sType;
	raaIDPluginContainers m_lContainers;
};

