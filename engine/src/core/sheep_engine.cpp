#include <pch.h>
#include <iostream>
#include <SDL.h>
#include <core/sheep_engine.h>
#include "app.h"

SheepEngine::SheepEngine()
{

}

void SheepEngine::run_engine()
{
	// TODO: scene config, serialization, inspector
}

void SheepEngine::run_game(GameData data)
{
	game = new Game{ data };
	if (game->is_valid() == false) {
		std::cout << "Game data not valid" << std::endl;
		return;
	}
	game->init();

	scene_manager = new SceneManager(game->data.scene_list);

	App& app = App::get_instance();
	while (app.is_closed() == false)
	{
		/*entity_event_system.run();
		physics_system.run();
		if (scene_manager->should_change_scene()) {
			current_scene = scene_manager->get_next_scene();
		}*/
	}
}

static double calculate_elapsed_time() {
	static uint32_t prev = SDL_GetTicks();
	static uint32_t now = 0;
	now = SDL_GetTicks();
	double elapsedTime = (now - prev) / 1000.0f; // Convert to seconds.
	prev = SDL_GetTicks();
	return elapsedTime;
}