#pragma once
#include <ecs/components/transform.h>
#include <string>

class Entity {
public:
	Entity(std::string name, Entity* parent);
	Transform transform;
	Transform local_transform;
	size_t id;
	std::vector<std::string> tags;
	std::string name;
	bool locked_to_parent;
	Entity* parent;
	std::vector<Entity*> children;
};

