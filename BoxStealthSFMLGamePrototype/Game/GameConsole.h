// GameConsole.h
#pragma once
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <cmath>
#include <string>
#include "GameInput.h"

// GameConsole class (Singleton) is meant to display messages to the game window.
// For example, use to check current state of GameInput

struct DebugMessage
{
	sf::Vector2f textPosition;
	unsigned numCharacters;
	std::string message;
};

// May need way to enable/disable which messages are displayed -> Maybe use a "Sensitivity List" to turn on/off messages from different game systems

class GameConsole
{
public:

	GameConsole() {}
	~GameConsole() {}

	void GameConsoleInitialize();
	void GameConsoleUpdate();
	void GameConsoleDestroy();

public:

	sf::Font consoleFont;
	DebugMessage *debugMessages;

public:

	GameInput *gameInputPtr;

};
