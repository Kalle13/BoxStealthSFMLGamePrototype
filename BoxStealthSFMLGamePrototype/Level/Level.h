// Level.h
#pragma once
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <cmath>
#include "LevelArea.h"

class LevelArea;

class Level
{
public:

	Level() {}
	~Level() {}

	virtual void LevelInit() = 0;
	virtual void LevelUpdate() = 0;
	virtual void LevelDestroy() = 0;

public:

	unsigned numLevelAreas;
	LevelArea *levelAreaArray;

};
