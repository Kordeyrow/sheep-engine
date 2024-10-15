#include <iostream>
#include <core/sheep_engine.h>
#include <ecs/components/entity_event_component.h>
#include <vector>
#include "scenes/menu_scene.h"
#include <player_controller.cpp>

int main()
{
    std::cout << "Hello World! - main()" << std::endl;

    SheepEngine sheep_engine;
    sheep_engine.run_engine();

    Entity player{};
    player.add_component<PlayerController>(player.id);
    auto menu_scene = MenuScene{};
    menu_scene.add_entity(&player);
    auto scene_list = std::vector<Scene*>{ &menu_scene };
    auto start_scene_id = 0;
    GameData data{ scene_list, start_scene_id };
    sheep_engine.run_game(data);

    system("pause");
    return 0;
}