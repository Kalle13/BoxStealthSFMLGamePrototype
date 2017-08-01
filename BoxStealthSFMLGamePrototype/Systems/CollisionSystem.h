// CollisionSystem.h
#pragma once
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <cmath>
#include "../Utility/Vector2Utility.h"

#define PI 3.141592654
#define MAX_NUM_COLLISION_OBJECTS 10
#define MAX_NUM_COLLISION_FLAGS 10

class CollisionComponent;

// Collision System is a container for collision components.
// The system will use collision detection algorithms to determine
// when a collision occurs. Collisions will need to be flagged and 
// combined with some information about the collision (e.g. collision
// components involved) so that other game systems (e.g. game logic 
// and physics) can handle these events accordingly.

struct CollisionData
{
	int collisionDataID;				// An ID# for identifying a CollisionData instance
	int numVertices;					// Number of vertices comprising the collision boundary
	sf::Vector2f boundsAverageVector;	// Vector that is the average of all vectors comprising the collision boundary
	sf::Vertex *collisionVerticesArray;	// The collision boundary vertices (can also use sf::Vector2f array; sf::Vertex allows for collision bounds to be rendered)

	void CollisionDataMalloc() {
		collisionVerticesArray = (sf::Vertex*)malloc(numVertices * sizeof(sf::Vertex));
	}

	void CollisionDataFree() {
		free(collisionVerticesArray);
	}
};

struct CollisionFlag
{
	int collisionDataID1;
	int collisionDataID2;
	sf::Vector2f collisionVertexVector1;
	sf::Vector2f collisionVertexVector2;
};


class CollisionSystem
{
public:

	CollisionSystem() {}
	~CollisionSystem() {}

	void Initialize();
	void Destroy();

	int AddCollisionObject(); // Tell CollisionSystem to add another collision object; function will return ID of object for further configuration of object
	
	int GetCollisionObjectIndexFromID(int collisionObjectID);

	// CollisionSystem removes CollisionData (use an unordered array data structure: 
	// remove from array, replace with last element in array; decrement array counter)
	bool RemoveCollisionObject(int collisionObjectID);
	
	void RunCollisionDetection();

	void AddCollisionFlag(int ID1, int ID2, sf::Vector2f vertexVector1, sf::Vector2f vertexVector2);
	void ClearCollisionFlags();
	void PrintfCollisionFlags();

public:

	int numCollisionObjects;
	int numCollisionFlags;
	int currentCollisionObjectID;
	int *collisionObjectArrayElementToIDMap;
	CollisionData *collisionObjectArray;
	CollisionFlag *collisionFlagArray;
};

// CollisionDataObjectQuickInit assumes CollisionData ID and numVertices have been initialized for the object
void CollisionDataObjectQuickInit(CollisionData& collisionData);
void DisplaceCollisionDataObject(sf::Vector2f displacement, CollisionData& collisionObject);
void SetCollisionDataPosition(sf::Vector2f position, CollisionData &collisionData);