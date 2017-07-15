// EntityComponent.h
#pragma once
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <cmath>


class EntityComponent
{
public:

	EntityComponent() {}
	~EntityComponent() {}

	virtual void Initialize() = 0;
	virtual void Update(float deltaTInSeconds) = 0;
	virtual void Destroy() = 0;

};