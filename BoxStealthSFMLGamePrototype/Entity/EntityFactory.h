// EntityFactory.h
#pragma once
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <cmath>
#include "Entity.h"
#include "EntityManager.h"

class Entity;
class EntityManager;

// EntityFactory will likely be a Singleton class, as it will always be needed, but only one instance is ever really needed at a time.

class EntityFactory
{
public:

	EntityFactory() {}
	~EntityFactory() {}

	void EntityFactoryInit();	
	void EntityFactoryDestroy();	

	void CreateEntity(Entity& entity);

public: 

	EntityManager *entityManagerPtr;

};

/* EntityFactory pseudocode:

void EntityFactory::CreateEntity(Entity& entity)
{
	EntityManager::EntityType entityType = entity.entityType;

	Entity newEntity;
	PhysicsComponent *newPhysCompPtr;
	RenderComponent *newRenderCompPtr;
	AIComponent *newAIComponentPtr;
	InputComponent *newInputComponentPtr;
	CollisionComponent *newCollisionComponentPtr;

	switch(entityType)
	{
	case Player:
		newPhysicsCompPtr = (PhysicsComponent*)malloc(sizeof(newPhysicsCompPtr));
		newCollisionCompPtr = (CollisionComponent*)malloc(sizeof(newCollisionCompPtr));
		newRenderCompPtr = (RenderComponent*)malloc(sizeof(newRenderCompPtr));
		newInputCompPtr = (InputComponent*)malloc(sizeof(newInputCompPtr));
		
		newEntity.physicsCompPtr = newPhysicsCompPtr;
		newEntity.collisionCompPtr = newCollisionCompPtr;
		newEntity.renderCompPtr = newRenderCompPtr;
		newEntity.inputCompPtr = newInputCompPtr;
	
	break;
	case AI:

		break;
	case Static:

		break;
	case default:

		break;
	}




	


}
*/