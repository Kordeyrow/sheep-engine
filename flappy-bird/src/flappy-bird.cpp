#include <iostream>
#include <core/sheep_engine.h>
#include <vector>
#include "scenes/menu_scene.h"

int main()
{
    std::cout << "Hello World! - main()" << std::endl;

    SheepEngine sheep_engine;
    sheep_engine.run_engine();

    auto menu_scene = MenuScene{};
    auto scene_list = std::vector<Scene>{ menu_scene };
    auto start_scene_id = 0;
    sheep_engine.run_game(scene_list, start_scene_id);

    system("pause");
    return 0;
}