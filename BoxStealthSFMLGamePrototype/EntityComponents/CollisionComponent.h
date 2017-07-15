// CollisionComponent.h
#pragma once
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <cmath>

// These collision types may be redundant
enum CollisionComponentType
{
	Rigid,
	Wall,
	Surface
};

class CollisionComponent
{
public:

	CollisionComponent() {}
	~CollisionComponent() {}

	virtual void CollisionComponentInit() = 0;
	virtual void CollisionComponentUpdate(float deltaTInSeconds) = 0;
	virtual void CollisionComponentDestroy() = 0;

public:

	unsigned numberOfCollisionVertices;
	sf::PrimitiveType primitiveType;
	sf::VertexArray collisionBounds;

};