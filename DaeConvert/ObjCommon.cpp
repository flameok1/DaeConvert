#include "ObjCommon.h"
#include "stdafx.h"


bool IsNameFuncEnd(NameFunc* pNameFunc)
{
	if (pNameFunc->name == "end" && pNameFunc->fuc == nullptr)
		return true;

	return false;
}

std::shared_ptr<ObjBase> CallNameFunc(std::shared_ptr<XMLNode> pXMLNode)
{
	for (int f = 0; ; ++f)
	{
		if (IsNameFuncEnd(&commonNameFuncs[f]))
			break;

		if (commonNameFuncs[f].name == pXMLNode->sName)
		{
			return (commonNameFuncs[f].fuc)(commonNameFuncs[f],pXMLNode);
		}
	}

	return nullptr;
}

void ParserXMLNodeChild(std::shared_ptr<ObjBase> pNewNode, std::shared_ptr<XMLNode> pXMLNode)
{
	for (int n = 0; n < pXMLNode->vChilds.size(); ++n)
	{
		std::shared_ptr<XMLNode> pSubNode = pXMLNode->vChilds[n];

		std::shared_ptr<ObjBase> pAns = CallNameFunc(pSubNode);

		if (pAns != nullptr)
		{
			pNewNode->AddObj(pAns);
		}
	}
}

std::shared_ptr<ObjBase> ParserStand(NameFunc nf, std::shared_ptr<XMLNode> pNode)
{
	std::shared_ptr<ObjBase> pNewNode = nf.generate();

	for (int n = 0; n < pNode->vAttrs.size(); ++n)
	{
		pNewNode->AddAttr(pNode->vAttrs[n]);
	}

	pNewNode->ParserData(pNode->sData);

	ParserXMLNodeChild(pNewNode, pNode);

	return pNewNode;
}

template <typename A>
std::shared_ptr<ObjBase> GenerateObj()
{
	static_assert(std::is_base_of<ObjBase, A>::value, "A must derive from ObjBase");
	return std::static_pointer_cast<ObjBase>(std::make_shared<A>());
}


NameFunc commonNameFuncs[] =
{
	{"param" , ParserStand , GenerateObj<LibParam>},
	{"technique" , ParserStand , GenerateObj<LibTechnique>},
	{"extra" , ParserStand , GenerateObj<LibExtra>},
	{"geometry" , ParserStand , GenerateObj<LibGeometry>},
	{"mesh" , ParserStand , GenerateObj<LibMesh>},
	{"source" , ParserStand , GenerateObj<LibSource>},
	{"float_array" , ParserStand , GenerateObj<FloatArray>},
	{"technique_common" , ParserStand , GenerateObj<TechniqueCommon>},
	{"accessor" , ParserStand , GenerateObj<LibAccessor>},
	{"vertices" , ParserStand , GenerateObj<LibVertex>},
	{"polylist" , ParserStand , GenerateObj<LibPolylist>},
	{"input" , ParserStand , GenerateObj<LibInput>},
	{"vcount" , ParserStand , GenerateObj<LibVCount>},
	{"p" , ParserStand , GenerateObj<LibP>},
	{"v" , ParserStand , GenerateObj<LibV>},
	{"vertex_weights" , ParserStand , GenerateObj<LibVertexWeights>},
	{"joints" , ParserStand , GenerateObj<LibJoints>},
	{"skin" , ParserStand , GenerateObj<LibSkin>},
	{"controller" , ParserStand , GenerateObj<LibController>},
	{"IDREF_array" , ParserStand , GenerateObj<IDREFArray>},
	{"node" , ParserStand, GenerateObj<LibNode>},
	{"scale" , ParserStand, GenerateObj<LibScale>},
	{"rotate" , ParserStand, GenerateObj<LibRotate>},
	{"translate" , ParserStand, GenerateObj<LibTranslate>},
	{"end" , 0 , nullptr},
};

ObjGenerateManager gObjGenerateManager;

ObjGenerateManager::ObjGenerateManager()
{
	AddObjGeneratorBase(std::make_shared< ObjGenerator<LibParam> >("param"));
	AddObjGeneratorBase(std::make_shared< ObjGenerator<LibTechnique> >("technique"));
	AddObjGeneratorBase(std::make_shared< ObjGenerator<LibExtra> >("extra"));
	AddObjGeneratorBase(std::make_shared< ObjGenerator<LibGeometry> >("geometry"));
	AddObjGeneratorBase(std::make_shared< ObjGenerator<LibMesh> >("mesh"));
	AddObjGeneratorBase(std::make_shared< ObjGenerator<LibSource> >("source"));
	AddObjGeneratorBase(std::make_shared< ObjGenerator<FloatArray> >("float_array"));
	AddObjGeneratorBase(std::make_shared< ObjGenerator<TechniqueCommon> >("technique_common"));
	AddObjGeneratorBase(std::make_shared< ObjGenerator<LibAccessor> >("accessor"));
	AddObjGeneratorBase(std::make_shared< ObjGenerator<LibVertex> >("vertices"));
	AddObjGeneratorBase(std::make_shared< ObjGenerator<LibPolylist> >("polylist"));
	AddObjGeneratorBase(std::make_shared< ObjGenerator<LibInput> >("input"));
	AddObjGeneratorBase(std::make_shared< ObjGenerator<LibVCount> >("vcount"));
	AddObjGeneratorBase(std::make_shared< ObjGenerator<LibP> >("p"));
	AddObjGeneratorBase(std::make_shared< ObjGenerator<LibV> >("v"));
	AddObjGeneratorBase(std::make_shared< ObjGenerator<LibVertexWeights> >("vertex_weights"));
	AddObjGeneratorBase(std::make_shared< ObjGenerator<LibJoints> >("joints"));
	AddObjGeneratorBase(std::make_shared< ObjGenerator<LibSkin> >("skin"));
	AddObjGeneratorBase(std::make_shared< ObjGenerator<LibController> >("controller"));
	AddObjGeneratorBase(std::make_shared< ObjGenerator<IDREFArray> >("IDREF_array"));
	AddObjGeneratorBase(std::make_shared< ObjGenerator<LibNode> >("node"));
	AddObjGeneratorBase(std::make_shared< ObjGenerator<LibScale> >("scale"));
	AddObjGeneratorBase(std::make_shared< ObjGenerator<LibRotate> >("rotate"));
	AddObjGeneratorBase(std::make_shared< ObjGenerator<LibTranslate> >("translate"));
}

ObjGenerateManager::~ObjGenerateManager()
{

}

void ObjGenerateManager::AddObjGeneratorBase(std::shared_ptr<ObjGeneratorBase> ogb)
{
	_mapGenerators.insert({ ogb->GetName() , ogb });
}


std::shared_ptr<ObjBase> ObjGenerateManager::CallNameFunc(std::shared_ptr<XMLNode> pXMLNode)
{
	if (_mapGenerators.find(pXMLNode->sName) == _mapGenerators.end())
		return nullptr;
	return ParserStand(_mapGenerators[pXMLNode->sName], pXMLNode);
}

void ObjGenerateManager::ParserXMLNodeChild(std::shared_ptr<ObjBase> pNewNode, std::shared_ptr<XMLNode> pXMLNode)
{
	for (int n = 0; n < pXMLNode->vChilds.size(); ++n)
	{
		std::shared_ptr<XMLNode> pSubNode = pXMLNode->vChilds[n];

		std::shared_ptr<ObjBase> pAns = CallNameFunc(pSubNode);

		if (pAns != nullptr)
		{
			pNewNode->AddObj(pAns);
		}
	}
}

std::shared_ptr<ObjBase> ObjGenerateManager::ParserStand(std::shared_ptr<ObjGeneratorBase> Ogb, std::shared_ptr<XMLNode> pNode)
{
	std::shared_ptr<ObjBase> pNewNode = Ogb->Generate();

	for (int n = 0; n < pNode->vAttrs.size(); ++n)
	{
		pNewNode->AddAttr(pNode->vAttrs[n]);
	}

	pNewNode->ParserData(pNode->sData);

	ParserXMLNodeChild(pNewNode, pNode);

	return pNewNode;
}