#pragma once
#include <ecs/components/entity_event_component.h>
#include <iostream>

class PlayerController : public EntityEventComponent {
public:
	PlayerController(ID owner_id, bool is_enabled = true) 
		: EntityEventComponent{ owner_id, is_enabled } {

	}

	void on_update(double elapsed_time) override {
		static double sum = 0;
		sum += elapsed_time;
		std::cout << sum << std::endl;
	}
};

