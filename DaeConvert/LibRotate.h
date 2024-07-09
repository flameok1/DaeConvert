#pragma once


#include "stdafx.h"

class LibRotate : public ObjBase
{
public:
	float3 sAxis;
	float fAngle;

	virtual std::string GetName()
	{
		return GetCheckName();
	}

	static std::string GetCheckName()
	{
		return "rotate";
	}

	virtual void ParserData(std::string data)
	{
		std::string tmpStr;
		int index = 0;
		float fsave[4];

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
					if (index < 4)
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

		sAxis.x = fsave[0];
		sAxis.y = fsave[1];
		sAxis.z = fsave[2];
		fAngle = fsave[3];
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
		printf("rotate %f %f %f %f\n", sAxis.x, sAxis.y, sAxis.z, fAngle);
	}
};