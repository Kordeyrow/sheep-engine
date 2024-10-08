#pragma once
#include <ecs/entity/gameobject_id.h>

class Component {
public:
	bool enabled = true;
	GameobjectID owner;
	Component(GameobjectID owner);
};

