// PhysicsComponent.h
#pragma once
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include "EntityComponent.h"
#include "../Entity/Entity.h"

class Entity;

struct LinearPhysics
{
	sf::Vector2f pos;
	sf::Vector2f vel;
	sf::Vector2f acc;
};

struct RotationPhysics
{
	float angle;
	float angVel;
	float angAcc;
};

struct SceneGraph
{	
	Entity *childEntityPtr;
	sf::Transform parentTransformChild;
};

class PhysicsComponent : public EntityComponent
{
public:

	PhysicsComponent() {}
	~PhysicsComponent() {}

	virtual void Initialize() override;
	virtual void Update(float deltaTInSeconds) override;
	virtual void Destroy() override;

public:

	sf::Vector2f scale;
	LinearPhysics linPhys;
	RotationPhysics rotPhys;
	SceneGraph *sceneGraph;	 // Scene graph pointer to allow for several children

};

float Vector2Magnitude(sf::Vector2f vector);
float Vector2Dot(sf::Vector2f vector1, sf::Vector2f vector2);