// GameConsole.h
#pragma once
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <cmath>
#include "GameInput.h"

// GameConsole class (Singleton) is meant to display messages to the game window.
// For example, use to check current state of GameInput

// DebugTextFormat defines sf::Text and sf::Font used to display a debug message
struct DebugFontFormat
{
	float lineSpacing;
	sf::Font debugFont;
};


struct DebugMessage
{
	sf::Vector2f textPosition;
	unsigned numCharacters;
	char *message;
};


// May need way to enable/disable which messages are displayed -> Maybe use a "Sensitivity List" to turn on/off messages from different game systems

class GameConsole
{
public:

	GameConsole() {}
	~GameConsole() {}

	void GameConsoleInit();
	void GameConsoleUpdate();
	void GameConsoleDestroy();

public:

	sf::Font consoleFont;
	DebugMessage *debugMessages;

public:

	GameInput *gameInputPtr;

};
