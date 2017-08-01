// CollisionComponent.h
#pragma once
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <cmath>
#include "EntityComponent.h"
#include "../Utility/Vector2Utility.h"

#define DEFAULT_NUM_COLLISION_VERTICES (4)
#define DEFAULT_COLLISION_PRIMITIVE_TYPE (sf::Lines)
#define DEFAULT_COLLISION_BOUNDS_WIDTH (32)
#define DEFAULT_COLLISION_BOUNDS_HEIGHT (32)
#define DEFAULT_COLLISION_VECTOR_CENTER (sf::Vector2f(DEFAULT_COLLISION_BOUNDS_WIDTH/2.0, DEFAULT_COLLISION_BOUNDS_HEIGHT/2.0))
#define DEFAULT_COLLISION_VECTOR_COORD_0 (sf::Vector2f(0,0))
#define DEFAULT_COLLISION_VECTOR_COORD_1 (sf::Vector2f(DEFAULT_COLLISION_BOUNDS_WIDTH,0))
#define DEFAULT_COLLISION_VECTOR_COORD_2 (sf::Vector2f(DEFAULT_COLLISION_BOUNDS_WIDTH,DEFAULT_COLLISION_BOUNDS_HEIGHT))
#define DEFAULT_COLLISION_VECTOR_COORD_3 (sf::Vector2f(0,DEFAULT_COLLISION_BOUNDS_HEIGHT))

// These collision types may be redundant
enum CollisionComponentType 
{
	Rigid,
	Wall,
	Surface
};

class CollisionComponent : public EntityComponent
{
public:

	CollisionComponent() {}
	~CollisionComponent() {}

	virtual void Initialize() override;
	virtual void Update(float deltaTInSeconds) override;
	virtual void Destroy() override;

	void Draw(sf::RenderWindow& window);
	void UpdateCollisionBoundsPositionAndOrientation(sf::Vector2f displacementVector, float displacementAngle);

public:

	// 'minDistanceForCollision_' - the minimum distance between the collisionBoundsCenter 
	// and another collision boundary before collision detection must be resolved using a 
	// finer algorithm. 
	// (minDistanceForCollision_ = Vector2Magnitude(collisionBoundsCenterVector_ - (furthest "collisionBoundsVertexArray_" vertex from center))

	unsigned numCollisionBoundsVertices_;
	float minDistanceForCollision_;	
	sf::Vector2f collisionBoundsCenterVector_;
	sf::Vector2f *collisionBoundsVectorArray_;

	// Add a vertex array component to visualize the collision bounds (in debug mode)
	sf::PrimitiveType collisionBoundsPrimitiveType_;
	sf::VertexArray collisionBoundsVertexArray_;

};