#pragma once
#include <ecs/component.h>

class __declspec(dllexport) EntityEventComponent : public Component {
public:
	EntityEventComponent(ID owner_id, bool is_enabled = true);
	virtual void on_update(double elapsed_time) {};
};

