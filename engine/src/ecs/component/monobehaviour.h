#pragma once
#include <ecs/system/system_components/script_life_cycle_system_component.h>
#include <ecs/component/component.h>

class __declspec(dllexport) Monobehaviour : public Component, ScriptLifeCycleSystemComponent {
public:
	Monobehaviour(GameobjectID owner);
};
