#include "raaIDCore.h"

#ifdef RAAIDCORE_SINGLETON
unsigned int raaIDCore::sm_uiInstance=0;
raaIDCore* raaIDCore::sm_pInstance=0;

void raaIDCore::start()
{
	if(!sm_uiInstance++&&!sm_pInstance) new raaIDCore();
}

void raaIDCore::stop()
{
	if(!--sm_uiInstance&&sm_pInstance) delete sm_pInstance;
}

raaIDCore* raaIDCore::instance()
{
	return sm_pInstance;
}
#endif

raaIDCore::raaIDCore()
{
#ifdef RAAIDCORE_SINGLETON
	if(!sm_pInstance) sm_pInstance=this;
#endif
}

raaIDCore::~raaIDCore()
{
#ifdef RAAIDCORE_SINGLETON
	if(sm_pInstance==this) sm_pInstance=0;
#endif
}
