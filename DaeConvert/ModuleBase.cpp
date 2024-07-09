#include "ModuleBase.h"

ModuleBase::ModuleBase()
{

}

ModuleBase::~ModuleBase()
{
	_Datas.clear();
}

bool ModuleBase::CheckDataVaild(std::shared_ptr<XMLNode> pNowNode)
{
	return true;
}

bool ModuleBase::InitByXmlNode(std::shared_ptr<XMLNode> pRootNode)
{
	std::shared_ptr<XMLNode> pNowNode = nullptr;

	if (pRootNode == nullptr)
		return false;

	if (pRootNode->sName != GetModuleName())
		return false;

	for (auto pNowNode : pRootNode->vChilds)
	{
		if (!CheckDataVaild(pNowNode))
			continue;

		std::shared_ptr<ObjBase> pAns = gObjGenerateManager.CallNameFunc(pNowNode);

		if (pAns != nullptr)
		{
			_Datas.push_back(pAns);
		}
	}

	return true;
}

void ModuleBase::PrintfOut()
{
	for (auto d: _Datas)
	{
		d->PrintfOut();
	}
}
