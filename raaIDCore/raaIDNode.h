#pragma once

#include <list>

#include "raaIDBase.h"
#include "raaIDCoreDefs.h"

class raaIDVisitor;
class raaIDContainer;

typedef std::list<class raaIDNode*>raaIDNodes;
typedef std::list<raaIDContainer*> raaIDContainers;

class RAAIDCORE_DLL_DEF raaIDNode: public raaIDBase
{
	friend raaIDVisitor;
public:
	raaIDNode();
	raaIDNode(std::string sName);

	void addChild(raaIDNode*);
	void removeChild(raaIDNode*);

	void addContainer(raaIDContainer *pContainer);
	void removeContainer(raaIDContainer *pContainer);

	const raaIDNodes& children();
	const raaIDNodes& parents();
	const raaIDContainers& containers();

private:
	raaIDNodes m_lParents;
	raaIDNodes m_lChildren;
	raaIDContainers m_lContainers;

protected:
	virtual ~raaIDNode();

	void addParent(raaIDNode*);
	void removeParent(raaIDNode*);

	virtual bool accept(raaIDVisitor&);

};

