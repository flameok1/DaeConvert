#include "LibraryControllers.h"

LibraryControllers::LibraryControllers()
{

}

LibraryControllers::~LibraryControllers()
{

}


bool LibraryControllers::CheckDataVaild(std::shared_ptr<XMLNode> pNowNode)
{
	if (pNowNode->sName != "controller")
	{
		return false;
	}

	return true;
}

std::string LibraryControllers::GetModuleName()
{
	return "library_controllers";
}