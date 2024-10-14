#pragma once
#include <ecs/system.h>
#include <vector>
#include <ecs/components/rigidbody.h>

class __declspec(dllexport) PhysicsSystem { //; : public System {
public:
	void simulate(std::vector<Rigidbody*> rbs);
public:
	const float simulation_delay_seconds = 0.02;
};

