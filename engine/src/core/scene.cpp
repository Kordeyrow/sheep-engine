#include <pch.h>
#include <core/scene.h>

Scene::Scene()
{
}

void Scene::add_entity(Entity* ent)
{
	entity_list.push_back(ent);
}

void Scene::load()
{
}

void Scene::unload()
{
}
