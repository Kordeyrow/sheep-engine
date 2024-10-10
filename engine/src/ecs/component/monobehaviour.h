#pragma once
#include <ecs/system/system_components/script_life_cycle_system_component.h>
//#include <ecs/component/component.h>
#include <utils/dll_macros.h>

class Monobehaviour : ScriptLifeCycleSystemComponent {
public:
	Monobehaviour(size_t owner) {}
};
