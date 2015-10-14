#include "raaIDNodePath.h"

raaIDNodePath::raaIDNodePath()
{
}

void raaIDNodePath::push(raaIDNode* pNode)
{
	if (pNode)
	{
		pNode->ref();
		m_lNodes.push_back(pNode);
	}
}

void raaIDNodePath::pop()
{
	raaIDNode *pNode = m_lNodes.back();
	if (pNode)
	{
		m_lNodes.pop_back();
		pNode->unref();
	}
}

void raaIDNodePath::clear()
{
	for (raaIDNodes::iterator it = m_lNodes.begin(); it != m_lNodes.end();it++) (*it)->unref();
	m_lNodes.clear();
}

const raaIDNodes& raaIDNodePath::path()
{
	return m_lNodes;
}

raaIDNodePath::~raaIDNodePath()
{
	clear();
}
