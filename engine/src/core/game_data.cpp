#include "pch.h"
#include "game_data.h"

GameData::GameData(std::vector<Scene> scene_list, int start_scene_id)
	: scene_list{ scene_list }, start_scene_id{ start_scene_id }
{
}

bool GameData::is_valid() const
{
	if (scene_list.empty())
	{
		//std::cout << "Error: Can NOT start game. Scene list is empty" << std::endl;
		return false;
	}

	if (start_scene_id < 0 || start_scene_id >= scene_list.size())
	{
		//std::cout << "Error: Can NOT start game. Wrong start scene id" << std::endl;
		return false;
	}

	return true;
}
