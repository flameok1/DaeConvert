#pragma once

#include "stdafx.h"

class LibraryGeometry : public ModuleBase
{
public:
	LibraryGeometry();
	~LibraryGeometry();
private:
	/// <summary>
	/// 檢查資料對不對
	/// </summary>
	virtual bool CheckDataVaild(std::shared_ptr<XMLNode> pNowNode) override;
public:
	/// <summary>
	/// 取得Module Name(Xml標籤)
	/// </summary>
	virtual std::string GetModuleName() override;
};