// Vector2Utility.cpp
#include "Vector2Utility.h"

/*------------------------------------------------------------------------------------------------*/
/*---------------------------------------Physics Functions----------------------------------------*/
/*------------------------------------------------------------------------------------------------*/

float Vector2Magnitude(sf::Vector2f vector)
{
	float magnitude = sqrt(vector.x*vector.x + vector.y*vector.y);
	if (magnitude > 0) {
		return magnitude;
	}
	return -1.0;
}

float Vector2Dot(sf::Vector2f vector1, sf::Vector2f vector2)
{
	return vector1.x*vector2.x + vector1.y*vector2.y;
}

float Vector2CrossProductSignedMagnitude(sf::Vector2f vector1, sf::Vector2f vector2)
{
	return vector1.x*vector2.y - vector1.y*vector2.x;

	/* the following cross product calculations may be useful in 3 dimensions (add a 'z' component)

	float vector1SquaredMagnitude = vector1.x*vector1.x + vector1.y*vector1.y;
	float vector2SquaredMagnitude = vector2.x*vector2.x + vector2.y*vector2.y;
	float dotProductOfVectors = vector1.x*vector2.x + vector1.y*vector2.y;

	crossProductMagnitude = sqrt(vector1SquaredMagnitude*vector2SquaredMagnitude - dotProductOfVectors*dotProductOfVectors);
	*/
}

sf::Vector2f Vector2ArrayAverage(sf::Vector2f *vector2Array, unsigned numVectors)
{
	sf::Vector2f averageVector = sf::Vector2f(0, 0);

	for (unsigned i = 0; i < numVectors; ++i) {
		averageVector += vector2Array[i];
	}

	averageVector = sf::Vector2f(averageVector.x / numVectors, averageVector.y / numVectors);

	return averageVector;
}

sf::Vector2f VertexArrayVector2Average(sf::Vertex *vertexArray, int numVertices)
{
	sf::Vector2f averageVector = sf::Vector2f(0, 0);

	for (int i = 0; i < numVertices; ++i) {
		averageVector += vertexArray[i].position;
	}

	averageVector = sf::Vector2f(averageVector.x / numVertices, averageVector.y / numVertices);

	return averageVector;
}

float DistanceToFarthestVector2FromPoint(sf::Vector2f *vector2Array, unsigned numVectorsInArray, sf::Vector2f pointVector)
{
	float furthestDistance = 0;
	float tempDistance = 0;
	sf::Vector2f differenceVector;

	for (unsigned i = 0; i < numVectorsInArray; ++i) {
		differenceVector = vector2Array[i] - pointVector;
		tempDistance = sqrt(differenceVector.x*differenceVector.x + differenceVector.y*differenceVector.y);
		if (tempDistance > furthestDistance) {
			furthestDistance = tempDistance;
		}
	}

	return furthestDistance;
}

sf::Vector2f SmoothDisplacement(sf::Vector2f initialPositionVector, sf::Vector2f finalPositionVector, float speed, float deltaTimeInSeconds)
{
	sf::Vector2f displacementVector = speed*deltaTimeInSeconds*(finalPositionVector - initialPositionVector);
	float displacementMagnitude = Vector2Magnitude(finalPositionVector - initialPositionVector);

	if (displacementMagnitude < 0.00000001) {
		displacementVector = sf::Vector2f(0, 0);
	}

	return displacementVector;
}


/*------------------------------------------------------------------------------------------------*/
/*-------------------------------------Collision Functions----------------------------------------*/
/*------------------------------------------------------------------------------------------------*/

sf::Vector2f FindClosestVertexToVector2(sf::Vector2f vector, sf::Vertex *vertexArray, int vertexCount)
{
	sf::Vector2f closestVector = vertexArray[0].position;
	float distanceBetweenVectors;
	float minDistanceBetweenVectors = Vector2Magnitude(closestVector - vector);

	for (int i = 0; i < vertexCount; ++i) {
		distanceBetweenVectors = Vector2Magnitude(vertexArray[i].position - vector);
		if (distanceBetweenVectors < minDistanceBetweenVectors) {
			minDistanceBetweenVectors = distanceBetweenVectors;
			closestVector = vertexArray[i].position;
		}
	}

	return closestVector;
}

sf::Vector2f FindSecondClosestVertexToVector2(sf::Vector2f vector, sf::Vertex *vertexArray, int vertexCount)
{
	sf::Vector2f closestVector = FindClosestVertexToVector2(vector, vertexArray, vertexCount);
	sf::Vector2f secondClosestVector = FurthestVertexFromVector2(vector, vertexArray, vertexCount);
	float closestVectorDistance = Vector2Magnitude(closestVector - vector);
	float secondClosestVectorDistance = Vector2Magnitude(secondClosestVector - vector);
	float distanceBetweenVectors;


	for (int i = 0; i < vertexCount; ++i) {
		distanceBetweenVectors = Vector2Magnitude(vertexArray[i].position - vector);
		if ((distanceBetweenVectors > closestVectorDistance) && (distanceBetweenVectors < secondClosestVectorDistance)) {
			secondClosestVectorDistance = distanceBetweenVectors;
			secondClosestVector = vertexArray[i].position;
		}
	}

	return secondClosestVector;
}

sf::Vector2f FurthestVertexFromVector2(sf::Vector2f vector, sf::Vertex *vertexArray, int vertexCount)
{
	sf::Vector2f furthestVector = sf::Vector2f(0, 0);
	float furthestDistance = 0;
	float distanceToVector;

	for (int i = 0; i < vertexCount; ++i) {
		distanceToVector = Vector2Magnitude(vertexArray[i].position - vector);
		if (distanceToVector > furthestDistance) {
			furthestDistance = distanceToVector;
			furthestVector = vertexArray[i].position;
		}
	}

	return furthestVector;
}

sf::Vector2f Vector2Project(sf::Vector2f aVec, sf::Vector2f bVec)
{
	float aX = aVec.x;
	float aY = aVec.y;
	float bX = bVec.x;
	float bY = bVec.y;

	float aDotB = aX*bX + aY*bY;
	float bSquared = bX*bX + bY*bY;
	if (abs(bSquared) > 0) {
		return (aDotB / bSquared)*bVec;
	}
	else {
		return sf::Vector2f(-1.0, -1.0);
	}
}

int IndexOfClosestVertexToVector2(sf::Vector2f vector, sf::Vertex *vertexArray, int vertexCount)
{
	float distanceBetweenVectors;
	float minDistanceBetweenVectors = Vector2Magnitude(vertexArray[0].position - vector);
	int indexOfClosestVertex = 0;

	for (int i = 0; i < vertexCount; ++i) {
		distanceBetweenVectors = Vector2Magnitude(vertexArray[i].position - vector);
		if (distanceBetweenVectors < minDistanceBetweenVectors) {
			minDistanceBetweenVectors = distanceBetweenVectors;
			indexOfClosestVertex = i;
		}
	}

	return indexOfClosestVertex;
}

int IndexOfSecondClosestVertexToVector2(sf::Vector2f vector, sf::Vertex *vertexArray, int vertexCount)
{
	float closestVectorDistance = Vector2Magnitude(FindClosestVertexToVector2(vector, vertexArray, vertexCount) - vector);
	float secondClosestVectorDistance = Vector2Magnitude(FurthestVertexFromVector2(vector, vertexArray, vertexCount) - vector);
	float distanceBetweenVectors;
	int indexOfSecondClosestVertex = 0;

	for (int i = 0; i < vertexCount; ++i) {
		distanceBetweenVectors = Vector2Magnitude(vertexArray[i].position - vector);
		if ((distanceBetweenVectors > closestVectorDistance) && (distanceBetweenVectors < secondClosestVectorDistance)) {
			secondClosestVectorDistance = distanceBetweenVectors;
			indexOfSecondClosestVertex = i;
		}
	}

	return indexOfSecondClosestVertex;
}
