#include "raaIDBase.h"



raaIDBase::raaIDBase()
{
}

raaIDBase::raaIDBase(std::string sName)
{
	m_sName = sName;
}

raaIDBase::~raaIDBase()
{
}

void raaIDBase::setName(std::string sName)
{
	m_sName = sName;
}

std::string raaIDBase::name()
{
	return m_sName;
}