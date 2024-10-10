#pragma once
#include <utils/dll_macros.h>
#include "scene.h"
#include <ecs/system/system_component.h>
#include <ecs/system/system_components/script_life_cycle_system_component.h>

class __declspec(dllexport) Engine {
private:
	Scene* scene;
public:
	//Engine(Scene* scene) :scene{ scene } {};
	Engine();
	void run() {
		for (auto u : SystemComponent<ScriptLifeCycleSystemComponent>::GetInstances<ScriptLifeCycleSystemComponent>()) {
			u->update(1);
		}
		/*for (auto obj : scene->gameobjects) {
			if () {

			}
		}*/
	}
};

