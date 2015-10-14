#include "raaIDNodePath.h"
#include "raaIDVisitor.h"

raaIDVisitor::raaIDVisitor(unsigned int uiDirection, unsigned int uiVisitMode)
{
	m_uiDirection = uiDirection;
	m_uiVisitMode = uiVisitMode;
	m_pPath = new raaIDNodePath();
	m_pPath->ref();
}

raaIDVisitor::~raaIDVisitor()
{
	m_pPath->unref();
}

void raaIDVisitor::traverse(raaIDNode* pNode)
{
	if(pNode)
	{
		if (m_uiDirection == csm_uiTraverseDown)
		{
			m_pPath->push(pNode);

			if ((m_uiVisitMode == csm_uiVisitOnDownwardPass || m_uiVisitMode == csm_uiVisitOnUpwardAndDownwardPass) && pNode->accept(*this)) apply(pNode, csm_uiDownwardPass);

			for (raaIDNodes::const_iterator cit = pNode->children().begin(); cit != pNode->children().end(); cit++) traverse(*cit);

			if ((m_uiVisitMode == csm_uiVisitOnUpwardPass || m_uiVisitMode == csm_uiVisitOnUpwardAndDownwardPass) && pNode->accept(*this)) apply(pNode, csm_uiUpwardPass);
			m_pPath->pop();
		}
		else if (m_uiDirection == csm_uiTraverseUp)
		{
			m_pPath->push(pNode);

			if ((m_uiVisitMode == csm_uiVisitOnUpwardPass || m_uiVisitMode == csm_uiVisitOnUpwardAndDownwardPass) && pNode->accept(*this)) apply(pNode, csm_uiUpwardPass);

			for (raaIDNodes::const_iterator cit = pNode->parents().begin(); cit != pNode->parents().end(); cit++) traverse(*cit);

			if ((m_uiVisitMode == csm_uiVisitOnDownwardPass || m_uiVisitMode == csm_uiVisitOnUpwardAndDownwardPass) && pNode->accept(*this)) apply(pNode, csm_uiDownwardPass);
			m_pPath->pop();
		}
	}
}

const raaIDNodePath* raaIDVisitor::path()
{
	return m_pPath;
}

void raaIDVisitor::apply(raaIDNode* pNode,unsigned uiPassDirection) {}