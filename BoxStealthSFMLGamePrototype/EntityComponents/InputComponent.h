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
#include "EntityComponent.h"

class GameInput;

class InputComponent : public EntityComponent
{
public:

	InputComponent() {};
	~InputComponent() {};

	virtual void Initialize() override;
	virtual void Update(float deltaTInSeconds) override;
	virtual void Destroy() override;

public:

	GameInput *gameInputPtr;

};
