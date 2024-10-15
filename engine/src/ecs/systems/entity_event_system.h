#pragma once
#include <ecs/system.h>
#include <vector>
#include <ecs/components/entity_event_component.h>

class __declspec(dllexport) EntityEventSystem {//: public System {
public:
	void call_on_init();
	void call_on_start();
	//void call_on_entity_enabled();
	void call_on_update(double elapsed_time_seconds, std::vector<EntityEventComponent*> e_components);
	void call_on_physics_updated();
	//void call_on_entity_disabled();
	//void call_on_entity_removed();
};

