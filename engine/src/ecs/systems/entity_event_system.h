#pragma once
#include <ecs/system.h>

class __declspec(dllexport) EntityEventSystem : public System {
public:
	void run() override;
private:
	void call_events();
};

