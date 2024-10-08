#pragma once
#include <ecs/system/system_component.h>

class __declspec(dllexport) ScriptLifeCycleSystemComponent : public SystemComponent<ScriptLifeCycleSystemComponent> {
public:
	bool is_enabled = true;
	virtual void awake();
	virtual void on_enable();
	virtual void start();
	virtual void fixed_update();
	virtual void update(double elapsed_time);
	virtual void late_update();
	virtual void on_disable();
	virtual void on_destroy();
private:
	bool is_awake;
	bool is_started;
};

