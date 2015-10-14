#include "$raaProjectName$.h"

#ifdef $raaProjectNameCaps$_SINGLETON
unsigned int $raaProjectName$::sm_uiInstance=0;
$raaProjectName$* $raaProjectName$::sm_pInstance=0;

void $raaProjectName$::start()
{
	if(!sm_uiInstance++&&!sm_pInstance) new $raaProjectName$();
}

void $raaProjectName$::stop()
{
	if(!--sm_uiInstance&&sm_pInstance) delete sm_pInstance;
}

$raaProjectName$* $raaProjectName$::instance()
{
	return sm_pInstance;
}
#endif

$raaProjectName$::$raaProjectName$()
{
#ifdef $raaProjectNameCaps$_SINGLETON
	if(!sm_pInstance) sm_pInstance=this;
#endif
}

$raaProjectName$::~$raaProjectName$()
{
#ifdef $raaProjectNameCaps$_SINGLETON
	if(sm_pInstance==this) sm_pInstance=0;
#endif
}
