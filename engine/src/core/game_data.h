#pragma once
#include <vector>
#include "scene.h"

class __declspec(dllexport) GameData {
public:
	GameData(std::vector<Scene> scene_list, int start_scene_id);
	std::vector<Scene> scene_list;
	int start_scene_id;
};

