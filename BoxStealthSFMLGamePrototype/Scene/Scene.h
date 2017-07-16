// Scene.h
#pragma once
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <stdlib.h>
#include <stdio.h>
#include <cmath>
#include <string>

enum SceneType
{
	Game,
	Menu,
	Console
};


class Scene
{
public:

	Scene() {}
	~Scene() {}

public:

	unsigned sceneID;
	SceneType sceneType;
	sf::View sceneView;
};