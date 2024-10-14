#pragma once
#include <map>
#include <set>

// TODO: separate into Component and SystemComponent
// not all components will be used by systems

class Component {
	friend class Entity;
public:

	Component(Entity* owner, bool is_enabled = true)
		: owner{ owner }, _id{ next_id() }, _is_enabled{ is_enabled }, is_in_scene{ owner->is_in_scene() }
	{
	}
	using ID = std::size_t;

	static ID next_id() {
		static ID _next_id = 0;
		return _next_id++;
	}

	ID _id;
	bool is_in_scene;
	Entity* owner;
public:
	// getters
	const ID& id() const { return _id; }
	const bool& is_enabled() const { return _is_enabled; }
	bool enable()
	{
		if (_is_enabled) {
			return;
		}
		_is_enabled = true;
	}

private:
	bool is_in_scene;
	bool _is_enabled;
};

template<typename T>
class SystemComponent : public Component {

	using ID = std::size_t;

	static std::map<ID, T*> just_enabled_list;
	static std::set<ID> just_disabled_list;
public:

	static const std::map<ID, T*>& just_enabled_list() const { return just_enabled_list };
	static const std::set<ID>& just_disabled_list() const { return just_enabled_list };

	SystemComponent(Entity* owner, bool is_enabled = true)
		: Component{ owner, is_enabled }
	{
		if (_is_enabled && is_in_scene) {
			add_to_just_enabled_list();
		}
	}
	// methods
	bool enable() 
	{
		if (_is_enabled) {
			return;
		}
		_is_enabled = true;

		if (is_in_scene) {
			add_to_just_enabled_list();
		}
	}
	bool disable() 
	{
		if (_is_enabled == false) {
			return;
		}
		_is_enabled = false;

		if (is_in_scene) {
			add_to_just_disabled_list();
		}
	}
private:
	void add_to_just_enabled_list() 
	{
		just_enabled_list[_id] = this;

		// check if not in disabled list (rare edge case)
		auto& disabled = just_disabled_list;
		auto it = disabled.find(_id);
		if (it != disabled.end()) {
			disabled.erase(it);
		}
	}
	void add_to_just_disabled_list()
	{
		just_disabled_list.insert(_id);

		// check if not in enabled list (rare edge case)
		auto& enabled = just_enabled_list;
		auto it = enabled.find(_id);
		if (it != enabled.end()) {
			enabled.erase(it);
		}
	}
};

