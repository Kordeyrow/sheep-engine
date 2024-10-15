#include "pch.h"
#include "entity.h"

Entity::Entity(std::string name, Entity* parent)
	:name{ name }, parent{ parent }, _is_enabled{ true }
{
}
