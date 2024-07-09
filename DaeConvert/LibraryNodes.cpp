#include "LibraryNodes.h"

LibraryNodes::LibraryNodes()
{

}


LibraryNodes::~LibraryNodes()
{
	
}

bool LibraryNodes::CheckDataVaild(std::shared_ptr<XMLNode> pNowNode)
{
	if (pNowNode->sName != "node")
	{
		return false;
	}

	return true;
}

std::string LibraryNodes::GetModuleName()
{
	return "library_nodes";
}
