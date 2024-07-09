#pragma once

#include "XMLManager.h"
#include "MathStruct.h"
#include <map>

class ObjBase
{
public:
	ObjBase() {}
	~ObjBase() {}
private:

public:
	std::string sID;

	virtual std::string GetName()
	{
		return "ObjBase";
	}

	virtual void AddObj(std::shared_ptr<ObjBase> pAdd)
	{
		printf("AddObj GG %s\n", pAdd->GetName().c_str());
	}

	virtual void AddAttr(std::shared_ptr<AttributePair> pAttributePair)
	{

	}

	virtual void ParserData(std::string data)
	{

	}

	virtual void PrintfOut()
	{

	}
};

class ObjGeneratorBase
{
public:
	ObjGeneratorBase() {}
	ObjGeneratorBase(std::string name) : _sObjName(name) {}
private:
	std::string _sObjName;
public:
	const std::string& GetName() { return _sObjName; }

	virtual std::shared_ptr<ObjBase> Generate()
	{
		return nullptr;
	}
};

template <typename A>
class ObjGenerator : public ObjGeneratorBase
{

public:
	ObjGenerator(std::string name) : ObjGeneratorBase(name) {}
	~ObjGenerator() {}
private:
	
public:

	virtual std::shared_ptr<ObjBase> Generate() override
	{
		return GenerateTemplate();
	}

	std::shared_ptr<ObjBase> GenerateTemplate()
	{
		static_assert(std::is_base_of<ObjBase, A>::value, "A must derive from ObjBase");
		return std::static_pointer_cast<ObjBase>(std::make_shared<A>());
	}
};

class ObjGenerateManager
{
public:
	ObjGenerateManager();
	~ObjGenerateManager();
private:
	std::map<std::string, std::shared_ptr<ObjGeneratorBase>> _mapGenerators;

	void ParserXMLNodeChild(std::shared_ptr<ObjBase> pNewNode, std::shared_ptr<XMLNode> pXMLNode);

	std::shared_ptr<ObjBase> ParserStand(std::shared_ptr<ObjGeneratorBase> Ogb, std::shared_ptr<XMLNode> pNode);
public:
	void AddObjGeneratorBase(std::shared_ptr<ObjGeneratorBase> ogb);

	std::shared_ptr<ObjBase> CallNameFunc(std::shared_ptr<XMLNode> pXMLNode);
};

extern ObjGenerateManager gObjGenerateManager;

struct NameFunc
{
	std::string name;

	std::shared_ptr<ObjBase>(*fuc)(NameFunc nf,std::shared_ptr<XMLNode>);

	std::shared_ptr<ObjBase>(*generate)(void);
};

std::shared_ptr<ObjBase> CallNameFunc(std::shared_ptr<XMLNode> pXMLNode);


bool IsNameFuncEnd(NameFunc* pNameFunc);

NameFunc commonNameFuncs[];

