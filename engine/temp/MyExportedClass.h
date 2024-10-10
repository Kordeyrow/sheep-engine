#pragma once
#include <cstddef>
#include <iostream>
#include "Parent.h"

class __declspec(dllexport) MyExportedClass : public Parent {
private:
	static std::size_t next_id;
public:
	MyExportedClass() {
		next_id++;
	}

	template <typename T>
	static void Test()
	{
		next_id++;
		std::cout << "--------- Test" << std::endl;
	}
};

std::size_t MyExportedClass::next_id = 0;