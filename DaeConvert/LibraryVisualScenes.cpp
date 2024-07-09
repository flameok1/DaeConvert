#include "LibraryVisualScenes.h"

LibraryVisualScenes::LibraryVisualScenes()
{

}

LibraryVisualScenes::~LibraryVisualScenes()
{

}

bool LibraryVisualScenes::CheckDataVaild(std::shared_ptr<XMLNode> pNowNode)
{
	if (pNowNode->sName != "visual_scene")
	{
		return false;
	}

	return true;
}

std::string LibraryVisualScenes::GetModuleName()
{
	return "library_visual_scenes";
}