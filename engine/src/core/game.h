#pragma once
#include <vector>
#include "scene.h"
#include "game_data.h"

class Game {
public:
	Game(GameData data);
	void init();
	void close();
	bool is_running() const;
	bool is_valid() const;
private:
	bool is_valid(GameData data) const;
public:
	GameData data;
	Scene* current_scene;
private:
	bool _is_running;
	bool _is_valid;
};