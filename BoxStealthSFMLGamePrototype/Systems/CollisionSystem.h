// CollisionSystem.h
#pragma once
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <cmath>
#include "../EntityComponents/CollisionComponent.h"

#define MAX_NUM_COLLISION_COMPONENTS 2

class CollisionComponent;

// Collision System is a container for collision components.
// The system will use collision detection algorithms to determine
// when a collision occurs. Collisions will need to be flagged and 
// combined with some information about the collision (e.g. collision
// components involved) so that other game systems (e.g. game logic 
// and physics) can handle these events accordingly.

class CollisionSystem
{
public:

	CollisionSystem() {}
	~CollisionSystem() {}

	void Initialize();
	void Destroy();

	void RunCollisionDetection();
	void RegisterCollisionComponent(CollisionComponent *collisionComponentPtr);
	void UnregisterCollisionComponent(CollisionComponent *collisionComponentPtr);

public:

	unsigned collisionComponentIndex;
	CollisionComponent **collisionComponentPtrArray;

};