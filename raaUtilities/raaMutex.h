#pragma once

#include "raaUtilities.h"
#include "raaUtilitiesDefs.h"

class RAAUTILITIES_DLL_DEF raaMutex
{
public:
	raaMutex(void);
	virtual ~raaMutex(void);

	bool lock();
	bool lock(unsigned int uiWait);
	void unlock();

protected:
	raaMutexHandle m_hMutex;

};
