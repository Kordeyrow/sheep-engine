#pragma once
#include <utils/dll_macros.h>

class __declspec(dllexport) Component {
public:
	bool enabled = true;
	size_t owner;
	Component(size_t owner) : owner(owner) {}
};

