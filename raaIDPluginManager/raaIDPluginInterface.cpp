#include "raaIDPluginContainer.h"

#include "raaIDPluginInterface.h"

raaIDPluginInterface::raaIDPluginInterface()
{
	m_pContainer = 0;
	m_pTypeContainer = 0;
}

void raaIDPluginInterface::release()
{
	finalise();

	if(m_pContainer) m_pContainer->release(this);
}

raaIDPluginContainer* raaIDPluginInterface::container()
{
	return m_pContainer;
}

raaIDPluginTypeContainer* raaIDPluginInterface::type()
{
	return m_pTypeContainer;
}

raaIDPluginInterface::~raaIDPluginInterface()
{
}

void raaIDPluginInterface::setContainers(raaIDPluginTypeContainer* pTypeContainer,raaIDPluginContainer* pContainer)
{
	m_pTypeContainer = pTypeContainer;
	m_pContainer = pContainer;
}

raaIDPluginFactory::raaIDPluginFactory()
{
	
}

raaIDPluginFactory::~raaIDPluginFactory()
{
	
}