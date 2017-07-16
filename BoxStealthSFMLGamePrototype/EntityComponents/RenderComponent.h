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

#define DEFAULT_MESH_COLOR (0x777777FF)
#define DEFAULT_TRIANGLE_MESH_WIDTH (32)
#define DEFAULT_TRIANGLE_MESH_HEIGHT (32)
#define DEFAULT_QUAD_MESH_WIDTH (32)
#define DEFAULT_QUAD_MESH_HEIGHT (32)
#define DEFAULT_QUAD_ORIGIN (sf::Vector2f(DEFAULT_QUAD_MESH_WIDTH/2.0, DEFAULT_QUAD_MESH_HEIGHT/2.0))
#define DEFAULT_QUAD_VERTEX_COORD_1 (sf::Vector2f(0,0))
#define DEFAULT_QUAD_VERTEX_COORD_2 (sf::Vector2f(DEFAULT_QUAD_MESH_WIDTH,0))
#define DEFAULT_QUAD_VERTEX_COORD_3 (sf::Vector2f(DEFAULT_QUAD_MESH_WIDTH,DEFAULT_QUAD_MESH_HEIGHT))
#define DEFAULT_QUAD_VERTEX_COORD_4 (sf::Vector2f(0,DEFAULT_QUAD_MESH_HEIGHT))
#define DEFAULT_TRIANGLE_ORIGIN (sf::Vector2f(DEFAULT_TRIANGLE_MESH_WIDTH / 2.0, DEFAULT_TRIANGLE_MESH_HEIGHT * (1.0 - ((float)sqrt((double)3.0) / 2.0))))
#define DEFAULT_TRIANGLE_VERTEX_COORD_1 (sf::Vector2f(0,0))
#define DEFAULT_TRIANGLE_VERTEX_COORD_2 (sf::Vector2f(DEFAULT_TRIANGLE_MESH_WIDTH,0))
#define DEFAULT_TRIANGLE_VERTEX_COORD_3 (sf::Vector2f(DEFAULT_TRIANGLE_MESH_WIDTH,DEFAULT_TRIANGLE_MESH_HEIGHT))

class RenderComponent : public EntityComponent
{
public:

	RenderComponent() {}
	~RenderComponent() {}

	virtual void Initialize() override;
	virtual void Update(float deltaTInSeconds) override;
	virtual void Destroy() override;

	void Draw(sf::RenderWindow& drawWindow);

	void UpdateMesh(sf::Vector2f& newOrigin, 
					unsigned newVertexCount, 
					sf::Vector2f *newVertexPositionsArray, 
					sf::PrimitiveType& newPrimType);
	// Update Quad Mesh texCoords
	void UpdateMeshTextureCoordsWithVector(sf::Vector2f *coordsPtr);	// pass an pointer to an array of new texture coords for updating mesh's texCoords
	void UpdateMeshTextureCoordsWithIndexVector(sf::Vector2f& textureIndexVector);	// pass a vector with (x,y) indices corresponding to the location of the new texture on a tilemap/spritesheet
	void UpdateRenderPositionAndAngle(sf::Vector2f& position, float& angle);

public:

	unsigned numVertices;
	float renderAngle;
	sf::Vector2f renderOrigin;
	sf::PrimitiveType primitiveType;
	sf::VertexArray mesh;
	sf::Vector2f *meshTextureCoords;	// assumed to have same number of texture coordinates as vertices

public:

	sf::RenderStates renderStates;
	sf::Transform transform;	// a transform to enable Physics component data to effect render component data
	sf::Texture *texture;	// pointer to texture will be assigned by EntityManger, EntityFactory, or manually (but not in Initialize() method)
};