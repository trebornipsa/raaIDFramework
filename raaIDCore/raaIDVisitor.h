#pragma once

#include "raaIDCoreDefs.h"

class raaIDNodePath;
class raaIDNode;

class RAAIDCORE_DLL_DEF raaIDVisitor
{
public:
	// direction of traversal
	const static unsigned int csm_uiTraverseUp=0;
	const static unsigned int csm_uiTraverseDown=1;

	const static unsigned int csm_uiVisitOnDownwardPass = 0;
	const static unsigned int csm_uiVisitOnUpwardPass = 1;
	const static unsigned int csm_uiVisitOnUpwardAndDownwardPass = 2;

	const static unsigned int csm_uiUpwardPass = 0;
	const static unsigned int csm_uiDownwardPass = 1;

	raaIDVisitor(unsigned int uiDirection=csm_uiTraverseDown, unsigned int uiVisitMode=csm_uiVisitOnUpwardAndDownwardPass);
	virtual ~raaIDVisitor();

	void traverse(raaIDNode*);

	const raaIDNodePath* path();

protected:
	virtual void apply(raaIDNode* pNode, unsigned int uiPassDirection)=0;
private:
	raaIDNodePath* m_pPath;

	unsigned int m_uiDirection;
	unsigned int m_uiVisitMode;
};

