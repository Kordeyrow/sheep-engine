#include <pch.h>
#include <ecs/system/system_component_base.h>

template<typename T>
inline std::vector<T*> SystemComponentBase::GetInstances()
{
	auto& baseInstances = systemsComponents[typeid(T)];
	std::vector<T*> derivedInstances;
	for (auto* instance : baseInstances) {
		derivedInstances.push_back(static_cast<T*>(instance));
	}
	return derivedInstances;
}