#include "Game.h"

GameLoop::GameLoop()
{
   printf("Game constructor\n");
}

GameLoop::~GameLoop()
{
   printf("Game destructor\n");
}

void GameLoop::GameLoopInit()
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
         ProcessEvents();
         Update(timePerFrame.asSeconds());
      }

      Render();
   }
}

void GameLoop::GameLoopDestroy()
{
	
}

void GameLoop::ProcessEvents()
{

   sf::Event event;
   while(window.pollEvent(event))
   {
      if(event.type == sf::Event::Closed)
      {
         window.close();
      }
   }

}

void GameLoop::Update(float deltaT)
{

}

void GameLoop::Render()
{
   window.clear(sf::Color::Black);

   window.display();
}
