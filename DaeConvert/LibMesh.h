#pragma once

#include "stdafx.h"

class LibSource;
class LibVertex;
class LibPolylist;

class LibMesh : public ObjBase
{
public:
	~LibMesh()
	{
		vSource.clear();
		vVertex.clear();
		vPolylist.clear();
	}
public:
	std::vector<std::shared_ptr<ObjBase>> vSource;
	std::vector<std::shared_ptr<ObjBase>> vVertex;
	std::vector<std::shared_ptr<ObjBase>> vPolylist;

	virtual std::string GetName()
	{
		return GetCheckName();
	}

	static std::string GetCheckName()
	{
		return "mesh";
	}

	virtual void AddObj(std::shared_ptr<ObjBase> pAdd)
	{
		if (pAdd->GetName() == LibSource::GetCheckName())
		{
			vSource.push_back(pAdd);
			return;
		}

		if (pAdd->GetName() == LibVertex::GetCheckName())
		{
			vVertex.push_back(pAdd);
			return;
		}

		if (pAdd->GetName() == LibPolylist::GetCheckName())
		{
			vPolylist.push_back(pAdd);
			return;
		}

		printf("AddObj GG %s\n", pAdd->GetName().c_str());
	}

	virtual void PrintfOut()
	{
		for (auto p : vSource)
		{
			p->PrintfOut();
		}
	}
};
