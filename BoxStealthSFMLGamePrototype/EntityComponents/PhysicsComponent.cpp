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
	float magnitude = sqrt(vector.x*vector.x + vector.x*vector.x);
	if (magnitude > 0) {
		return magnitude;
	}
	return -1.0;
}

float Vector2Dot(sf::Vector2f vector1, sf::Vector2f vector2)
{
	return vector1.x*vector2.x + vector1.y*vector2.y;
}