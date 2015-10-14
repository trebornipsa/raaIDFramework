#pragma once

#include <string>

#include <raaIDCore/raaIDNode.h>

#include "raaIDDataManagerDefs.h"

class RAAIDDATAMANAGER_DLL_DEF raaIDDataCollection : public raaIDNode
{
public:
	raaIDDataCollection(std::string sName);
	raaIDDataCollection(std::string sName, std::string sDescription);

protected:
	virtual ~raaIDDataCollection();

private:
	std::string m_sDescription;
};

