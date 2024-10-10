#pragma once
#include <unordered_map>
#include <typeindex>
#include <utils/dll_macros.h>

class SystemComponentBase {
//protected:
//	std::unordered_map<std::type_index, std::vector<SystemComponentBase*>> systemsComponents;
//public:
//	SystemComponentBase() = default;
//	virtual ~SystemComponentBase() = default;
//
//	template <typename T>
//	static std::vector<T*> GetInstances() {
//		auto& baseInstances = systemsComponents[typeid(T)];
//		std::vector<T*> derivedInstances;
//		for (auto* instance : baseInstances) {
//			derivedInstances.push_back(static_cast<T*>(instance));
//		}
//		return derivedInstances;
//		return std::vector<T*>();
//	}
};





//std::size_t MyExportedClass::next_id = 0;

//template<typename T>
//inline std::vector<T*> SystemComponentBase::GetInstances() {
//	auto& baseInstances = systemsComponents[typeid(T)]; //get_base_instances<T>(); //;
//	std::vector<T*> derivedInstances;
//	for (auto* instance : baseInstances) {
//		derivedInstances.push_back(static_cast<T*>(instance));
//	}
//	return derivedInstances;
//	return std::vector<T*>();
//}
