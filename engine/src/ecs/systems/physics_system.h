#pragma once
#include <ecs/system.h>

class __declspec(dllexport) PhysicsSystem : public System {
public:
	void run() override;
private:
	void simulate();
};

