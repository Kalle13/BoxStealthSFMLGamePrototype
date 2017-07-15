// PhysicsComponent.h
#pragma once
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include "../Entity.h"

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

class PhysicsComponent
{
public:

	PhysicsComponent() {}
	~PhysicsComponent() {}

	virtual void PhysicsComponentInit() = 0;
	virtual void PhysicsComponentUpdate(float deltaTInSeconds) = 0;
	virtual void PhysicsComponentDestroy() = 0;

public:

	sf::Vector2f scale;
	LinearPhysics linPhys;
	RotationPhysics rotPhys;
	SceneGraph *sceneGraph;	 // Scene graph pointer to allow for several children

};