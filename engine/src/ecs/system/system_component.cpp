#include <pch.h>
#include <ecs/system/system_component.h>

template<typename T>
inline SystemComponent<T>::SystemComponent()
{
	// Register 
	systemsComponents[typeid(T)].push_back(this);
}

template<typename T>
SystemComponent<T>::~SystemComponent()
{
	// Unregister 
	auto& instances = systemsComponents[typeid(T)];
	instances.erase(std::remove(instances.begin(), instances.end(), this), instances.end());
}
