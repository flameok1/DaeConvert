#pragma once

#include "stdafx.h"

class LibSource : public ObjBase
{
public:
	LibSource()
	{
		pFloatAry = nullptr;
		pIDREFArray = nullptr;
		pTechniqueCommon = nullptr;
	}

	~LibSource()
	{
	}
public:
	std::shared_ptr<ObjBase> pFloatAry;
	std::shared_ptr<ObjBase> pIDREFArray;
	std::shared_ptr<ObjBase> pTechniqueCommon;

	virtual std::string GetName()
	{
		return GetCheckName();
	}

	static std::string GetCheckName()
	{
		return "source";
	}

	virtual void AddObj(std::shared_ptr<ObjBase> pAdd)
	{
		if (pAdd->GetName() == FloatArray::GetCheckName())
		{
			pFloatAry = pAdd;
			return;
		}

		if (pAdd->GetName() == TechniqueCommon::GetCheckName())
		{
			pTechniqueCommon = pAdd;
			return;
		}

		if (pAdd->GetName() == IDREFArray::GetCheckName())
		{
			pIDREFArray = pAdd;
			return;
		}

		printf("AddObj GG %s\n", pAdd->GetName().c_str());
	}

	virtual void PrintfOut()
	{
		if (pFloatAry != nullptr)
		{

		}

		if (pIDREFArray != nullptr)
		{

		}

		if (pTechniqueCommon != nullptr)
		{
			pTechniqueCommon->PrintfOut();
		}
	}
};