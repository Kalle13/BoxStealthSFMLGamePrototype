// GameWindow.h
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
#include "../Scene/Scene.h"
#include "../Entity/Entity.h"
#include "../Level/Level.h"

class GameInput;
class Scene;
class RenderComponent;

class GameWindow
{
public:

	GameWindow() {}
	~GameWindow() {}

	void Initialize(GameInput *initGameInputPtr);	
	void Update();	
	void Destroy();

	bool WindowIsOpen();
	void Draw();
	/*
	void DrawScene(Scene& scene);
	void DrawEntity(Entity& entity);
	void DrawLevel(Level& level);
	*/

public:

	unsigned windowWidth;
	unsigned windowHeight;
	std::string gameWindowTitle;
	sf::VideoMode videoMode;
	sf::RenderWindow gameWindow;
	
public:

	GameInput *gameInputPtr;
	RenderComponent *renderComponentPtr;

};