#pragma once

#include "stdafx.h"

class TechniqueCommon : public ObjBase
{
public:
	TechniqueCommon()
	{
		pLibAccessor = nullptr;
	}

	~TechniqueCommon()
	{

	}
public:
	std::shared_ptr<ObjBase> pLibAccessor;

	virtual std::string GetName()
	{
		return GetCheckName();
	}

	static std::string GetCheckName()
	{
		return "technique_common";
	}

	virtual void AddObj(std::shared_ptr<ObjBase> pAdd)
	{
		if (pAdd->GetName() == LibAccessor::GetCheckName())
		{
			pLibAccessor = pAdd;
			return;
		}

		printf("AddObj GG %s\n", pAdd->GetName().c_str());
	}

	virtual void PrintfOut()
	{
		if (pLibAccessor != nullptr)
		{
			pLibAccessor->PrintfOut();
		}
	}
};