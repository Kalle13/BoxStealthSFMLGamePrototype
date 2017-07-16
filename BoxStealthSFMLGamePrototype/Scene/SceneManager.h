// SceneManager.h
#pragma once
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <stdlib.h>
#include <stdio.h>
#include <cmath>
#include <string>
#include "Scene.h"
#include "../Entity/EntityManager.h"
#include "../Level/LevelManager.h"

class Scene;
class EntityManager;
class LevelManager;

class SceneManager
{
public:

	SceneManager() {}
	~SceneManager() {}

	void SceneManagerInitialize();
	void SceneManagerDestroy();

	void DrawScene();
	void ChangeScene(unsigned sceneID);

public:

	unsigned currentSceneID;

public:

	EntityManager *entityManagerPtr;
	LevelManager *levelManagerPtr;

};