#pragma once
#include <ecs/system/system_component_base.h>

template <typename T>
class SystemComponent : public SystemComponentBase {
public:
	SystemComponent();
	virtual ~SystemComponent();
};
