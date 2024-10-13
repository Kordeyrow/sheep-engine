#pragma once
#include "scene.h"
#include <typeindex>

class __declspec(dllexport) SceneManager {
private:
	std::vector<Scene> scene_list;
public:
	SceneManager(std::vector<Scene> scene_list);
	bool should_change_scene();
	Scene* get_next_scene();
	void change_scene(int scene_index);
	void change_scene(std::string scene_name);
};

