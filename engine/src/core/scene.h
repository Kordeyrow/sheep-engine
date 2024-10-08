#pragma once
#include <ecs/entity/gameobject.h>
#include <vector>

class __declspec(dllexport) Scene {
public:
	Scene();

	template<typename... Args>
	Gameobject* add_gameobject(Args&&... args);

private:
	std::vector<Gameobject> gameobjects;
};

