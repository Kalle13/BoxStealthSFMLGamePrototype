// GameLoop.h
#pragma once

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <stdlib.h>
#include <stdio.h>
#include <cmath>

class GameLoop
{
public:

   sf::RenderWindow window;

   GameLoop();
   ~GameLoop();

   void GameLoopInit();
   void GameLoopDestroy();
   void ProcessEvents();
   void Update(float deltaT);
   void Render();
};