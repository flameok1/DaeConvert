#pragma once

#include "stdafx.h"

class LibInput : public ObjBase
{
public:
	std::string sSemantic;
	int nOffset;
	std::string sSource;
	int nSet;

	virtual std::string GetName()
	{
		return GetCheckName();
	}

	static std::string GetCheckName()
	{
		return "input";
	}

	virtual void AddAttr(std::shared_ptr<AttributePair> pAttributePair)
	{
		if (pAttributePair->sName == "offset")
		{
			nOffset = atoi(pAttributePair->sValue.c_str());
		}
		else if (pAttributePair->sName == "semantic")
		{
			sSemantic = pAttributePair->sValue;
		}
		else if (pAttributePair->sName == "source")
		{
			sSource = pAttributePair->sValue;
		}
		else if (pAttributePair->sName == "set")
		{
			nSet = atoi(pAttributePair->sValue.c_str());
		}
	}

	virtual void PrintfOut()
	{
		printf("offset %d semantic %s , src %s , set %d\n", nOffset, sSemantic.c_str(), sSource.c_str(), nSet);
	}
};