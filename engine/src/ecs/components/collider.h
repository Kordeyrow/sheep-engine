#pragma once
#include <ecs/components/transform.h>
#include <ecs/components/collider.h>

class __declspec(dllexport) Collider {
public:
    using ListenerID = std::size_t;

	Transform* transform;
	Vector2 relative_scale;	

	//virtual void just_collided(Collider* other);

 //   // Register a member function for an event type using shared_ptr
 //   template <typename ObjectType, typename EventType>
 //   ListenerID Register(ObjectType* obj, void(ObjectType::* func)(Collider* other)) {
 //       auto id = nextListenerID++;
 //       std::type_index eventType = typeid(EventType);

 //       listeners[eventType][id] = [obj, func](const BaseEvent& event) {
 //           auto derivedEvent = dynamic_cast<const EventType*>(&event);
 //           if (derivedEvent) {
 //               (obj.get()->*func)(*derivedEvent);  // Use shared_ptr to access the object
 //           }
 //           };
 //       return id;
 //   }

private:
    std::size_t nextListenerID = 0;
};

