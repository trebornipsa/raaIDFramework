#pragma once

#include "raaIDCoreDefs.h"

class RAAIDCORE_DLL_DEF  raaIDManaged
{
public:
	raaIDManaged();

	unsigned int ref();
	unsigned int unref(bool bNoDelete = false);
	unsigned int refCount();

private:
	unsigned int m_uiRefCount;

protected:
	virtual ~raaIDManaged();
};

