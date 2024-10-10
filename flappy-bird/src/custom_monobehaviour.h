#pragma once
#include <ecs/component/monobehaviour.h>
#include <utils/dll_macros.h>

class CustomMonobehaviour : public Monobehaviour {
//class CustomMonobehaviour {
	//void update(double elapsed_time) override;
public:
	CustomMonobehaviour(size_t owner) : Monobehaviour{owner} {};
};


