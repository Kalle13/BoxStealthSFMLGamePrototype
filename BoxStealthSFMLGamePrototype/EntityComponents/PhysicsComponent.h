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
	sf::Vector2f position_;
	sf::Vector2f velocity_;
	sf::Vector2f acceleration_;
};

struct RotationPhysics
{
	float angle;
	float angularVelocity_;
	float angularAcceleration_;
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

	sf::Vector2f scale_;
	LinearPhysics linPhys_;
	RotationPhysics rotPhys_;
	SceneGraph *sceneGraph_;	 // Scene graph pointer to allow for several children

};