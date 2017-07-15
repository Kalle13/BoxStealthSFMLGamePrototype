// GameInput.h
#pragma once
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <cmath>

enum InputType
{
	KeyPressed,
	KeyReleased,
	MouseButtonPressed,
	MouseButtonReleased,
	ControllerButtonPressed,
	ControllerButtonReleased,
	ControllerMoved
};


class GameInput
{
public:

	GameInput() {}
	~GameInput() {}

	void GameInputInit();
	void GameInputDestroy();

public:

	unsigned keyboardPressedFlags;
	unsigned keyboardReleasedFlags;
	unsigned mouseButtonFlags;
	unsigned controllerButtonFlags;
	sf::Vector2f controllerLeftJoystickPos;
	sf::Vector2f controllerrightJoystickPos;

public:

	unsigned numControllerButtons;
	unsigned numControllerJoysticks;
};