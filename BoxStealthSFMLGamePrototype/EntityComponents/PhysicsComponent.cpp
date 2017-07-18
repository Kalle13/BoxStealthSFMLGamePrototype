// PhysicsComponent.cpp
#include "PhysicsComponent.h"

void PhysicsComponent::Initialize()
{
}

void PhysicsComponent::Update(float deltaTInSeconds)
{
}

void PhysicsComponent::Destroy()
{
}

float Vector2Magnitude(sf::Vector2f vector)
{
	float magnitude = sqrt(vector.x*vector.x + vector.y*vector.y);
	if (magnitude > 0) {
		return magnitude;
	}
	return -1.0;
}

float Vector2Dot(sf::Vector2f vector1, sf::Vector2f vector2)
{
	return vector1.x*vector2.x + vector1.y*vector2.y;
}

sf::Vector2f Vector2ArrayAverage(sf::Vector2f *vector2Array, unsigned numVectors)
{
	sf::Vector2f averageVector = sf::Vector2f(0, 0);
	
	for (unsigned i = 0; i < numVectors; ++i) {
		averageVector += vector2Array[i];
	}

	averageVector = sf::Vector2f(averageVector.x / numVectors, averageVector.y / numVectors);

	return averageVector;
}

float DistanceToFarthestVector2FromPoint(sf::Vector2f *vector2Array, unsigned numVectorsInArray, sf::Vector2f pointVector)
{
	float furthestDistance = 0;
	float tempDistance = 0;
	sf::Vector2f differenceVector;

	for (unsigned i = 0; i < numVectorsInArray; ++i) {
		differenceVector = vector2Array[i] - pointVector;
		tempDistance = sqrt(differenceVector.x*differenceVector.x + differenceVector.y*differenceVector.y);
		if (tempDistance > furthestDistance) {
			furthestDistance = tempDistance;
		}
	}
	
	return furthestDistance;
}

sf::Vector2f SmoothDisplacement(sf::Vector2f initialPositionVector, sf::Vector2f finalPositionVector, float speed, float deltaTimeInSeconds)
{
	sf::Vector2f displacementVector = speed*deltaTimeInSeconds*(finalPositionVector - initialPositionVector);
	float displacementMagnitude = Vector2Magnitude(finalPositionVector - initialPositionVector);

	if (displacementMagnitude < 0.00000001) {
		displacementVector = sf::Vector2f(0, 0);
	}

	return displacementVector;
}