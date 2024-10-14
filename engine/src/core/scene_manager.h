#pragma once
#include "scene.h"
#include <typeindex>

// Enable user to control scene change
// The SheepEngine uses it to know when to load/unload scenes
class __declspec(dllexport) SceneManager {
public:
	SceneManager(std::vector<Scene> scene_list);
	bool should_change_scene();
	Scene* get_next_scene();
	void load_scene(int scene_index);
	void change_scene(int scene_index);
	void change_scene(std::string scene_name);
	Scene* get_current_scene();
public:
private:
	std::vector<Scene> scene_list;
	Scene* current_scene;
};

