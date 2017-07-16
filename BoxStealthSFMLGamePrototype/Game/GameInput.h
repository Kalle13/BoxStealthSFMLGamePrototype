// GameInput.h
#pragma once
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <cmath>

enum InputEventType
{
	KeyPressed,
	KeyReleased,
	MouseButtonPressed,
	MouseButtonReleased,
	ControllerButtonPressed,
	ControllerButtonReleased,
	ControllerJoystickRightMoved,
	ControllerJoystickLeftMoved
};

class GameInput
{
public:

	GameInput() {}
	~GameInput() {}

	void GameInputInitialize();
	void GameInputDestroy();

public:

	unsigned keyboardPressedFlags;
	unsigned keyboardReleasedFlags;
	unsigned mouseButtonPressedFlags;
	unsigned mouseButtonReleasedFlags;
	float mouseWheelDelta;
	unsigned controllerButtonPressedFlags;
	unsigned controllerButtonReleasedFlags;
	sf::Vector2i mousePosition;
	sf::Vector2f controllerLeftJoystickPos;
	sf::Vector2f controllerRightJoystickPos;

public:

	unsigned numControllerButtons;
	unsigned numControllerJoysticks;
};