// LevelManager.h
#pragma once
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <cmath>
#include "Level.h"

class Level;

// LevelManager will be a Singleton object

class LevelManager
{
public:

	LevelManager() {}
	~LevelManager() {}

	void LevelManagerInit();
	void LevelManagerUpdate();
	void LevelManagerDestroy();

public:

	unsigned numLevels;
	Level *levels;
};