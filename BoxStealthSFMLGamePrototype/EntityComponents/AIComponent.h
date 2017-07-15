// AIComponent.h
#pragma once
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <cmath>

struct PathNode
{
	sf::Vector2f pathNode;
	PathNode *nextNode;
	PathNode *prevNode;
};


class AIComponent
{
public:

	AIComponent() {}
	~AIComponent() {}

	virtual void AIComponentInit() = 0;
	virtual void AIComponentUpdate() = 0;
	virtual void AIComponentDestroy() = 0;

public:

	PathNode *AIPath;

};
