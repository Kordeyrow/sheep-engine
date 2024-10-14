#pragma once
#include <ecs/components/transform.h>
#include <string>
#include "component.h"

enum COMPONENT_ACTION {
	COMP_ADDED,
	COMP_REMOVED,
	COMP_ENABLED,
	COMP_DISABLED
};

class ComponentChangeInfo {
public:
	COMPONENT_ACTION action;
	Component* comp;

};

class Entity {
	friend class SheepEngine;
public:
	// TODO: should be private somehow
	static std::vector<Component*> components_just_enabled;
	static std::vector<Component*> components_just_disabled;
	static std::vector<ComponentChangeInfo> component_change_info_list;

	Entity(std::string name, Entity* parent);
	Transform transform;
	Transform local_transform;
	size_t id;
	std::vector<std::string> tags;
	std::string name;
	bool locked_to_parent;
	Entity* parent;
	std::vector<Entity*> children;
	std::vector<Component> component_list;

	bool _is_in_scene;

	bool is_in_scene() const { return _is_in_scene; }

	// TODO: Check if doing copy
	void add_component(Component c) {
		component_list.push_back(c);
		if (c.is_enabled()) {
			components_just_enabled.push_back(&component_list[component_list.size() - 1]);
		}
		component_change_info_list.push_back({ COMP_ADDED, &component_list[component_list.size() - 1] });
	}

	void enable_component(Component c) {
		c

	}

	void disable_component(Component c) {

	}

	void remove_component(Component c) {

	}

};

