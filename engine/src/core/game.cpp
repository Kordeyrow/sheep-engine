#include "pch.h"
#include "Game.h"

Game::Game(GameData data)
	: data{ data }, _is_running {false}
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
