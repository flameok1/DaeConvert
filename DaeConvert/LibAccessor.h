#pragma once

#include "stdafx.h"


class LibAccessor : public ObjBase
{
public:
	~LibAccessor()
	{
		vLibParam.clear();
	}
public:
	std::string sSource;
	int nCount;
	int nStride;
	std::vector<std::shared_ptr<ObjBase>> vLibParam;

	virtual std::string GetName()
	{
		return GetCheckName();
	}

	static std::string GetCheckName()
	{
		return "accessor";
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
		if (pAttributePair->sName == "source")
		{
			sID = pAttributePair->sValue;
			sSource = pAttributePair->sValue;
		}
		else if (pAttributePair->sName == "count")
		{
			nCount = atoi(pAttributePair->sValue.c_str());
		}
		else if (pAttributePair->sName == "stride")
		{
			nStride = atoi(pAttributePair->sValue.c_str());
		}
	}

	virtual void PrintfOut()
	{
		printf("%s count %d stride %d\n", sSource.c_str() , nCount, nStride);

		for (int i = 0; i < vLibParam.size(); ++i)
		{
			vLibParam[i]->PrintfOut();
		}
	}
};