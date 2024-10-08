#pragma once
#include <ecs/component/monobehaviour.h>

class CustomMonobehaviour : Monobehaviour {
	void update(double elapsed_time) override;
public:
	CustomMonobehaviour(GameobjectID owner);
};


