#pragma once
#include <type_traits>
#include <string>
#include <ecs/components/transform.h>
#include "component.h"

//enum COMPONENT_ACTION {
//	COMP_ADDED,
//	COMP_REMOVED,
//	COMP_ENABLED,
//	COMP_DISABLED
//};
//
//class ComponentChangeInfo {
//public:
//	COMPONENT_ACTION action;
//	Component* comp;
//
//};

class __declspec(dllexport) Entity {
	friend class SheepEngine;
private:
	bool _is_enabled;
public:
	bool is_enabled(){return _is_enabled;}

	// TODO: should be private somehow
	/*static std::vector<Component*> components_just_enabled;
	static std::vector<Component*> components_just_disabled;
	static std::vector<ComponentChangeInfo> component_change_info_list;*/

	Entity(std::string name = "new Entity", Entity* parent = nullptr);
	Transform transform;
	Transform local_transform;
	size_t id;
	std::vector<std::string> tags;
	std::string name;
	bool locked_to_parent;
	Entity* parent;
	std::vector<Entity*> children;
	std::vector<Component*> component_list;

	bool _is_in_scene;

	bool is_in_scene() const { return _is_in_scene; }

	// TODO: Check if doing copy

	template<typename T, typename... Args>
	typename std::enable_if<
		std::is_base_of<Component, T>::value&&    // Ensure T is derived from Component
		std::is_constructible<T, Args...>::value   // Ensure Args... can be used to construct T
	>::type
	add_component(Args&&... args) {
		// Static assert to check if T can be constructed with Args...
		static_assert(std::is_constructible<T, Args...>::value,
			"Error: The provided arguments do not match the constructor of the component type T.");

		// If the checks pass, create the new component
		T* new_comp = new T(std::forward<Args>(args)...);
		// Typically, you'd do something with new_comp, like storing it



			/*static_assert(std::is_base_of<Component, T>::value, "T must derive from Component");
			T* a = new T(args...);*/



		component_list.push_back(new_comp);
		/*if (c.is_enabled()) {
			components_just_enabled.push_back(component_list[component_list.size() - 1]);
		}
		component_change_info_list.push_back({ COMP_ADDED, component_list[component_list.size() - 1] });*/
	}

	/*void remove_component(Component c) {

	}*/

};

