#include <pch.h>
#include <core/sheep_engine.h>
#include <iostream>

SheepEngine::SheepEngine() 
{

}

void SheepEngine::run_engine()
{
	// TODO: scene config, serialization, inspector
}

void SheepEngine::run_game(std::vector<Scene> _scene_list, int _start_scene_id)
{
	if (_scene_list.empty())
	{
		std::cout << "Error: Can NOT start game. Scene list is empty" << std::endl;
		return;
	}

	if (_start_scene_id < 0 || _start_scene_id >= _scene_list.size())
	{
		std::cout << "Error: Can NOT start game. Wrong start scene id" << std::endl;
		return;
	}

	scene_list = _scene_list;
	start_scene_id = _start_scene_id;
	scene_manager = new SceneManager(scene_list);

	while (current_scene)
	{
		entity_event_system.run();
		physics_system.run();
		current_scene = scene_manager->get_next_scene();
	}
}