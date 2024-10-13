#pragma once
#include "scene.h"
#include "scene_manager.h"
#include <vector>
#include "game.h"
#include "game_data.h"

class __declspec(dllexport) SheepEngine {
public:
	SheepEngine();
	void run_engine();
	void run_game(GameData data);
private:
	Game* game;
	SceneManager* scene_manager;
	PhysicsSystem physics_system;
	EntityEventSystem entity_event_system;
};

