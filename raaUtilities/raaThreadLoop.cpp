#include "raaUtilities.h"
#include "raaThreadLoop.h"

raaThreadLoop::raaThreadLoop(void)
{
	m_bLoop=true;
	m_tLoopTime=100000;
	m_tLastCycleTime=raaUtilities::time();
}

raaThreadLoop::~raaThreadLoop(void)
{
}

void raaThreadLoop::setLoop(bool bLoop)
{
	m_bLoop=bLoop;
}

bool raaThreadLoop::isLooping()
{
	return m_bLoop;
}

void raaThreadLoop::setLoopTime(raaTime tTime)
{
	m_tLoopTime=tTime;
}

raaTime raaThreadLoop::getLoopTime()
{
	return m_tLoopTime;
}

void raaThreadLoop::thread()
{
	startLoop();
	
	while(m_bLoop)
	{
		raaTime tTime=raaUtilities::time();

		if((tTime-m_tLastCycleTime)>m_tLoopTime)
		{
			m_tLastCycleTime=tTime;
			loop();						
		}
		else raaThread::sleep(tTime-m_tLastCycleTime);
	}
	
	endLoop();
}
