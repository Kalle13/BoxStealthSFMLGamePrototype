// LevelArea.h
#pragma once
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <cmath>

// A LevelArea is a section of a level that consists of visual/render information (colors, textures), and 
// level boundary/surface information (boundary/surface vertices). 

// An array of both Render and Vertex data will be used to construct the any parts of a level area.

// Used to "paint" area boundary/surface vertices
struct AreaRenderData
{
	sf::Color areaColors;
	sf::Texture areaTexture;
};

// Used to construct specific objects in an area (e.g. a rectangle in a platformer game that can be jumped on)
struct AreaVertexData
{
	unsigned numVertices;
	sf::PrimitiveType areaPrimitiveType;
	sf::VertexArray areaVertices;
};

class LevelArea
{
public:

	LevelArea() {}
	~LevelArea() {}

	virtual void LevelAreaInit() = 0;
	virtual void LevelAreaUpdate() = 0;
	virtual void LevelAreaDestroy() = 0;

public:

	AreaVertexData *areaVertexDataArray;
	AreaRenderData *areaRenderDataArray;

};
