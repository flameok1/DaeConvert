#pragma once


#include "stdafx.h"

class LibScale : public ObjBase
{
public:
	float3 sScale;

	virtual std::string GetName()
	{
		return GetCheckName();
	}

	static std::string GetCheckName()
	{
		return "scale";
	}

	virtual void ParserData(std::string data)
	{
		std::string tmpStr;
		int index = 0;
		float fsave[3] = { 0,0,0 };

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
					if(index < 3)
						fsave[index++] = std::strtof(tmpStr.c_str() , nullptr);
				}
				tmpStr = "";
			}
		}

		if (tmpStr.length() > 0)
		{
			if (index < 4)
				fsave[index++] = std::strtof(tmpStr.c_str(), nullptr);
		}

		sScale.x = fsave[0];
		sScale.y = fsave[1];
		sScale.z = fsave[2];
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
		printf("scale %f %f %f\n", sScale.x , sScale.y , sScale.z);
	}
};