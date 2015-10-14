#include <windows.h>

#include <raaUtilities/raaUtilities.h>

#include "raaIDPluginInterface.h"

#include "raaIDPluginContainer.h"
#include "raaIDPluginTypeContainer.h"

#include <QtCore/QFile>
#include <QtCore/QDir>
#include <QtXML/QDomDocument>

#include "raaIDPluginManager.h"

#ifdef RAAIDPLUGINMANAGER_SINGLETON
unsigned int raaIDPluginManager::sm_uiInstance=0;
raaIDPluginManager* raaIDPluginManager::sm_pInstance=0;

void raaIDPluginManager::start()
{
	if(!sm_uiInstance++&&!sm_pInstance) new raaIDPluginManager();
}

void raaIDPluginManager::stop()
{
	if(!--sm_uiInstance&&sm_pInstance) delete sm_pInstance;
}

raaIDPluginManager* raaIDPluginManager::instance()
{
	return sm_pInstance;
}
#endif

raaIDPluginManager::raaIDPluginManager()
{
#ifdef RAAIDPLUGINMANAGER_SINGLETON
	if(!sm_pInstance) sm_pInstance=this;
#endif
}

raaIDPluginManager::~raaIDPluginManager()
{
#ifdef RAAIDPLUGINMANAGER_SINGLETON
	if(sm_pInstance==this) sm_pInstance=0;
#endif
}

void raaIDPluginManager::loadPlugins()
{
	std::string sDir;

	if(raaUtilities::envVarExists(std::string("raaIDPlugins"))) sDir = raaUtilities::envVar(std::string("raaIDPlugins"));
	else sDir= "..\\plugins";

	if (sDir.length())
	{
		QDir dir(sDir.c_str());

		QStringList slFilters;
		slFilters << "*.raaConf";
		QFileInfoList files = dir.entryInfoList(slFilters, QDir::Files | QDir::NoDotAndDotDot | QDir::NoSymLinks, QDir::Name);

		for (QFileInfoList::iterator it = files.begin(); it != files.end();it++)
		{
			if (it->isFile()) loadPlugin(it->absoluteFilePath().toStdString());
		}
	}
}

bool raaIDPluginManager::loadPlugin(std::string sConfig)
{
	std::string sPluginType;
	std::string sPluginName;
	std::string sPluginPath;
	std::string sPluginDLL;

	QDomDocument doc("raaPlugin");
	QFile file(sConfig.c_str());

	if (file.open(QIODevice::ReadOnly))
	{
		if (doc.setContent(&file))
		{
			QDomElement element = doc.documentElement();

			sPluginType = getText(element.firstChildElement("type"));
			sPluginName = getText(element.firstChildElement("name"));
			sPluginPath = getText(element.firstChildElement("path"));
			sPluginDLL = getText(element.firstChildElement("dll"));
		}
		file.close();

		if (sPluginType.length() && sPluginName.length() && sPluginDLL.length())
		{
			std::string sFullPluginPath;

			void* pvLib = raaUtilities::getLibrary(sPluginPath, sPluginDLL);

			if(pvLib)
			{
				std::string sFunction = sPluginDLL + "FactoryCreate";
				constructPluginFactory *constructFunction=(constructPluginFactory*)raaUtilities::getLibraryFunction(pvLib, sFunction);

				if(constructFunction)
				{
					raaIDPluginTypeContainer *pTypeContainer = 0;
					if(m_mTypeContainers.find(sPluginType)!=m_mTypeContainers.end())
					{
						pTypeContainer = m_mTypeContainers[sPluginType];
					}
					else
					{
						pTypeContainer = new raaIDPluginTypeContainer(sPluginType);
						m_mTypeContainers[sPluginType] = pTypeContainer;
					}

					if (!pTypeContainer->nameExists(sPluginName))
					{
						pTypeContainer->addContainer(new raaIDPluginContainer(sPluginName, pvLib, constructFunction()));

						return true;
					}
				}
			}

		}
	}
	return false;
}

raaIDPluginInterface* raaIDPluginManager::create(std::string sType,std::string sName,std::string sConfigFile)
{
	raaIDPluginInterface *pPlugin = 0;

	if(sType.length() && sName.length())
	{
		if(m_mTypeContainers.find(sType)!=m_mTypeContainers.end())
		{
			if (m_mTypeContainers[sType]->nameExists(sName))
			{

				QDomDocument doc("raaPluginConfig");
				QFile file(sConfigFile.c_str());

				if (file.open(QIODevice::ReadOnly))
				{
					doc.setContent(&file);
					file.close();
				}

				pPlugin = m_mTypeContainers[sType]->create(sName, doc);
			}
		}
	}

	return pPlugin;
}

raaIDPluginInterface* raaIDPluginManager::create(std::string sName,std::string sConfigFile)
{
	raaIDPluginInterface *pPlugin = 0;
	raaIDPluginTypeContainer *pTypeContainer = 0;

	if (sName.length())
	{
		for (raaIDPluginTypeContainers::iterator it = m_mTypeContainers.begin(); it != m_mTypeContainers.end(); it++)
		{
			if(it->second->nameExists(sName))
			{
				pTypeContainer = it->second;
				break;
			}
		}

		if (pTypeContainer)
		{
			QDomDocument doc("raaPluginConfig");
			QFile file(sConfigFile.c_str());

			if (file.open(QIODevice::ReadOnly))
			{
				doc.setContent(&file);
				file.close();
			}

			pPlugin = pTypeContainer->create(sName, doc);
		}
	}
	return pPlugin;
}

std::string raaIDPluginManager::getText(QDomNode& node)
{
	std::string sText;

	if (!node.isNull() && node.isElement())
	{
		QDomElement element = node.toElement();
		sText = element.text().toStdString();
	}

	return sText;
}