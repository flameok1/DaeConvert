#pragma once

#include "stdafx.h"



class LibPolylist : public ObjBase
{
public:
	LibPolylist()
	{
		nCount = 0;
		pLibVCount = nullptr;
		pLibP = nullptr;
	}
	
	~LibPolylist()
	{
		vLibInput.clear();
		vLibExtra.clear();
	}
public:
	int nCount;
	std::string sMaterial;

	std::vector<std::shared_ptr<ObjBase>> vLibInput;

	std::shared_ptr<ObjBase> pLibVCount;
	std::shared_ptr<ObjBase> pLibP;

	std::vector<std::shared_ptr<ObjBase>> vLibExtra;

	virtual std::string GetName()
	{
		return GetCheckName();
	}

	static std::string GetCheckName()
	{
		return "polylist";
	}

	virtual void AddObj(std::shared_ptr<ObjBase> pAdd)
	{
		if (pAdd->GetName() == LibInput::GetCheckName())
		{
			vLibInput.push_back(pAdd);
			return;
		}

		if (pAdd->GetName() == LibVCount::GetCheckName())
		{
			pLibVCount = pAdd;
			return;
		}

		if (pAdd->GetName() == LibP::GetCheckName())
		{
			pLibP = pAdd;
			return;
		}

		if (pAdd->GetName() == LibExtra::GetCheckName())
		{
			vLibExtra.push_back(pAdd);
			return;
		}

		printf("AddObj GG %s\n", pAdd->GetName().c_str());
	}

	virtual void AddAttr(std::shared_ptr<AttributePair> pAttributePair)
	{
		if (pAttributePair->sName == "id")
		{
			sID = pAttributePair->sValue;
		}
		else if (pAttributePair->sName == "name")
		{
			sID = pAttributePair->sValue;
		}
		else if (pAttributePair->sName == "count")
		{
			nCount = atoi(pAttributePair->sValue.c_str());
		}
		else if (pAttributePair->sName == "material")
		{
			sMaterial = pAttributePair->sValue;
		}
	}

	virtual void PrintfOut()
	{
		pLibVCount->PrintfOut();

		for (int i = 0; i < vLibExtra.size(); ++i)
		{
			vLibExtra[i]->PrintfOut();
		}

		for (int k = 0; k < vLibInput.size(); ++k)
		{
			vLibInput[k]->PrintfOut();
		}
	}
};