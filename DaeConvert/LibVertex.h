#pragma once

#include "stdafx.h"

class LibVertex : public ObjBase
{
public:
	~LibVertex()
	{
		vLibInput.clear();
		vLibExtra.clear();
	}
public:
	std::vector<std::shared_ptr<ObjBase>> vLibInput;

	std::vector<std::shared_ptr<ObjBase>> vLibExtra;

	virtual std::string GetName()
	{
		return GetCheckName();
	}

	static std::string GetCheckName()
	{
		return "vertices";
	}

	virtual void AddObj(std::shared_ptr<ObjBase> pAdd)
	{
		if (pAdd->GetName() == LibInput::GetCheckName())
		{
			vLibInput.push_back(pAdd);
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
	}
};