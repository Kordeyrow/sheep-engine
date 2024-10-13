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

void SceneManager::change_scene(int scene_index)
{
}

void SceneManager::change_scene(std::string scene_name)
{
}
