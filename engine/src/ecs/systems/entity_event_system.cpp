#include "pch.h"
#include "entity_event_system.h"

void EntityEventSystem::call_on_init()
{
}

void EntityEventSystem::call_on_start()
{
}

//void EntityEventSystem::call_on_entity_enabled()
//{
//}

void EntityEventSystem::call_on_update(double elapsed_time_seconds, std::vector<EntityEventComponent*> e_components)
{
	for (auto& c : e_components)
	{
		c->on_update(elapsed_time_seconds);
	}
}

void EntityEventSystem::call_on_physics_updated()
{
}

//void EntityEventSystem::call_on_entity_disabled()
//{
//}
//
//void EntityEventSystem::call_on_entity_removed()
//{
//}
