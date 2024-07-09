#pragma once

#include "stdafx.h"

class LibTechnique : public ObjBase
{
public:
	~LibTechnique()
	{
		vLibParam.clear();
	}
public:
	std::string sProfile;

	std::vector<std::shared_ptr<ObjBase>> vLibParam;

	virtual std::string GetName()
	{
		return GetCheckName();
	}

	static std::string GetCheckName()
	{
		return "technique";
	}

	virtual void AddObj(std::shared_ptr<ObjBase> pAdd)
	{
		if (pAdd->GetName() == LibParam::GetCheckName())
		{
			vLibParam.push_back(pAdd);
			return;
		}
		printf("AddObj GG %s\n", pAdd->GetName().c_str());
	}

	virtual void AddAttr(std::shared_ptr<AttributePair> pAttributePair)
	{
		if (pAttributePair->sName == "profile")
		{
			sProfile = pAttributePair->sValue;
		}
	}

	virtual void PrintfOut()
	{
		printf("sProfile %s\n", sProfile.c_str());

		for (int i = 0; i < vLibParam.size(); ++i)
		{
			vLibParam[i]->PrintfOut();
		}
	}
};