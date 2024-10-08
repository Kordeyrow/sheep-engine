#include <pch.h>
#include <core/scene.h>

Scene::Scene()
{

}

template<typename ...Args>
inline Gameobject* Scene::add_gameobject(Args && ...args)
{
	gameobjects.emplace_back(args);
	return &gameobjects.back();
}