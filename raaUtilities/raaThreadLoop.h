#pragma once

#include "raaThread.h"

#include "raaUtilitiesDefs.h"

class RAAUTILITIES_DLL_DEF raaThreadLoop: public raaThread
{
public:
	raaThreadLoop(void);
	virtual ~raaThreadLoop(void);

	void setLoop(bool bLoop);
	bool isLooping();

	void setLoopTime(raaTime tTime);
	raaTime getLoopTime();

protected:
	virtual void thread();
	virtual void startLoop()=0;
	virtual void loop()=0;
	virtual void endLoop()=0;

	bool m_bLoop;
	raaTime m_tLoopTime;
	raaTime m_tLastCycleTime;
};
