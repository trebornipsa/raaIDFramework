#include "raaThread.h"

raaThread::raaThread(void)
{
	m_Handle=0;
}

raaThread::~raaThread(void)
{
	end();
}

void raaThread::end()
{
	if(m_Handle)
	{
		::TerminateThread(m_Handle, 0);
		::WaitForSingleObject(m_Handle, INFINITE);
		::CloseHandle(m_Handle);
		m_Handle=0;
	}
}

void raaThread::start(bool bDelayReturn)
{
	if(!m_Handle)
	{
		if(bDelayReturn) m_bRelease=false;

		m_Handle=::CreateThread(0,0,threadProc, this, 0, &m_ID);

		if(bDelayReturn) while(!m_bRelease) ::Sleep(100);
	}
}

void raaThread::resume()
{
	if(m_Handle) ::ResumeThread(m_Handle);
}

void raaThread::suspend()
{
	if(m_Handle) ::SuspendThread(m_Handle);
}

void raaThread::setPriority(unsigned int uiPriority)
{
	if(m_Handle)
	{
		switch(uiPriority)
		{
			case csm_uiThreadIdle:
				::SetThreadPriority(m_Handle, THREAD_PRIORITY_IDLE);
				break;
			case csm_uiThreadLowest:
				::SetThreadPriority(m_Handle, THREAD_PRIORITY_LOWEST);
				break;
			case csm_uiThreadLow:
				::SetThreadPriority(m_Handle, THREAD_PRIORITY_BELOW_NORMAL);
				break;
			case csm_uiThreadNormal:
				::SetThreadPriority(m_Handle, THREAD_PRIORITY_NORMAL);
				break;
			case csm_uiThreadHigh:
				::SetThreadPriority(m_Handle, THREAD_PRIORITY_ABOVE_NORMAL);
				break;
			case csm_uiThreadHighest:
				::SetThreadPriority(m_Handle, THREAD_PRIORITY_HIGHEST);
				break;
			case csm_uiThreadRealtime:
				::SetThreadPriority(m_Handle, THREAD_PRIORITY_TIME_CRITICAL);
				break;
		}
	}
}

void raaThread::setProcessor(raaThreadProcessor proc)
{

}

void raaThread::release()
{
	m_bRelease=true;
}

void raaThread::sleep(raaTime tTime)
{
	::Sleep(tTime/1000);
}

unsigned long __stdcall raaThread::threadProc(void *pParam)
{
	raaThread *pMe=(raaThread*)pParam;

	if(dynamic_cast<raaThread*>(pMe))
	{
		pMe->thread();
		::CloseHandle(pMe->m_Handle);
		pMe->m_Handle=0;
	}
	return 0;
}
