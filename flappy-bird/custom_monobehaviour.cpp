#include "custom_monobehaviour.h"
#include <iostream>

void CustomMonobehaviour::update(double elapsed_time)
{
	std::cout << "CustomMonobehaviour update" << std::endl;
}

CustomMonobehaviour::CustomMonobehaviour(GameobjectID owner) : Monobehaviour(owner) {}
