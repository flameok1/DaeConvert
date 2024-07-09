#include "LibraryGeometry.h"


LibraryGeometry::LibraryGeometry()
{

}


LibraryGeometry::~LibraryGeometry()
{

}

bool LibraryGeometry::CheckDataVaild(std::shared_ptr<XMLNode> pNowNode)
{
	if (pNowNode->sName != "geometry")
	{
		return false;
	}

	return true;
}

std::string LibraryGeometry::GetModuleName()
{
	return "library_geometries";
}