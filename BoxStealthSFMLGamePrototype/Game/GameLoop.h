// GameLoop.h
#pragma once
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <stdlib.h>
#include <stdio.h>
#include <cmath>
#include "GameInput.h"
#include "../Entity/Entity.h"
#include "../Entity/EntityManager.h"
#include "../EntityComponents/CollisionComponent.h"
#include "../EntityComponents/PhysicsComponent.h"
#include "../EntityComponents/RenderComponent.h"
#include "../EntityComponents/InputComponent.h"
#include "../Level/LevelManager.h"
#include "../Level/Level.h"
#include "../Level/LevelArea.h"

extern LevelManager *gLevelManager;
extern EntityManager *gEntityManager;
extern GameInput *gGameInput;

class GameLoop
{
public:
   
	GameLoop() {}
	~GameLoop() {}

   void GameLoopInit();
   void GameLoopDestroy();
   void GameLoopRun();
   void GameLoopInput();
   void GameLoopUpdate(float deltaTInSeconds);
   void GameLoopRender();

public:

   sf::RenderWindow window;

public:

	LevelManager *levelManagerPtr;
	EntityManager *entityManagerPtr;
	GameInput *gameInputPtr;

};