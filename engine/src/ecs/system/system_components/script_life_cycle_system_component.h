#pragma once
#include <ecs/system/system_component.h>
#include <utils/dll_macros.h>
#include <iostream>


class ScriptLifeCycleSystemComponent : SystemComponent<ScriptLifeCycleSystemComponent> {
public:
//	bool is_enabled = true;
//	virtual void awake() { }
//	virtual void on_enable() { }
//	virtual void start() { }
//	virtual void fixed_update() { }
	void update(double elapsed_time) { std::cout << "update" << std::endl; }
//	virtual void late_update() { }
//	virtual void on_disable() { }
//	virtual void on_destroy() { return; }
//private:
//	bool is_awake;
//	bool is_started;
};

