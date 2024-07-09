#pragma once

#include "stdafx.h"


class LibController : public ObjBase
{
public:
	~LibController()
	{
		vLibSkin.clear();
	}
public:
	std::vector<std::shared_ptr<ObjBase>> vLibSkin;

	virtual std::string GetName()
	{
		return GetCheckName();
	}

	static std::string GetCheckName()
	{
		return "controller";
	}

	virtual void AddObj(std::shared_ptr<ObjBase> pAdd)
	{
		if (pAdd->GetName() == LibSkin::GetCheckName())
		{
			vLibSkin.push_back(pAdd);
			return;
		}
	}

	virtual void AddAttr(std::shared_ptr<AttributePair> pAttributePair)
	{
		if (pAttributePair->sName == "id")
		{
			sID = pAttributePair->sValue;
		}
	}

	virtual void PrintfOut()
	{
		for (int i = 0; i < vLibSkin.size(); ++i)
		{
			vLibSkin[i]->PrintfOut();
		}
	}
};