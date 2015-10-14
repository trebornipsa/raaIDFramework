#pragma once

#include <QtXml/QDomDocument>

#include <raaIDCore/raaIDBase.h>

#include "raaIDPluginManagerDefs.h"

class raaIDPluginContainer;
class raaIDPluginTypeContainer;
class raaIDPluginManager;

class RAAIDPLUGINMANAGER_DLL_DEF raaIDPluginInterface : public raaIDBase
{
	friend raaIDPluginManager;
	friend raaIDPluginContainer;
public:
	raaIDPluginInterface();

	virtual void initialise(QDomDocument &doc) = 0;
	void release();

	raaIDPluginContainer* container();
	raaIDPluginTypeContainer* type();

protected:
	~raaIDPluginInterface();
	virtual void finalise() = 0;

private:
	void setContainers(raaIDPluginTypeContainer *pTypeContainer, raaIDPluginContainer *pContainer);

	raaIDPluginContainer *m_pContainer;
	raaIDPluginTypeContainer *m_pTypeContainer;
};

class RAAIDPLUGINMANAGER_DLL_DEF raaIDPluginFactory
{
public:
	raaIDPluginFactory();
	virtual ~raaIDPluginFactory();

	virtual raaIDPluginInterface* create() = 0;
};

typedef raaIDPluginFactory* (constructPluginFactory)();

// example of required plugin constructor 
// extern "C" RAAIDPLUGINMANAGER_DLL_DEF raaIDPluginFactory* raaIDPluginFactoryCreate() {return new raaIDPluginFactory();};


