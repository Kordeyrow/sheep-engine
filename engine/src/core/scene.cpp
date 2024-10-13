#include <pch.h>
#include <core/scene.h>

Scene::Scene()
{
}

Scene* Scene::get_next_scene()
{
	return this;
}
