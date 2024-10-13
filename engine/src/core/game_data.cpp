#include "pch.h"
#include "game_data.h"

GameData::GameData(std::vector<Scene> scene_list, int start_scene_id)
	: scene_list{ scene_list }, start_scene_id{ start_scene_id }
{
}
