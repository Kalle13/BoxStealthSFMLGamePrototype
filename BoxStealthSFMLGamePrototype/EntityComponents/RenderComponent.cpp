// RenderComponent.cpp
#include "RenderComponent.h"

void RenderComponent::Initialize()
{
	numVertices = 4;
	primitiveType = sf::Quads;
	mesh.resize(numVertices);
	mesh.setPrimitiveType(primitiveType);	

	meshTextureCoords = (sf::Vector2f*)malloc(numVertices * sizeof(sf::Vector2f));

	if (meshTextureCoords == NULL) {
		printf("(RenderComponent::Initialize) Error: Failed to allocate memory for mesh texture coordinates\n");
	}

	renderAngle = 0;
	renderOrigin = DEFAULT_QUAD_ORIGIN;
	mesh[0].position = DEFAULT_QUAD_VERTEX_COORD_1;
	mesh[1].position = DEFAULT_QUAD_VERTEX_COORD_2;
	mesh[2].position = DEFAULT_QUAD_VERTEX_COORD_3;
	mesh[3].position = DEFAULT_QUAD_VERTEX_COORD_4;
	mesh[0].texCoords = DEFAULT_QUAD_VERTEX_COORD_1;
	mesh[1].texCoords = DEFAULT_QUAD_VERTEX_COORD_2;
	mesh[2].texCoords = DEFAULT_QUAD_VERTEX_COORD_3;
	mesh[3].texCoords = DEFAULT_QUAD_VERTEX_COORD_4;
	
	if (meshTextureCoords != NULL) {
		meshTextureCoords[0] = DEFAULT_QUAD_VERTEX_COORD_1;
		meshTextureCoords[1] = DEFAULT_QUAD_VERTEX_COORD_2;
		meshTextureCoords[2] = DEFAULT_QUAD_VERTEX_COORD_3;
		meshTextureCoords[3] = DEFAULT_QUAD_VERTEX_COORD_4;
	}

}

void RenderComponent::Update(float deltaTInSeconds)
{
	// No time-dependent changes at this time
	// Time-dependence may be required for animations though
}

void RenderComponent::Destroy()
{
	if (meshTextureCoords != NULL) {
		free(meshTextureCoords);
	}
}

void RenderComponent::UpdateMesh(sf::Vector2f& newOrigin, unsigned newVertexCount, sf::Vector2f *newVertexPositionsArray, sf::PrimitiveType& newPrimType)
{
	renderOrigin = newOrigin;
	numVertices = newVertexCount;
	
	mesh.resize(newVertexCount);
	mesh.setPrimitiveType(newPrimType);

	for (unsigned i = 0; i < newVertexCount; ++i) {
		mesh[i].position = newVertexPositionsArray[i];
	}
}

void RenderComponent::UpdateMeshTextureCoordsWithVector(sf::Vector2f *coordsPtr)
{
	for (unsigned i = 0; i < numVertices; ++i) {
		mesh[i].texCoords = coordsPtr[i];
	}
}

void RenderComponent::UpdateMeshTextureCoordsWithIndexVector(sf::Vector2f& textureIndexVector)
{
	for (unsigned i = 0; i < numVertices; ++i) {
		mesh[i].texCoords += sf::Vector2f(textureIndexVector.x*DEFAULT_QUAD_MESH_WIDTH, 
										  textureIndexVector.y*DEFAULT_QUAD_MESH_HEIGHT);
	}
}

void RenderComponent::UpdateRenderPositionAndAngle(sf::Vector2f& position, float& angle)
{
	renderAngle = angle;
	renderOrigin = position;
	// translate then rotate; will this properly rotate mesh vertices?
	transform.translate(renderOrigin);
	transform.rotate(renderAngle, renderOrigin);
	renderStates.transform = transform;
	transform = sf::Transform::Identity; // reset transform so that next transform is purely a rotation by renderAngle, and a translation by renderOrigin
}

void RenderComponent::Draw(sf::RenderWindow& drawWindow)
{
	drawWindow.draw(mesh,renderStates);
}
