#include "LibGeometry.h"

std::string LibGeometry::GetName()
{
	return GetCheckName();
}

std::string LibGeometry::GetCheckName()
{
	return "geometry";
}

void LibGeometry::AddAttr(std::shared_ptr<AttributePair> pAttributePair)
{
	if (pAttributePair->sName == "id")
	{
		sID = pAttributePair->sValue;
	}
}


void LibGeometry::AddObj(std::shared_ptr<ObjBase> pAdd)
{
	if (pAdd->GetName() == LibMesh::GetCheckName())
	{
		vMesh.push_back(pAdd);
		return;
	}

	printf("AddObj GGGGGGGGG %s\n" , pAdd->GetName().c_str());
}

void LibGeometry::PrintfOut()
{
	for (auto p : vMesh)
	{
		p->PrintfOut();
	}
}