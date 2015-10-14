#include "raaMutex.h"

raaMutex::raaMutex(void)
{
	m_hMutex=CreateMutex(0,false,0);
}

raaMutex::~raaMutex(void)
{
	if(m_hMutex) CloseHandle(m_hMutex);	
}

bool raaMutex::lock()
{
	if(m_hMutex && WaitForSingleObject(m_hMutex, INFINITE)==WAIT_OBJECT_0) return true; return false;
}

bool raaMutex::lock(unsigned int uiWait)
{
	if(m_hMutex && WaitForSingleObject(m_hMutex, (DWORD)uiWait)==WAIT_OBJECT_0) return true; return false;
}

void raaMutex::unlock()
{
	if(m_hMutex) ReleaseMutex(m_hMutex);
}
