#include "raaClassTemplate.h"

#ifdef RAACLASSTEMPLATE_SINGLETON
unsigned int raaClassTemplate::sm_uiInstance=0;
raaClassTemplate* raaClassTemplate::sm_pInstance=0;

void raaClassTemplate::start()
{
	if(!sm_uiInstance++&&!sm_pInstance) new raaClassTemplate();
}

void raaClassTemplate::stop()
{
	if(!--sm_uiInstance&&sm_pInstance) delete sm_pInstance;
}

raaClassTemplate* raaClassTemplate::instance()
{
	return sm_pInstance;
}
#endif

raaClassTemplate::raaClassTemplate()
{
#ifdef RAACLASSTEMPLATE_SINGLETON
	if(!sm_pInstance) sm_pInstance=this;
#endif
}

raaClassTemplate::~raaClassTemplate()
{
#ifdef RAACLASSTEMPLATE_SINGLETON
	if(sm_pInstance==this) sm_pInstance=0;
#endif
}
