#pragma once
#include <ecs/system.h>

class __declspec(dllexport) EntityEventSystem {//: public System {
public:
	void call_on_init();
	void call_on_start();
	//void call_on_entity_enabled();
	void call_on_update(double elapsed_time_seconds);
	void call_on_physics_updated();
	//void call_on_entity_disabled();
	//void call_on_entity_removed();
};

