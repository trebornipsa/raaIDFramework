#include "raaIDPluginContainer.h"

#include "raaIDPluginTypeContainer.h"

raaIDPluginTypeContainer::raaIDPluginTypeContainer(std::string sType)
{
	m_sType = sType;
}

raaIDPluginTypeContainer::~raaIDPluginTypeContainer()
{
}

bool raaIDPluginTypeContainer::nameExists(std::string sComntainerName)
{
	if (m_lContainers.find(sComntainerName) != m_lContainers.end()) return true;
	return false;
}

bool raaIDPluginTypeContainer::addContainer(raaIDPluginContainer* pContainer)
{
	if(pContainer && !nameExists(pContainer->name()))
	{
		m_lContainers[pContainer->name()] = pContainer;
		return true;
	}
	return false;
}

raaIDPluginInterface* raaIDPluginTypeContainer::create(std::string sName,QDomDocument& doc)
{
	raaIDPluginInterface *pPlugin = 0;

	if(nameExists(sName)) pPlugin=m_lContainers[sName]->create(doc);

	return pPlugin;
}