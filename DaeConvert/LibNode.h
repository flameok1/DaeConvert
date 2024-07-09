#pragma once

#include "stdafx.h"

enum LibraryNodeType
{
	None,
	Joint
};


struct LibNode : public ObjBase
{
public:
	~LibNode()
	{
		vScale.clear();
		vRotate.clear();
		vTranslate.clear();
		vExtra.clear();
		subNodes.clear();
	}
public:
	LibraryNodeType eType;
	std::string sType;

	std::vector<std::shared_ptr<ObjBase>> vScale;
	std::vector<std::shared_ptr<ObjBase>> vRotate;
	std::vector<std::shared_ptr<ObjBase>> vTranslate;
	std::vector<std::shared_ptr<ObjBase>> vExtra;

	std::vector<std::shared_ptr<ObjBase>> subNodes;

	virtual std::string GetName()
	{
		return GetCheckName();
	}

	static std::string GetCheckName()
	{
		return "node";
	}

	virtual void AddObj(std::shared_ptr<ObjBase> pAdd)
	{
		if (pAdd->GetName() == LibScale::GetCheckName())
		{
			vScale.push_back(pAdd);
			return;
		}

		if (pAdd->GetName() == LibRotate::GetCheckName())
		{
			vRotate.push_back(pAdd);
			return;
		}

		if (pAdd->GetName() == LibTranslate::GetCheckName())
		{
			vTranslate.push_back(pAdd);
			return;
		}

		if (pAdd->GetName() == LibNode::GetCheckName())
		{
			subNodes.push_back(pAdd);
			return;
		}

		if (pAdd->GetName() == LibExtra::GetCheckName())
		{
			vExtra.push_back(pAdd);
			return;
		}
	}

	virtual void AddAttr(std::shared_ptr<AttributePair> pAttributePair)
	{
		if (pAttributePair->sName == "id")
		{
			sID = pAttributePair->sValue;
		}
		else if (pAttributePair->sName == "type")
		{
			sType = pAttributePair->sValue;
		}
	}

	virtual void PrintfOut()
	{
		printf("id %s type %s \n", sID.c_str(), sType.c_str());

		for (int i = 0; i < vScale.size(); ++i)
		{
			vScale[i]->PrintfOut();
		}

		for (int i = 0; i < vRotate.size(); ++i)
		{
			vRotate[i]->PrintfOut();
		}

		for (int i = 0; i < vTranslate.size(); ++i)
		{
			vTranslate[i]->PrintfOut();
		}

		for (int i = 0; i < subNodes.size(); ++i)
		{
			subNodes[i]->PrintfOut();
		}
	}
};