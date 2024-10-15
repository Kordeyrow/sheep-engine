#pragma once
#include <vector>
#include "scene.h"

// Hold info of to init a Game class
class __declspec(dllexport) GameData {
public:
	GameData(std::vector<Scene*> scene_list, int start_scene_id);
	bool is_valid() const;
public:
	std::vector<Scene*> scene_list;
	int start_scene_id;
};

