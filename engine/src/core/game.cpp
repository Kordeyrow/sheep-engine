#include "pch.h"
#include "Game.h"

Game::Game(GameData data)
	: data{ data }, _is_valid{ is_valid(data)}, _is_running {false}
{
}

void Game::init()
{
	if (_is_valid == false)
		return;

	current_scene = &data.scene_list[data.start_scene_id];
}

void Game::close()
{
	_is_running = true;
}

bool Game::is_running() const
{
	return _is_running;
}

bool Game::is_valid() const
{
	return _is_valid;
}

bool Game::is_valid(GameData data) const
{
	if (data.scene_list.empty())
	{
		//std::cout << "Error: Can NOT start game. Scene list is empty" << std::endl;
		return false;
	}

	if (data.start_scene_id < 0 || data.start_scene_id >= data.scene_list.size())
	{
		//std::cout << "Error: Can NOT start game. Wrong start scene id" << std::endl;
		return false;
	}

	return true;
}
