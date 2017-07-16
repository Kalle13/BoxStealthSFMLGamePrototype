// GameConsole.cpp
#include "GameConsole.h"

// font: calibri.tff
//"C:\Users\Kalle13\Documents\Visual Studio 2017\Projects\BoxStealthSFMLGamePrototype\BoxStealthSFMLGamePrototype\Resources\Fonts\calibri.ttf"

void GameConsole::GameConsoleInitialize()
{	
	if (!consoleFont.loadFromFile("../Resources/Fonts/calibri.ttf")){
		printf("(GameConsole::GameConsoleInit) Error: Failed to load font\n");
	}

}


void GameConsole::GameConsoleUpdate()
{


}


void GameConsole::GameConsoleDestroy()
{


}