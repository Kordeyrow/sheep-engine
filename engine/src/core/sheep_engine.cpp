#include <pch.h>
#include <iostream>
#include <SDL.h>
#include <core/sheep_engine.h>
#include "app.h"
#include <ecs/components/rigidbody.h>

SheepEngine::SheepEngine()
{
}

void SheepEngine::run_engine()
{
	// TODO: scene config (world building), serialization, inspector
}

void SheepEngine::run_game(GameData data)
{
	// create Game
	if (data.is_valid() == false) {
		std::cout << "Game data not valid" << std::endl;
		return;
	}
	game = new Game{ data };

	// load start scene
	scene_manager = new SceneManager(data.scene_list);
	scene_manager->load_scene(data.start_scene_id);

	// update system components
	/*for (auto& comp_info : Entity::component_change_info_list) {
		switch (switch_on)
		{
		default:
			break;
		} (comp_info.action) {}
	}*/

	// update system components
	for (auto& entity : scene_manager->get_current_scene()->entity_list) {
		for (auto& comp : entity.component_list) {

		}
	}

	// on init
	entity_event_system.call_on_init();
	auto& app = App::get_instance();

	// update system components
	


	// on start
	static uint32_t previous_time = get_current_time();
	entity_event_system.call_on_start();

	// update system components




	// elapsed time sum seconds
	float sum = 0;
	while (app.is_closed() == false) {
		// time
		auto now = get_current_time();
		auto elapsed_time = (now - previous_time) / 1000.0f; // Convert to seconds.
		sum += elapsed_time;
		previous_time = now;

		// update system components
		
		// entities
		std::unordered_map<std::type_index, std::vector<std::type_index*>> system_component_map;
		std::vector<Rigidbody*> rb_components = system_component_map[std::type_index(typeid(Rigidbody))];
		
		// physics
		if (sum >= physics_system.simulation_delay_seconds) {
			sum -= physics_system.simulation_delay_seconds;
			// TODO: check for elapsed_time_sum_seconds > 2 * physics_system.simulation_delay_seconds
			physics_system.simulate(rb_components);
			entity_event_system.call_on_physics_updated();
		}

		// entity events
		entity_event_system.call_on_update(elapsed_time);
		if (scene_manager->should_change_scene()) {
			//current_scene = scene_manager->get_next_scene();
		}
	}
}

uint32_t SheepEngine::get_current_time()
{
	return SDL_GetTicks();
}
