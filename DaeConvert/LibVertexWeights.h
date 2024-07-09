#pragma once

#include "stdafx.h"

class LibVertexWeights : public ObjBase
{
public:
	LibVertexWeights()
	{
		nCount = 0;
		pLibVCount = nullptr;
		pLibV = nullptr;
	}

	~LibVertexWeights()
	{
		vLibInput.clear();
	}
public:
	int nCount;
	std::vector<std::shared_ptr<ObjBase>> vLibInput;

	std::shared_ptr<ObjBase> pLibVCount;
	std::shared_ptr<ObjBase> pLibV;

	virtual std::string GetName()
	{
		return GetCheckName();
	}

	static std::string GetCheckName()
	{
		return "vertex_weights";
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

		if (pAdd->GetName() == LibV::GetCheckName())
		{
			pLibV = pAdd;
			return;
		}
	}

	virtual void AddAttr(std::shared_ptr<AttributePair> pAttributePair)
	{
		if (pAttributePair->sName == "count")
		{
			nCount = atoi(pAttributePair->sValue.c_str());
		}
	}
};