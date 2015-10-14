#include "raaIDInterfaces.h"

#ifdef RAAIDINTERFACES_SINGLETON
unsigned int raaIDInterfaces::sm_uiInstance=0;
raaIDInterfaces* raaIDInterfaces::sm_pInstance=0;

void raaIDInterfaces::start()
{
	if(!sm_uiInstance++&&!sm_pInstance) new raaIDInterfaces();
}

void raaIDInterfaces::stop()
{
	if(!--sm_uiInstance&&sm_pInstance) delete sm_pInstance;
}

raaIDInterfaces* raaIDInterfaces::instance()
{
	return sm_pInstance;
}
#endif

raaIDInterfaces::raaIDInterfaces()
{
#ifdef RAAIDINTERFACES_SINGLETON
	if(!sm_pInstance) sm_pInstance=this;
#endif
}

raaIDInterfaces::~raaIDInterfaces()
{
#ifdef RAAIDINTERFACES_SINGLETON
	if(sm_pInstance==this) sm_pInstance=0;
#endif
}
