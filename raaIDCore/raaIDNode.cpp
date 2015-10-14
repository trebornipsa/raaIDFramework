
#include "raaIDContainer.h"
#include "raaIDNode.h"

raaIDNode::raaIDNode()
{
}

raaIDNode::raaIDNode(std::string sName) : raaIDBase(sName)
{
	
}

void raaIDNode::addChild(raaIDNode* pNode)
{
	if(pNode && pNode!=this)
	{
		m_lChildren.push_back(pNode);
		pNode->addParent(this);
		pNode->ref();
	}
}

void raaIDNode::removeChild(raaIDNode* pNode)
{
	if(pNode && std::find(m_lChildren.begin(), m_lChildren.end(), pNode)!=m_lChildren.end())
	{
		m_lChildren.remove(pNode);
		pNode->removeParent(this);
		pNode->unref();
	}
}

void raaIDNode::addContainer(raaIDContainer* pContainer)
{
	if(pContainer)
	{
		pContainer->ref();
		m_lContainers.push_back(pContainer);
	}
}

void raaIDNode::removeContainer(raaIDContainer* pContainer)
{
	if(pContainer && std::find(m_lContainers.begin(), m_lContainers.end(), pContainer)!=m_lContainers.end())
	{
		m_lContainers.remove(pContainer);
		pContainer->unref();
	}
}

const raaIDNodes& raaIDNode::children()
{
	return m_lChildren;
}

const raaIDNodes& raaIDNode::parents()
{
	return m_lParents;
}

const raaIDContainers& raaIDNode::containers()
{
	return m_lContainers;
}

raaIDNode::~raaIDNode()
{
	for (raaIDNodes::iterator it = m_lChildren.begin(); it != m_lChildren.end(); it++)
	{
		(*it)->removeParent(this);
		(*it)->unref();
	}
}

void raaIDNode::addParent(raaIDNode* pNode)
{
	if(pNode) m_lParents.push_back(pNode);
}

void raaIDNode::removeParent(raaIDNode* pNode)
{
	m_lParents.remove(pNode);
}

bool raaIDNode::accept(raaIDVisitor& visitor)
{
	return true;
}