#pragma once

#include "stdafx.h"

class FloatArray : public ObjBase
{
public:
	FloatArray()
	{
		nCount = 0;
		pAllFloats = nullptr;
	}

	~FloatArray()
	{

	}
public:
	int nCount;
	std::shared_ptr<float[]> pAllFloats;

	virtual std::string GetName()
	{
		return GetCheckName();
	}

	static std::string GetCheckName()
	{
		return "float_array";
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
		pAllFloats = std::shared_ptr<float[]>(new float[nCount]);
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
					char* pEnd;
					float add = strtof(tmpStr.c_str(), &pEnd);
					if (index < nCount)
						pAllFloats[index++] = add;
				}
				tmpStr = "";
			}
		}

		if (index != nCount)
			printf("Error %d != %d\n", index, nCount);
	}
};