#include <pch.h>
#include <ecs/entity/gameobject.h>

size_t Gameobject::next_id = 0;

Gameobject::Gameobject(
	std::string name = "new_Gameobject",
	Vector2 position = Vector2{ 0,0 },
	Vector2 size = Vector2{ 1,1 }) // Vector2{ Vector2::one })
	:
	name(name),
	_id(next_id++),
	transform(position, size)
{ }
