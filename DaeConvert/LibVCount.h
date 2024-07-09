#pragma once

#include "stdafx.h"



class LibVCount : public ObjBase
{
public:
	std::vector<int> vCounts;

	virtual std::string GetName()
	{
		return GetCheckName();
	}

	static std::string GetCheckName()
	{
		return "vcount";
	}

	virtual void ParserData(std::string data)
	{
		std::string tmpStr = "";
		long long total = 0;

		vCounts.clear();

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
					total += add;
					vCounts.push_back(add);
				}
				tmpStr = "";
			}
		}
	}
};