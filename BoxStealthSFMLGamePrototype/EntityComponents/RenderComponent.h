// RenderComponent.h
#pragma once
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <cmath>
#include "EntityComponent.h"

class RenderComponent : public EntityComponent
{
public:

	RenderComponent() {}
	~RenderComponent() {}

	virtual void Initialize() override;
	virtual void Update(float deltaTInSeconds) override;
	virtual void Destroy() override;

public:

	unsigned numVertices;
	sf::PrimitiveType primitiveType;
	sf::VertexArray mesh;

};