#pragma once

#include "stdafx.h"



class LibP : public ObjBase
{
public:
	std::vector<int> vP;

	virtual std::string GetName()
	{
		return GetCheckName();
	}

	static std::string GetCheckName()
	{
		return "p";
	}

	virtual void ParserData(std::string data)
	{
		vP.clear();

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
					vP.push_back(add);
				}
				tmpStr = "";
			}
		}
	}
};