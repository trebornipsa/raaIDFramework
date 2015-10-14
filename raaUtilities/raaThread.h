#pragma once

#include "raaUtilities.h"
#include "raaUtilitiesDefs.h"

class RAAUTILITIES_DLL_DEF raaThread
{
public:
	const static unsigned int csm_uiThreadIdle=0;
	const static unsigned int csm_uiThreadLowest=1;
	const static unsigned int csm_uiThreadLow=2;
	const static unsigned int csm_uiThreadNormal=3;
	const static unsigned int csm_uiThreadHigh=4;
	const static unsigned int csm_uiThreadHighest=5;
	const static unsigned int csm_uiThreadRealtime=6;

	raaThread(void);
	virtual ~raaThread(void);

	virtual void end();
	virtual void start(bool bDelayReturn=false);
	virtual void resume();
	virtual void suspend();
	virtual void setPriority(unsigned int uiPriority);
	virtual void setProcessor(raaThreadProcessor proc);

protected:
	void release();
	void sleep(raaTime tTime);
	virtual void thread()=0;

private:
	raaThreadHandle m_Handle;
	raaThreadID m_ID;
	bool m_bRelease;
	static unsigned long __stdcall threadProc(void *pParam);
};
