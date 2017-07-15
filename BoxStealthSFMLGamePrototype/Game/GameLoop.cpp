// GameLoop.cpp
#include "GameLoop.h"

void GameLoop::GameLoopInit()
{
	entityManagerPtr = gEntityManager;
	gameInputPtr = gGameInput;




}

void GameLoop::GameLoopRun()
{

   sf::VideoMode videoMode(800,600);
   window.create(videoMode,"Game Window");

   sf::Clock gameClock;
   sf::Time timeSinceLastUpdate = sf::Time::Zero;
   sf::Time timePerFrame = sf::seconds(1.f/60.f);

   while(window.isOpen())
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

void GameLoop::GameLoopDestroy()
{
	
}

void GameLoop::GameLoopInput()
{

   sf::Event event;
   while(window.pollEvent(event))
   {
      if(event.type == sf::Event::Closed)
      {
         window.close();
      }
	  if (event.type == sf::Event::KeyPressed)
	  {
		  gameInputPtr->
	  }
	  if (event.type == sf::Event::KeyReleased)
	  {

	  }

   }

}

void GameLoop::GameLoopUpdate(float deltaTInSeconds)
{

}

void GameLoop::GameLoopRender()
{
   window.clear(sf::Color::Black);

   window.display();
}
