#pragma once

#include "stdafx.h"

class LibVisualScene : public ObjBase
{
public:
	LibVisualScene()
	{

	}

	~LibVisualScene()
	{
		vLibNode.clear();
	}

public:
	std::string name;

	std::vector<std::shared_ptr<ObjBase>> vLibNode;

	virtual std::string GetName()
	{
		return GetCheckName();
	}

	static std::string GetCheckName()
	{
		return "visual_scene";
	}

	virtual void AddObj(std::shared_ptr<ObjBase> pAdd)
	{
		if (pAdd->GetName() == LibNode::GetCheckName())
		{
			vLibNode.push_back(pAdd);
			return;
		}
	}

	virtual void AddAttr(std::shared_ptr<AttributePair> pAttributePair)
	{
		if (pAttributePair->sName == "id")
		{
			sID = pAttributePair->sValue;
		}
		else if (pAttributePair->sName == "name")
		{
			name = pAttributePair->sValue;
		}
	}

	virtual void PrintfOut()
	{
		printf("id %s name %s\n", sID.c_str(), name.c_str());
		for (int i = 0; i < vLibNode.size(); ++i)
		{
			vLibNode[i]->PrintfOut();
		}
	}
};