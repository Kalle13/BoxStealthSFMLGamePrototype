#include "CollisionSystem.h"

void CollisionSystem::Initialize()
{
	printf("[CollisionSystem::Initialize]\n");

	numCollisionObjects = 0;
	numCollisionFlags = 0;
	currentCollisionObjectID = 0;
	
	collisionObjectArrayElementToIDMap = (int*)malloc(MAX_NUM_COLLISION_OBJECTS * sizeof(int));

	collisionObjectArray = (CollisionData*)malloc(MAX_NUM_COLLISION_OBJECTS * sizeof(CollisionData));
		
	collisionFlagArray = (CollisionFlag*)malloc(MAX_NUM_COLLISION_FLAGS * sizeof(CollisionFlag));
}

void CollisionSystem::Destroy()
{
	if (collisionObjectArray != NULL) {
		free(collisionObjectArray);
	}	

	if (collisionFlagArray != NULL) {
		free(collisionFlagArray);
	}

	if (collisionObjectArrayElementToIDMap != NULL) {
		free(collisionObjectArrayElementToIDMap);
	}

	printf("[CollisionSystem::Destroy]\n");
}

void CollisionSystem::RunCollisionDetection()
{
	// For collision object A, find closest collision vertex of object B to object A.
	// If closest B vertex is closer to A's average vector than any of A's vertices, then there is a collision.

	for (int i = 0; i < numCollisionObjects; ++i) {
		for (int j = i + 1; j < numCollisionObjects; ++j) {

			
			// Should maybe combine FindClosestVertexToVector2 and IndexOfClosestVertexVector2 
			// into one function with pointer args: *closestVector, *closestIndex.

			sf::Vector2f collidingVertexVector = FindClosestVertexToVector2(collisionObjectArray[i].boundsAverageVector,
																			collisionObjectArray[j].collisionVerticesArray,
																			collisionObjectArray[j].numVertices);			

			int indexOfCollidingVertex = IndexOfClosestVertexToVector2(collisionObjectArray[i].boundsAverageVector,
																	   collisionObjectArray[j].collisionVerticesArray,
																	   collisionObjectArray[j].numVertices);

			sf::Vector2f primaryIncidentVertexVector = FindClosestVertexToVector2(collidingVertexVector,
																				  collisionObjectArray[i].collisionVerticesArray,
																				  collisionObjectArray[i].numVertices);

			int indexOfPrimaryIncidentVertex = IndexOfClosestVertexToVector2(collidingVertexVector,
																			 collisionObjectArray[i].collisionVerticesArray,
																			 collisionObjectArray[i].numVertices);

			sf::Vector2f secondaryIncidentVertexVector = FindSecondClosestVertexToVector2(collidingVertexVector,
																						  collisionObjectArray[i].collisionVerticesArray,
																						  collisionObjectArray[i].numVertices);

			int indexOfSecondaryIncidentVertex = IndexOfSecondClosestVertexToVector2(collidingVertexVector,
																						   collisionObjectArray[i].collisionVerticesArray,
																						   collisionObjectArray[i].numVertices);

			sf::Vector2f incidentObjectAverageVector = collisionObjectArray[i].boundsAverageVector;

			// Need to use two closest A vertex vectors to B vertex vector to project B vertex vector
			// onto difference vector of two A vectors. Then determine if B vector is closer to A avg vector than
			// projected B vector (meaning B vector is inside object A, and a collision has occurred).

			sf::Vector2f projectedCollidingVertexOntoIncidentObjectBounds = Vector2Project(collidingVertexVector - secondaryIncidentVertexVector, primaryIncidentVertexVector - secondaryIncidentVertexVector) + secondaryIncidentVertexVector;

			float magnitudeCollidingVectorToObjectAverageVector = Vector2Magnitude(incidentObjectAverageVector - collidingVertexVector);
			float magnitudeProjectedCollidingVectorToObjectAverageVector = Vector2Magnitude(incidentObjectAverageVector - projectedCollidingVertexOntoIncidentObjectBounds);

			if (magnitudeCollidingVectorToObjectAverageVector < magnitudeProjectedCollidingVectorToObjectAverageVector) {
					AddCollisionFlag(collisionObjectArray[i].collisionDataID,
									 collisionObjectArray[j].collisionDataID,
									 primaryIncidentVertexVector,
									 collidingVertexVector);
			}

			// Change CollisionObject element vertex colors based on collision/proximity to other CollisionObject elements
			// Reset vertex colors
			for (int i = 0; i < numCollisionObjects; ++i) {
				int numVertices = collisionObjectArray[i].numVertices;
				int collisionObjectID = collisionObjectArray[i].collisionDataID;
				for (int j = 0; j < numVertices; ++j) {

					int colorInteger = 255 - (collisionObjectID * 7);
					colorInteger %= 255;

					sf::Color objectColor = sf::Color(colorInteger, colorInteger, colorInteger, 255);

					collisionObjectArray[i].collisionVerticesArray[j].color = objectColor;
				}
			}

			// Change color of closest vertices
			collisionObjectArray[i].collisionVerticesArray[indexOfPrimaryIncidentVertex].color = sf::Color::Blue;
			collisionObjectArray[i].collisionVerticesArray[indexOfSecondaryIncidentVertex].color = sf::Color::Yellow;
			collisionObjectArray[j].collisionVerticesArray[indexOfCollidingVertex].color = sf::Color::Green;

			// Change entire object color if there is a collision			
			for (int i = 0; i < numCollisionFlags; ++i) {
				int collisionID1 = collisionFlagArray[i].collisionDataID1;
				int collisionID2 = collisionFlagArray[i].collisionDataID2;
				for (int j = 0; j < numCollisionObjects; ++j) {
					// Change CollisionObject with ID1 to Magenta
					if (collisionObjectArray[j].collisionDataID == collisionID1) {
						for (int k = 0; k < collisionObjectArray[j].numVertices; ++k) {
							collisionObjectArray[j].collisionVerticesArray[k].color = sf::Color::Magenta;
						}
					} // Change CollisionObject with ID2 to Cyan
					else if (collisionObjectArray[j].collisionDataID == collisionID2) {
						for (int k = 0; k < collisionObjectArray[j].numVertices; ++k) {
							collisionObjectArray[j].collisionVerticesArray[k].color = sf::Color::Cyan;
						}
					}
				}
			}

		}
	}
}

void CollisionSystem::AddCollisionFlag(int ID1, int ID2, sf::Vector2f vertexVector1, sf::Vector2f vertexVector2)
{
	if (numCollisionFlags < MAX_NUM_COLLISION_FLAGS) {
		collisionFlagArray[numCollisionFlags].collisionDataID1 = ID1;
		collisionFlagArray[numCollisionFlags].collisionDataID2 = ID2;
		collisionFlagArray[numCollisionFlags].collisionVertexVector1 = vertexVector1;
		collisionFlagArray[numCollisionFlags].collisionVertexVector2 = vertexVector2;
		numCollisionFlags++;
	}
	else {
		printf("[CollisionSystem::AddCollisionFlag] ERROR: No more room for collision flags.\n");
	}
}

int CollisionSystem::GetCollisionObjectIndexFromID(int collisionObjectID)
{
	for (int i = 0; i < numCollisionObjects; ++i) {
		if (collisionObjectArrayElementToIDMap[i] == collisionObjectID) {
			return i;
		}
	}

	return -1;
}

void CollisionSystem::ClearCollisionFlags() {
	
	// Set numCollisionFlags to zero to simply overwrite previous flags on next loop.
	// Will require more sophisticated method if other data structure (e.g. linked list) is used to store collision flags
	numCollisionFlags = 0;
}

void CollisionSystem::PrintfCollisionFlags() {
	if (numCollisionFlags > 0) {
		printf("\n[CollisionSystem::PrintCollisionFlags]----------\n");
		printf("Number of collision flags: %d", numCollisionFlags);
		for (int i = 0; i < numCollisionFlags; ++i) {
			printf("ID1: %4d, ID2: %4d, VertexVector1: (%6.2f,%6.2f), VertexVector2: (%6.2f,%6.2f)\n",
				collisionFlagArray[i].collisionDataID1,
				collisionFlagArray[i].collisionDataID2,
				collisionFlagArray[i].collisionVertexVector1.x,
				collisionFlagArray[i].collisionVertexVector1.y,
				collisionFlagArray[i].collisionVertexVector2.x,
				collisionFlagArray[i].collisionVertexVector2.y);
		}
		printf("------------------------------------------------------\n");
	}
}

int CollisionSystem::AddCollisionObject()
{
	bool addObjectSuccess = false;
	int returnCollisionObjectID = 0;

	// If able to add an object, simply assign an ID to the next collision object array element.
	// Further initialization of collision objects is to be done by the user elsewhere (using the
	// collision object ID returned from this function).
	
	// NOTE: Use another array that acts as a "map" between collisionObjectArray element indexes 
	// and objectIDs. This should speed up initialization of objects when searching based on object IDs.

	if (numCollisionObjects < MAX_NUM_COLLISION_OBJECTS) {		
		
		collisionObjectArray[numCollisionObjects].collisionDataID = currentCollisionObjectID;						
		collisionObjectArrayElementToIDMap[numCollisionObjects] = currentCollisionObjectID;
		
		returnCollisionObjectID = currentCollisionObjectID;

		currentCollisionObjectID++;		
		numCollisionObjects++;		
		
		addObjectSuccess = true;
	}
	else {
		printf("[CollisionSystem::AddCollisionObject] ERROR: Collision object limit reached; cannot add more collision objects.\n");
	}

	if (addObjectSuccess) {
		return returnCollisionObjectID;
	}
	else {
		return -1;
	}
}

bool CollisionSystem::RemoveCollisionObject(int collisionObjectID)
{	
	bool successfullyRemovedObject = false;

	// Search for array element index of object with ID == collisionObjectID arg.
	// Remove collision object from array, and replace with last element of array
	// (Must update objectArrayElementToID map index/ID).
	for (int i = 0; i < numCollisionObjects; ++i) {
		if (collisionObjectArrayElementToIDMap[i] == collisionObjectID) {			
			
			// Remove object here


			successfullyRemovedObject = true;
		}
	}

	return successfullyRemovedObject;	
}

void CollisionDataObjectQuickInit(CollisionData& collisionData)
{
	int numVertices = collisionData.numVertices;
	int objectID = collisionData.collisionDataID;
	int colorInteger = 255 - (objectID * 7);
	colorInteger %= 255;

	sf::Color objectColor = sf::Color(colorInteger, colorInteger, colorInteger, 255);

	float deltaAngle;
	float angle = 0;
	float radius = 100;

	deltaAngle = (float)(2.0 * PI / numVertices);

	if (objectID > 0) {
		angle += (float)(deltaAngle / 2.0);
	}

	for (int i = 0; i < numVertices; ++i) {
		collisionData.collisionVerticesArray[i].position = sf::Vector2f(radius*sin(angle), -radius*cos(angle));
		angle += deltaAngle;
		collisionData.collisionVerticesArray[i].color = objectColor;
	}

	// Calculate average vector for collision data object
	sf::Vector2f averageVector = VertexArrayVector2Average(collisionData.collisionVerticesArray, numVertices);

	collisionData.boundsAverageVector = averageVector;
}

void DisplaceCollisionDataObject(sf::Vector2f displacement, CollisionData& collisionObject)
{
	int numVertices = collisionObject.numVertices;
	for (int i = 0; i < numVertices; ++i) {
		collisionObject.collisionVerticesArray[i].position += displacement;
	}

	collisionObject.boundsAverageVector = VertexArrayVector2Average(collisionObject.collisionVerticesArray, collisionObject.numVertices);
}

void SetCollisionDataPosition(sf::Vector2f position, CollisionData &collisionData)
{
	int numVertices = collisionData.numVertices;

	for (int i = 0; i < numVertices; ++i) {
		collisionData.collisionVerticesArray[i].position += position;
	}

	collisionData.boundsAverageVector = VertexArrayVector2Average(collisionData.collisionVerticesArray, numVertices);
}