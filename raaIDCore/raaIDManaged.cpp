#include "raaIDManaged.h"



raaIDManaged::raaIDManaged()
{
	m_uiRefCount = 0;
}

unsigned raaIDManaged::ref()
{
	return ++m_uiRefCount;
}

unsigned raaIDManaged::unref(bool bNoDelete)
{
	unsigned int uiRef = --m_uiRefCount;
	if (!m_uiRefCount && !bNoDelete) delete this;
	return uiRef;
}

unsigned raaIDManaged::refCount()
{
	return m_uiRefCount;
}

raaIDManaged::~raaIDManaged()
{
}
