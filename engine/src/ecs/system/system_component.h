#pragma once
#include <ecs/system/system_component_base.h>
#include <utils/dll_macros.h>

template <typename T>
class SystemComponent {
protected:
	std::unordered_map<std::type_index, std::vector<SystemComponent<T>*>> systemsComponents;
public:
	SystemComponent()
	{
		auto& t = typeid(T);
		systemsComponents[t].push_back(this);
	}

	~SystemComponent()
	{
		// Unregister 
		/*auto& instances = systemsComponents[typeid(T)];
		instances.erase(std::remove(instances.begin(), instances.end(), this), instances.end());*/
	}

	template <typename T>
	static std::vector<T*> GetInstances() {
		auto& baseInstances = systemsComponents[typeid(SystemComponent<T>)];
		std::vector<T*> derivedInstances;
		for (auto* instance : baseInstances) {
			derivedInstances.push_back(static_cast<T*>(instance));
		}
		return derivedInstances;
		return std::vector<T*>();
	}
public:
};