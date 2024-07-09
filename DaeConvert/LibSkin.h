#pragma once

#include "stdafx.h"

class LibSkin : public ObjBase
{
public:
	LibSkin()
	{
		pLibJoints = nullptr;
		pLibVertexWeights = nullptr;
	}

	~LibSkin()
	{
		vSource.clear();
	}
public:
	std::string sSource;

	std::vector<std::shared_ptr<ObjBase>> vSource;
	std::shared_ptr<ObjBase> pLibJoints;
	std::shared_ptr<ObjBase> pLibVertexWeights;


	virtual std::string GetName()
	{
		return GetCheckName();
	}

	static std::string GetCheckName()
	{
		return "skin";
	}

	virtual void AddObj(std::shared_ptr<ObjBase> pAdd)
	{
		if (pAdd->GetName() == LibSource::GetCheckName())
		{
			vSource.push_back(pAdd);
			return;
		}

		if (pAdd->GetName() == LibJoints::GetCheckName())
		{
			pLibJoints = pAdd;
			return;
		}

		if (pAdd->GetName() == LibVertexWeights::GetCheckName())
		{
			pLibVertexWeights = pAdd;
			return;
		}

		printf("AddObj GG %s\n", pAdd->GetName().c_str());
	}

	virtual void AddAttr(std::shared_ptr<AttributePair> pAttributePair)
	{
		if (pAttributePair->sName == "source")
		{
			sSource = pAttributePair->sValue;
		}
	}

	virtual void PrintfOut()
	{
		for (int i = 0; i < vSource.size(); ++i)
		{
			vSource[i]->PrintfOut();
		}
	}
};