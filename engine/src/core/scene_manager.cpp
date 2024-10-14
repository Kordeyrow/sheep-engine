#include "pch.h"
#include "scene_manager.h"

SceneManager::SceneManager(std::vector<Scene> scene_list) : scene_list{ scene_list }
{
}

bool SceneManager::should_change_scene()
{
    return false;
}

Scene* SceneManager::get_next_scene()
{
    return nullptr;
}

void SceneManager::load_scene(int scene_index)
{
    if (scene_index < 0 || scene_index >= scene_list.size()) {
        return;
    }
    scene_list[scene_index].load();
}

void SceneManager::change_scene(int scene_index)
{
}

void SceneManager::change_scene(std::string scene_name)
{
}

Scene* SceneManager::get_current_scene()
{
    return current_scene;
}
