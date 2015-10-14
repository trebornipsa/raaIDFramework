#pragma once


#include "raaIDManaged.h"
#include <string>

#include "raaIDCoreDefs.h"

class RAAIDCORE_DLL_DEF raaIDBase: public raaIDManaged
{
public:
	raaIDBase();
	raaIDBase(std::string sName);

	void setName(std::string sName);
	std::string name();



private:
	std::string m_sName;

protected:
	virtual ~raaIDBase();

};

