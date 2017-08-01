// Vector2Utility.h
#pragma once
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include "../Systems/CollisionSystem.h"

#define PI 3.141592654

/*------------------------------------------------------------------------------------------------*/
/*---------------------------------------Physics Functions----------------------------------------*/
/*------------------------------------------------------------------------------------------------*/

float Vector2Magnitude(sf::Vector2f vector);
float Vector2Dot(sf::Vector2f vector1, sf::Vector2f vector2);
float Vector2CrossProductSignedMagnitude(sf::Vector2f vector1, sf::Vector2f vector2);

// Vector2ArrayAverage: Returns the average vector from an array of vectors
sf::Vector2f Vector2ArrayAverage(sf::Vector2f *vector2Array, unsigned numVectors);
sf::Vector2f VertexArrayVector2Average(sf::Vertex *vertexArray, int numVertices);

// DistanceToFarthestVector2FromPoint: Returns the magnitude of the distance from a vector point to the farthest vector in an array
float DistanceToFarthestVector2FromPoint(sf::Vector2f *vector2Array, unsigned numVectorsInArray, sf::Vector2f pointVector);

// Use SmoothDisplacement inside of an sf::Transform "translate()" function to move an object smoothly
// e.g. sf::Transform transfrom.translate(SmoothDisplacement(iVec, fVec, 10.0, deltaT));
sf::Vector2f SmoothDisplacement(sf::Vector2f initialPositionVector,
	sf::Vector2f finalPositionVector,
	float speed,
	float deltaTimeInSeconds);


/*------------------------------------------------------------------------------------------------*/
/*-------------------------------------Collision Functions----------------------------------------*/
/*------------------------------------------------------------------------------------------------*/

sf::Vector2f FindClosestVertexToVector2(sf::Vector2f vector, sf::Vertex *vertexArray, int vertexCount);
sf::Vector2f FindSecondClosestVertexToVector2(sf::Vector2f vector, sf::Vertex *vertexArray, int vertexCount);
sf::Vector2f FurthestVertexFromVector2(sf::Vector2f vector, sf::Vertex *vertexArray, int vertexCount);
sf::Vector2f Vector2Project(sf::Vector2f aVec, sf::Vector2f bVec);
int IndexOfClosestVertexToVector2(sf::Vector2f vector, sf::Vertex *vertexArray, int vertexCount);
int IndexOfSecondClosestVertexToVector2(sf::Vector2f vector, sf::Vertex *vertexArray, int vertexCount);