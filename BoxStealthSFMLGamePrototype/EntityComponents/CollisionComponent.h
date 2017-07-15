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

public:

	unsigned numberOfCollisionVertices;
	sf::PrimitiveType primitiveType;
	sf::VertexArray collisionBounds;

};