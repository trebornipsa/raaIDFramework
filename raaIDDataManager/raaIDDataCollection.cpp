#include "raaIDDataCollection.h"



raaIDDataCollection::raaIDDataCollection(std::string sName) : raaIDNode(sName)
{
}

raaIDDataCollection::raaIDDataCollection(std::string sName,std::string sDescription) : raaIDNode(sName)
{
	m_sDescription = sDescription;
}

raaIDDataCollection::~raaIDDataCollection()
{
}
