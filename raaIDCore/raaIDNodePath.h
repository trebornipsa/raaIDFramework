#pragma once

#include "raaIDCoreDefs.h"
#include "raaIDNode.h"

class RAAIDCORE_DLL_DEF raaIDNodePath: public raaIDBase
{
public:
	raaIDNodePath();

	void push(raaIDNode*);
	void pop();
	void clear();
	const raaIDNodes& path();

private:
	raaIDNodes m_lNodes;

protected:
	virtual ~raaIDNodePath();
};

