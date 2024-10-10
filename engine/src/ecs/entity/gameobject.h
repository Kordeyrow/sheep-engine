#pragma once
#include <vector>
#include <string>
#include <math/vector2.h>
#include <ecs/component/component.h>
#include <ecs/component/transform.h>
#include <utils/dll_macros.h>

class __declspec(dllexport) Gameobject {

private:
	size_t _id;
	std::vector<Component> components;
	//// TODO: turn in to component
	Transform transform;

	static size_t next_id;
public:
	std::string name;

	Gameobject(std::string name,
		Vector2 position,
		Vector2 size);

	size_t id() const { return _id; };

	template<typename DerivedComponent>
	DerivedComponent* get_component() {
		static_assert(std::is_base_of<Component, DerivedComponent>::value, "DerivedComponent must be derived from Component");
		for (auto& comp : components) {
			if (auto* derivedComponent = dynamic_cast<DerivedComponent*>(comp)) {
				return derivedComponent;
			}
		}
		return nullptr;
	}

	template<typename DerivedComponent>
	typename std::enable_if<std::is_base_of<Component, DerivedComponent>::value, std::vector<Component*>&>::type
		get_components() {
		std::vector<Component*>& found_components{};
		for (auto& comp : components) {
			auto derivedComponent = get_derived_type<DerivedComponent>(comp);
			if (derivedComponent) {
				found_components.insert(derivedComponent);
			}
		}
		return found_components;
	}

	template<typename DerivedComponent, typename... Args>
	DerivedComponent* add_component(Args&&... args) {
		// Compile-time check: Ensure DerivedComponent is derived from Component
		static_assert(std::is_base_of<Component, DerivedComponent>::value,
			"DerivedComponent must be derived from Component");

		// Compile-time check: Ensure DerivedComponent is constructible with given arguments
		static_assert(std::is_constructible<DerivedComponent, Args...>::value,
			"DerivedComponent cannot be constructed with the given arguments");

		return new DerivedComponent(std::forward<Args>(args)...);
	}

	template<typename DerivedComponent>
	DerivedComponent* get_derived_type(Component* component) {
		return dynamic_cast<const DerivedComponent*>(&component);
	}
};




