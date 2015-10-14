#include "raaIDDataManager.h"

#ifdef RAAIDDATAMANAGER_SINGLETON
unsigned int raaIDDataManager::sm_uiInstance=0;
raaIDDataManager* raaIDDataManager::sm_pInstance=0;

void raaIDDataManager::start()
{
	if(!sm_uiInstance++&&!sm_pInstance) new raaIDDataManager();
}

void raaIDDataManager::stop()
{
	if(!--sm_uiInstance&&sm_pInstance) delete sm_pInstance;
}

raaIDDataManager* raaIDDataManager::instance()
{
	return sm_pInstance;
}
#endif

raaIDDataManager::raaIDDataManager()
{
#ifdef RAAIDDATAMANAGER_SINGLETON
	if(!sm_pInstance) sm_pInstance=this;
#endif
}

raaIDDataManager::~raaIDDataManager()
{
#ifdef RAAIDDATAMANAGER_SINGLETON
	if(sm_pInstance==this) sm_pInstance=0;
#endif
}
