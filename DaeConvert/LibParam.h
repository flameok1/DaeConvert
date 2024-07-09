#pragma once

#include "stdafx.h"


class LibParam : public ObjBase
{
public:
	std::string sName;
	std::string sType;
	std::string sData;

	virtual std::string GetName()
	{
		return GetCheckName();
	}

	static std::string GetCheckName()
	{
		return "param";
	}

	virtual void AddAttr(std::shared_ptr<AttributePair> pAttributePair)
	{
		if (pAttributePair->sName == "name")
		{
			sName = pAttributePair->sValue;
		}
		else if (pAttributePair->sName == "type")
		{
			sType = pAttributePair->sValue;
		}
	}

	void ParserData(std::string idata)
	{
		sData = idata;
	}

	virtual void PrintfOut()
	{
		printf("name %s %s %s\n", sName.c_str(), sType.c_str(), sData.c_str());
	}
};