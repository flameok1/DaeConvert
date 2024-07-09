#pragma once

#include "stdafx.h"

class LibMesh;

class LibGeometry : public ObjBase
{
public:
	~LibGeometry()
	{
		vMesh.clear();
	}
public:
	std::vector<std::shared_ptr<ObjBase>> vMesh;

	virtual std::string GetName();

	static std::string GetCheckName();

	virtual void AddAttr(std::shared_ptr<AttributePair> pAttributePair);

	virtual void AddObj(std::shared_ptr<ObjBase> pAdd);

	virtual void PrintfOut();
};