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
#include "../Scene/Scene.h"
#include "../Entity/Entity.h"
#include "../Level/Level.h"

class Scene;
class RenderComponent;

class GameWindow
{
public:

	GameWindow() {}
	~GameWindow() {}

	void Initialize();	
	void Update();	
	void Destroy();

	bool WindowIsOpen();
	void CloseWindow();
	void Clear(sf::Color clearWindowColor);
	void Display();

public:

	unsigned windowWidth_;
	unsigned windowHeight_;
	std::string gameWindowTitle_;
	sf::VideoMode videoMode_;
	sf::RenderWindow gameWindow_;

};