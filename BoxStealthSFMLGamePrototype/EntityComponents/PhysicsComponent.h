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



/*------------------------------------------------------------------------------------------------*/
/*------------------------------------ Other Physics Functions------------------------------------*/
/*------------------------------------------------------------------------------------------------*/

float Vector2Magnitude(sf::Vector2f vector);
float Vector2Dot(sf::Vector2f vector1, sf::Vector2f vector2);
float Vector2CrossProductSignedMagnitude(sf::Vector2f vector1, sf::Vector2f vector2);

// Vector2ArrayAverage: Returns the average vector from an array of vectors
sf::Vector2f Vector2ArrayAverage(sf::Vector2f *vector2Array, unsigned numVectors);

// DistanceToFarthestVector2FromPoint: Returns the magnitude of the distance from a vector point to the farthest vector in an array
float DistanceToFarthestVector2FromPoint(sf::Vector2f *vector2Array, unsigned numVectorsInArray, sf::Vector2f pointVector);

// Use SmoothDisplacement inside of an sf::Transform "translate()" function to move an object smoothly
// e.g. sf::Transform transfrom.translate(SmoothDisplacement(iVec, fVec, 10.0, deltaT));
sf::Vector2f SmoothDisplacement(sf::Vector2f initialPositionVector, 
								sf::Vector2f finalPositionVector, 
								float speed, 
								float deltaTimeInSeconds);