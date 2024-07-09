#pragma once

#include "stdafx.h"

class LibTranslate : public ObjBase
{
public:
	float3 sTranslate;

	virtual std::string GetName()
	{
		return GetCheckName();
	}

	static std::string GetCheckName()
	{
		return "translate";
	}

	virtual void ParserData(std::string data)
	{
		std::string tmpStr;
		int index = 0;
		float fsave[3];

		for (int i = 0; i < data.length(); ++i)
		{
			if (data[i] != ' ')
			{
				tmpStr += data[i];
			}
			else
			{
				if (tmpStr.length() > 0)
				{
					if (index < 3)
						fsave[index++] = std::strtof(tmpStr.c_str(), nullptr);
				}
				tmpStr = "";
			}
		}

		if (tmpStr.length() > 0)
		{
			if (index < 4)
				fsave[index++] = std::strtof(tmpStr.c_str(), nullptr);
		}

		sTranslate.x = fsave[0];
		sTranslate.y = fsave[1];
		sTranslate.z = fsave[2];
	}

	virtual void AddAttr(std::shared_ptr<AttributePair> pAttributePair)
	{
		if (pAttributePair->sName == "sid")
		{
			sID = pAttributePair->sValue;
		}
	}

	virtual void PrintfOut()
	{
		printf("Translate %f %f %f\n", sTranslate.x, sTranslate.y, sTranslate.z);
	}
};
