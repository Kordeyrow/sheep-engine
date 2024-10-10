#pragma once
#include <ecs/entity/gameobject.h>
#include <vector>
#include <utils/dll_macros.h>

class __declspec(dllexport) Scene {
public:
	Scene();

	template<typename... Args>
	Gameobject* add_gameobject(Args&&... args);

	std::vector<Gameobject> gameobjects;
};

