// InputComponent.h
#pragma once
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <cmath>
#include "../Game/GameInput.h"

class GameInput;

class InputComponent
{
public:

	InputComponent() {};
	~InputComponent() {};

	virtual void InputComponentInit() = 0;
	virtual void InputComponentUpdate() = 0;
	virtual void InputComponentDestroy() = 0;

public:

	GameInput *gameInputPtr;

};
