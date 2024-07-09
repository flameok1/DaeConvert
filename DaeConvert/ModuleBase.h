#pragma once

#include "stdafx.h"

class ModuleBase : public ObjBase
{
public:
	ModuleBase();
	~ModuleBase();
private:
	std::vector<std::shared_ptr<ObjBase>> _Datas;
	
	/// <summary>
	/// 檢查資料對不對
	/// </summary>
	virtual bool CheckDataVaild(std::shared_ptr<XMLNode> pNowNode);
public:
	/// <summary>
	/// 用XmlNode初始化
	/// </summary>
	bool InitByXmlNode(std::shared_ptr<XMLNode> pRootNode);

	/// <summary>
	/// 取得Module Name(Xml標籤)
	/// </summary>
	virtual std::string GetModuleName() = 0;

	virtual void PrintfOut() override;
};