#pragma once
#include <unordered_map>
#include <typeindex>
#include <ecs/component.h>
#include <ecs/entity.h>
#include <ecs/system.h>
#include <ecs/systems/physics_system.h>
#include <ecs/systems/entity_event_system.h>

// Used to separate the Game into partitions
// Holds the entities 
class __declspec(dllexport) Scene {
public:
	Scene();
	template <typename Args>
	Entity* add_entity(Args...);
	bool remove_entity(Entity* ent);
	void run_systems();
	bool validade_family_tree();
	void insert_components_into_map(Entity& go);
	void remove_components_from_map(Entity& go);
	void load();
	void unload();
public:
	std::unordered_map<std::type_index, std::vector<std::type_index*>> system_component_map;
	std::string name;
	std::vector<Entity> entity_list;
};

template<typename Args>
inline Entity* Scene::add_entity(Args ...)
{
	return nullptr;
}
