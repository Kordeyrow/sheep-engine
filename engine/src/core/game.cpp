#include "pch.h"
#include "Game.h"

Game::Game(GameData data)
	: data{ data }, _is_valid{ is_valid(data)}, _is_running {false}
{
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
