// EntityManager.h
#pragma once
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <cmath>
#include "Entity.h"
#include "../Game/GameInput.h"

class Entity;
class GameInput;

// EntityManager will likely be a Singleton class, as it will always be needed, but only one instance is ever really needed at a time.

class EntityManager
{
public:

	enum EntityType
	{
		Player,
		AI,
		Static
	};

	EntityManager() {}
	~EntityManager() {}

	void EntityManagerInit();
	void EntityManagerUpdate();
	void EntityManagerDestroy();

public:

	unsigned entityIndex;
	Entity *entities;

public: 

	GameInput *gameInputPtr;

};