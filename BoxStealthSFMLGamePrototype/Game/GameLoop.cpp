// GameLoop.cpp
#include "GameLoop.h"

void GameLoop::GameLoopInit()
{
	gameInputPtr = gGameInputPtr;
	gameConsolePtr = gGameConsolePtr;
	gameWindowPtr = gGameWindowPtr;
	sceneManagerPtr = gSceneManagerPtr;
	levelManagerPtr = gLevelManagerPtr;
	entityManagerPtr = gEntityManagerPtr;
	
	sceneManagerPtr->entityManagerPtr = gEntityManagerPtr;
	sceneManagerPtr->levelManagerPtr = gLevelManagerPtr;

	gameConsolePtr->gameInputPtr = gGameInputPtr;
	entityManagerPtr->gameInputPtr = gGameInputPtr;

	// Initialize various systems
	gameInputPtr->GameInputInitialize();
	gameConsolePtr->GameConsoleInitialize();
	gameWindowPtr->Initialize();
	//entityManagerPtr->EntityManagerInitialize();
	//levelManagerPtr->LevelManagerInitialize();
	

}

void GameLoop::GameLoopDestroy()
{
	gameInputPtr->GameInputDestroy();
	gameConsolePtr->GameConsoleDestroy();
	gameWindowPtr->Destroy();
	sceneManagerPtr->SceneManagerDestroy();
	//entityManagerPtr->EntityManagerDestroy();
	//levelManagerPtr->LevelManagerDestroy();
}

void GameLoop::GameLoopRun()
{
   sf::Clock gameClock;
   sf::Time timeSinceLastUpdate = sf::Time::Zero;
   sf::Time timePerFrame = sf::seconds(1.f/60.f);

   while(gameWindowPtr->WindowIsOpen())
   {
      timeSinceLastUpdate += gameClock.restart();

      while(timeSinceLastUpdate > timePerFrame)
      {
         timeSinceLastUpdate -= timePerFrame;
         GameLoopInput();
         GameLoopUpdate(timePerFrame.asSeconds());
      }

      GameLoopRender();
   }
}


void GameLoop::GameLoopInput()
{
	gameWindowPtr->CheckForInputEvents();
}

void GameLoop::GameLoopUpdate(float deltaTInSeconds)
{

}

void GameLoop::GameLoopRender()
{
	gameWindowPtr->gameWindow.clear(sf::Color::Black);

	// Draw stuff here

	gameWindowPtr->gameWindow.display();
}
