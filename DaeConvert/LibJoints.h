#pragma once

#include "stdafx.h"

class LibJoints : public ObjBase
{
public:
	~LibJoints()
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
		return "joints";
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
	}
};