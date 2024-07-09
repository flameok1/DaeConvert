#pragma once

#include "stdafx.h"


class IDREFArray : public ObjBase
{
public:
	int nCount;
	std::vector<std::string> vAllIdRef;

	virtual std::string GetName()
	{
		return GetCheckName();
	}

	static std::string GetCheckName()
	{
		return "IDREF_array";
	}

	virtual void AddAttr(std::shared_ptr<AttributePair> pAttributePair)
	{
		if (pAttributePair->sName == "id")
		{
			sID = pAttributePair->sValue;
		}
		else if (pAttributePair->sName == "count")
		{
			nCount = atoi(pAttributePair->sValue.c_str());
		}
	}

	virtual void ParserData(std::string data)
	{
		std::string tmpStr = "";
		int index = 0;

		for (int i = 0; i < data.size(); ++i)
		{
			if (data[i] != ' ')
			{
				tmpStr += data[i];
			}
			else if (data[i] == ' ')
			{
				if (tmpStr.size() > 0)
				{
					index++;
					vAllIdRef.push_back(tmpStr);
				}
				tmpStr = "";
			}
		}

		if (index != nCount)
			printf("index != nCount Error %d != %d\n", index, nCount);

		if (index != vAllIdRef.size())
			printf("index != vAllIdRef.size() Error %d !=  %llu\n", index, vAllIdRef.size());
	}
};