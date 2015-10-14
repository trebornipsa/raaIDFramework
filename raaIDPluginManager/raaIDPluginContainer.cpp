#include "raaIDPluginInterface.h"
#include "raaIDPluginContainer.h"

raaIDPluginContainer::raaIDPluginContainer(std::string sName, void* pvLib, raaIDPluginFactory *pFactory)
{
	m_sName = sName;
	m_pvLib = pvLib;
	m_pFactory = pFactory;
}


raaIDPluginContainer::~raaIDPluginContainer()
{
}

std::string raaIDPluginContainer::name()
{
	return m_sName;
}

raaIDPluginInterface* raaIDPluginContainer::create(QDomDocument& doc)
{
	raaIDPluginInterface *pPlugin = 0;
	if(m_pFactory)
	{
		pPlugin=m_pFactory->create();
		if (pPlugin)
		{
			pPlugin->ref();
			m_lPlugins.push_back(pPlugin);
			pPlugin->initialise(doc);
		}
	}

	return pPlugin;
}

void raaIDPluginContainer::release(raaIDPluginInterface* pPlugin)
{
	if(pPlugin && std::find(m_lPlugins.begin(), m_lPlugins.end(), pPlugin)!=m_lPlugins.end())
	{
		pPlugin->finalise();
		m_lPlugins.remove(pPlugin);
		pPlugin->unref();
	}
}

unsigned int raaIDPluginContainer::numInstances()
{
	return (unsigned int)m_lPlugins.size();
}