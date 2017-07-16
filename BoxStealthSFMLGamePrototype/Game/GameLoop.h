// GameLoop.h
#pragma once
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <stdlib.h>
#include <stdio.h>
#include <cmath>
#include "GameWindow.h"
#include "GameInput.h"
#include "GameConsole.h"
#include "../Scene/SceneManager.h"
#include "../Scene/Scene.h"
#include "../Entity/EntityManager.h"
#include "../Entity/Entity.h"
#include "../EntityComponents/CollisionComponent.h"
#include "../EntityComponents/PhysicsComponent.h"
#include "../EntityComponents/RenderComponent.h"
#include "../EntityComponents/InputComponent.h"
#include "../Level/LevelManager.h"
#include "../Level/Level.h"
#include "../Level/LevelArea.h"

extern GameWindow *gGameWindowPtr;
extern GameInput *gGameInputPtr;
extern GameConsole *gGameConsolePtr;
extern SceneManager *gSceneManagerPtr;
extern LevelManager *gLevelManagerPtr;
extern EntityManager *gEntityManagerPtr;

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

	GameInput *gameInputPtr;
	GameConsole *gameConsolePtr;
	GameWindow *gameWindowPtr;
	SceneManager *sceneManagerPtr;
	LevelManager *levelManagerPtr;
	EntityManager *entityManagerPtr;

};