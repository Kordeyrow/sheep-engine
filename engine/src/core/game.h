#pragma once
#include <vector>
#include "scene.h"
#include "game_data.h"

// Holds info of the game currently running
class __declspec(dllexport) Game {
public:
	Game(GameData data);
	void close();
	bool is_running() const;
public:
	GameData data;
	Scene* current_scene;
private:
	bool _is_running;
};