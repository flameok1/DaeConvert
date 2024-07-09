#pragma once

#include "stdafx.h"

class LibV : public ObjBase
{
public:
	~LibV()
	{

	}
public:
	std::vector<int> vV;

	virtual std::string GetName()
	{
		return GetCheckName();
	}

	static std::string GetCheckName()
	{
		return "v";
	}

	virtual void ParserData(std::string data)
	{
		vV.clear();

		std::string tmpStr = "";

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
					int add = atoi(tmpStr.c_str());
					vV.push_back(add);
				}
				tmpStr = "";
			}
		}
	}
};