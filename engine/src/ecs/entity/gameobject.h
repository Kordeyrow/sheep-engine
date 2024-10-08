#pragma once
#include <vector>
#include <string>
#include <math/vector2.h>
#include <ecs/entity/gameobject_id.h>
#include <ecs/component/component.h>
#include <ecs/component/transform.h>

class Gameobject {

private:
	GameobjectID _id;
	std::vector<Component> components;
	//// TODO: turn in to component
	Transform transform;

	static GameobjectID next_id;
public:
	std::string name;

	Gameobject(
		std::string name = "new_Gameobject",
		Vector2 position = Vector2{ 0,0 },
		Vector2 size = Vector2{ 1,1 }) // Vector2{ Vector2::one })
		:
		name(name),
		_id(next_id++),
		transform(position, size)
	{ }

	GameobjectID id() const { return _id; };

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




