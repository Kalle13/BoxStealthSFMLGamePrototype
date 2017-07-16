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

struct KeyboardInputData
{
	char keyPressed_;
	char keyReleased_;

	void Init()
	{
		keyPressed_ = -2;
		keyReleased_ = -2;
	}
};

struct MouseInputData
{
	float mouseWheelDelta_;
	sf::Vector2i mousePosition_;
	char mouseButtonPressed_;
	char mouseButtonReleased_;
	
	void Init()
	{
		mouseButtonPressed_ = -1;
		mouseButtonReleased_ = -1;
		mouseWheelDelta_ = 0;
		mousePosition_ = sf::Vector2i(0, 0);
	}
};

struct ControllerInputData
{
	sf::Vector2f controllerLeftJoystickPos_;
	sf::Vector2f controllerRightJoystickPos_;
	char controllerButtonPressed_;
	char controllerButtonReleased_;

	void Init()
	{
		controllerButtonPressed_ = -1;
		controllerButtonReleased_ = -1;
		controllerLeftJoystickPos_ = sf::Vector2f(0, 0);
		controllerRightJoystickPos_ = sf::Vector2f(0, 0);
	}
};

struct ControllerInformation
{
	unsigned controllerID;
	unsigned numButtons;
	unsigned numJoysticks;
};

class GameInput
{
public:

	GameInput() {}
	~GameInput() {}

	void GameInputInitialize();
	void GameInputDestroy();

	// For efficiency, could have Update functions for Keyboard, Mouse, and Joystick, 
	// and a function pointer to call the function for the input method being used
	void UpdateInputState(sf::RenderWindow& window);
	void GetJoystickData();

public:

	KeyboardInputData keyboardInputData_;
	MouseInputData mouseInputData_;
	ControllerInputData controllerInputData_;

public:

	ControllerInformation controllerInformation_;
};