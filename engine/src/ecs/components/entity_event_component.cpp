#include "pch.h"
#include "entity_event_component.h"

EntityEventComponent::EntityEventComponent(ID owner_id, bool is_enabled)
	: Component{owner_id, is_enabled}
{
}
