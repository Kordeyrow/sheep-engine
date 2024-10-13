#pragma once
#include "scene.h"
#include "scene_manager.h"
#include <vector>

class __declspec(dllexport) SheepEngine {
public:
	SheepEngine();
	void run_engine();
	void run_game(std::vector<Scene> scene_list, int start_scene_id);
private:
	// scene
	std::vector<Scene> scene_list;
	int start_scene_id;
	Scene* current_scene;
	SceneManager* scene_manager;
	// system
	PhysicsSystem physics_system;
	EntityEventSystem entity_event_system;
};

