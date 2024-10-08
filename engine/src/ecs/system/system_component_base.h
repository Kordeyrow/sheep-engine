#pragma once
#include <unordered_map>
#include <typeindex>

class SystemComponentBase {
protected:
	static std::unordered_map<std::type_index, std::vector<SystemComponentBase*>> systemsComponents;
public:
	template <typename T>
	static std::vector<T*> GetInstances();
};

