// Entity.h
#pragma once
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <cmath>
#include "../EntityComponents/PhysicsComponent.h"
#include "../EntityComponents/RenderComponent.h"
#include "../EntityComponents/InputComponent.h"
#include "../EntityComponents/CollisionComponent.h"
#include "../EntityComponents/AIComponent.h"

class PhysicsComponent;
class RenderComponent;
class InputComponent;
class CollisionComponent;
class AIComponent;

class Entity
{
public:

	Entity() {}
	~Entity() {}

	virtual void EntityInit() = 0;
	virtual void EntityUpdate(float deltaTInSeconds) = 0;
	virtual void EntityDestroy() = 0;
	
public:

	// Create transforms between physics and render components on a 
	// per-entity basis (i.e. to allow for physics data to effect render data)

	PhysicsComponent *physicsCompPtr;	
	RenderComponent *renderCompPtr;
	InputComponent *inputCompPtr;
	CollisionComponent *collisionCompPtr;
	AIComponent *aICompPtr;
};