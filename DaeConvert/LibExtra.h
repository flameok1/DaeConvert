#pragma once

#include "stdafx.h"

class LibExtra : public ObjBase
{
public:
	~LibExtra()
	{
		vLibTechnique.clear();
	}
public:
	std::vector<std::shared_ptr<ObjBase>> vLibTechnique;

	virtual std::string GetName()
	{
		return GetCheckName();
	}

	static std::string GetCheckName()
	{
		return "extra";
	}

	virtual void AddObj(std::shared_ptr<ObjBase> pAdd)
	{
		if (pAdd->GetName() == LibTechnique::GetCheckName())
		{
			vLibTechnique.push_back(pAdd);
			return;
		}

		printf("Other Node %s\n", pAdd->GetName().c_str());
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
		for (int i = 0; i < vLibTechnique.size(); ++i)
		{
			vLibTechnique[i]->PrintfOut();
		}
	}
};