// AIComponent.h
#pragma once
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <cmath>
#include "EntityComponent.h"

struct PathNode
{
	sf::Vector2f pathNode;
	PathNode *nextNode;
	PathNode *prevNode;
};


class AIComponent : public EntityComponent
{
public:

	AIComponent() {}
	~AIComponent() {}

	virtual void Initialize() override;
	virtual void Update(float deltaTInSeconds) override;
	virtual void Destroy() override;

public:

	PathNode *AIPath;

};
