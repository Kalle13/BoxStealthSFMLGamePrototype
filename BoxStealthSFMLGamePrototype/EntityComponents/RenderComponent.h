// RenderComponent.h
#pragma once
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <cmath>

class RenderComponent
{
public:

	RenderComponent() {}
	~RenderComponent() {}

	virtual void RenderComponentInit() = 0;
	virtual void RenderComponentUpdate(float deltaTInSeconds) = 0;
	virtual void RenderComponentDestroy() = 0;

public:

	unsigned numVertices;
	sf::PrimitiveType primitiveType;
	sf::VertexArray mesh;

};