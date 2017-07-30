// main.cpp

#include "Game/GameLoop.h"
#include <assert.h>

#define PI 3.141592654
#define MAX_COLLISION_FLAG_ELEMENTS 10

GameWindow *gGameWindowPtr;
GameInput *gGameInputPtr;
GameConsole *gGameConsolePtr;
SceneManager *gSceneManagerPtr;
LevelManager *gLevelManagerPtr;
EntityManager *gEntityManagerPtr;


struct CollisionData
{
	int collisionDataID;				// An ID# for identifying a CollisionData instance
	int numVertices;					// Number of vertices comprising the collision boundary
	sf::Vector2f boundsAverageVector;	// Vector that is the average of all vectors comprising the collision boundary
	sf::Vertex *collisionVerticesArray;	// The collision boundary vertices (can also use sf::Vector2f array; sf::Vertex allows for collision bounds to be rendered)

	void CollisionDataMalloc(){
		collisionVerticesArray = (sf::Vertex*)malloc(numVertices * sizeof(sf::Vertex));
	}

	void CollisionDataFree() {
		free(collisionVerticesArray);
	}
};

struct CollisionFlag
{
	int collisionDataID1;
	int collisionDataID2;
	sf::Vector2f collisionVertexVector1;
	sf::Vector2f collisionVertexVector2;
};

class CollisionFlagContainer 
{
public:
	CollisionFlagContainer() {}
	~CollisionFlagContainer() {}

	void Initialize() {
		printf("[CollisionFlagContainer::Initialize] Initialized\n");
		numCollisionFlags = 0;
		collisionFlagArray = (CollisionFlag*)malloc(MAX_COLLISION_FLAG_ELEMENTS * sizeof(CollisionFlag));
	}
	
	void Destroy() {
		printf("[CollisionFlagContainer::Destroy] Destroyed\n");
		free(collisionFlagArray);
	}
	
	void AddCollisionFlag(int ID1, int ID2, sf::Vector2f vertexVector1, sf::Vector2f vertexVector2) {
		if (numCollisionFlags < MAX_COLLISION_FLAG_ELEMENTS) {
			collisionFlagArray[numCollisionFlags].collisionDataID1 = ID1;
			collisionFlagArray[numCollisionFlags].collisionDataID2 = ID2;
			collisionFlagArray[numCollisionFlags].collisionVertexVector1 = vertexVector1;
			collisionFlagArray[numCollisionFlags].collisionVertexVector2 = vertexVector2;
			numCollisionFlags++;
		}
		else {
			printf("[CollisionFlagContainer::AddCollisionFlag] No more room for collision flags\n");
		}
	}

	void ClearCollisionFlags() {
		numCollisionFlags = 0; // set numCollisionFlags to zero to simply overwrite previous flags on next loop
	}

	void PrintCollisionFlags() {
		if (numCollisionFlags > 1) {
			printf("\n[CollisionFlagContainer::PrintCollisionFlags]----------\n");
			for (int i = 0; i < numCollisionFlags; ++i) {
				printf("ID1: %d, ID2: %d, VertexVector1: (%.2f,%.2f), VertexVector2: (%.2f,%.2f)\n", 
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


public:

	int numCollisionFlags;
	CollisionFlag *collisionFlagArray;

};

// CollisionDataObjectQuickInit assumes CollisionData ID and numVertices have been initialized for the object
void CollisionDataObjectQuickInit(CollisionData& collisionData);
void DisplaceCollisionDataObject(sf::Vector2f displacement, CollisionData& collisionObject);
void SetCollisionDataPosition(sf::Vector2f position, CollisionData &collisionData);
sf::Vector2f FindClosestVertexToVector2(sf::Vector2f vector, sf::Vertex *vertexArray, int vertexCount);
sf::Vector2f FindSecondClosestVertexToVector2(sf::Vector2f vector, sf::Vertex *vertexArray, int vertexCount);
sf::Vector2f FurthestVertexFromVector2(sf::Vector2f vector, sf::Vertex *vertexArray, int vertexCount);

int main()
{
	GameWindow gameWindow;
	GameInput gameInput;
	const int numCollisionDataObjects = 2;
	CollisionData collisionObject[numCollisionDataObjects];	
	CollisionFlagContainer collisionFlagContainer;


	gameInput.GameInputInitialize();
	collisionFlagContainer.Initialize();

	collisionObject[0].collisionDataID = 0;
	collisionObject[1].collisionDataID = 1;

	// Triangular objects
	collisionObject[0].numVertices = 3;
	collisionObject[1].numVertices = 3;

	collisionObject[0].CollisionDataMalloc();
	collisionObject[1].CollisionDataMalloc();

	CollisionDataObjectQuickInit(collisionObject[0]);
	CollisionDataObjectQuickInit(collisionObject[1]);

	DisplaceCollisionDataObject(sf::Vector2f(350, 275), collisionObject[0]);
	DisplaceCollisionDataObject(sf::Vector2f(400, 300), collisionObject[1]);

	gameWindow.Initialize();

	while (gameWindow.WindowIsOpen()) {

		gameInput.UpdateInputState(gameWindow.gameWindow_);

		if (gameInput.keyboardInputData_.keyPressed_ == sf::Keyboard::Escape) {
			gameWindow.CloseWindow();
		} else if (gameInput.keyboardInputData_.keyPressed_ == sf::Keyboard::W) {
			DisplaceCollisionDataObject(sf::Vector2f(0,-10), collisionObject[0]);
		} else if (gameInput.keyboardInputData_.keyPressed_ == sf::Keyboard::A) {
			DisplaceCollisionDataObject(sf::Vector2f(-10, 0), collisionObject[0]);
		} else if (gameInput.keyboardInputData_.keyPressed_ == sf::Keyboard::S) {
			DisplaceCollisionDataObject(sf::Vector2f(0, 10), collisionObject[0]);
		} else if (gameInput.keyboardInputData_.keyPressed_ == sf::Keyboard::D) {
			DisplaceCollisionDataObject(sf::Vector2f(10, 0), collisionObject[0]);
		} else if (gameInput.keyboardInputData_.keyPressed_ == sf::Keyboard::Up) {
			DisplaceCollisionDataObject(sf::Vector2f(0, -10), collisionObject[1]);
		} else if (gameInput.keyboardInputData_.keyPressed_ == sf::Keyboard::Left) {
			DisplaceCollisionDataObject(sf::Vector2f(-10, 0), collisionObject[1]);
		} else if (gameInput.keyboardInputData_.keyPressed_ == sf::Keyboard::Down) {
			DisplaceCollisionDataObject(sf::Vector2f(0, 10), collisionObject[1]);
		} else if (gameInput.keyboardInputData_.keyPressed_ == sf::Keyboard::Right) {
			DisplaceCollisionDataObject(sf::Vector2f(10, 0), collisionObject[1]);
		}

		// For collision object A, find closest collision vertex of object B to object A
		// If closest B vertex is closer to A's average vector than any of A's vertices, then there is a collision

		collisionFlagContainer.ClearCollisionFlags();

		for (int i = 0; i < numCollisionDataObjects; ++i) {
			for (int j = i + 1; j < numCollisionDataObjects; ++j) {				

				sf::Vector2f closestBVector = FindClosestVertexToVector2(collisionObject[i].boundsAverageVector, 
																		 collisionObject[j].collisionVerticesArray, 
																		 collisionObject[j].numVertices);
								
				sf::Vector2f closestAVectorToBVector = FindClosestVertexToVector2(closestBVector,
																				  collisionObject[i].collisionVerticesArray,
																				  collisionObject[i].numVertices);
				
				sf::Vector2f secondClosestAVectorToBVector = FindSecondClosestVertexToVector2(closestBVector, 
																							  collisionObject[i].collisionVerticesArray,
																							  collisionObject[i].numVertices);

				sf::Vector2f objectAAverageVector = collisionObject[i].boundsAverageVector;
				
				// Need to use two closest A vertex vectors to B vertex vector to project B vertex vector
				// onto difference vector of two A vectors. Then determine if B vector is closer to A avg vector than
				// projected B vector (meaning B vector is inside object A, and a collision has occurred).


				float magnitudeOfAAverageVectorToAVector = Vector2Magnitude(closestAVectorToBVector - objectAAverageVector);
				assert(magnitudeOfAAverageVectorToAVector > 0);
				
				float magnitudeOfAAverageVectorToBVector = Vector2Magnitude(closestBVector - objectAAverageVector);
				assert(magnitudeOfAAverageVectorToBVector > 0);

				if (magnitudeOfAAverageVectorToAVector > magnitudeOfAAverageVectorToBVector) {				
					collisionFlagContainer.AddCollisionFlag(collisionObject[i].collisionDataID, 
															collisionObject[j].collisionDataID, 
															closestAVectorToBVector, 
															closestBVector);
				}
			}
		}

		if (collisionFlagContainer.numCollisionFlags > 0) {
			//printf("numCollisionFlags: %d\n", collisionFlagContainer.numCollisionFlags);
			collisionFlagContainer.PrintCollisionFlags();
		}
		else {
			//printf("No collision flags\n");
		}

		gameWindow.Clear(sf::Color::Red);
		gameWindow.gameWindow_.draw(collisionObject[0].collisionVerticesArray,collisionObject[0].numVertices,sf::Triangles);
		gameWindow.gameWindow_.draw(collisionObject[1].collisionVerticesArray, collisionObject[1].numVertices, sf::Triangles);
		gameWindow.Display();

	}

	// Free/Destroy everything
	collisionObject[0].CollisionDataFree();
	collisionObject[1].CollisionDataFree();
	collisionFlagContainer.Destroy();
	gameInput.GameInputDestroy();
	gameWindow.Destroy();

	return 0;
}


void CollisionDataObjectQuickInit(CollisionData& collisionData)
{
	int numVertices = collisionData.numVertices;
	int objectID = collisionData.collisionDataID;
	int colorInteger = 255 - (objectID * 7);
	colorInteger %= 255;

	sf::Color objectColor = sf::Color(colorInteger, colorInteger, colorInteger, 255);

	float deltaAngle = 2 * PI / numVertices;
	float angle = 0;
	float radius = 100;
	
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

sf::Vector2f FindClosestVertexToVector2(sf::Vector2f vector, sf::Vertex *vertexArray, int vertexCount)
{
	sf::Vector2f closestVector = vertexArray[0].position;
	float distanceBetweenVectors;
	float minDistanceBetweenVectors = Vector2Magnitude(closestVector-vector);

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
		if((distanceBetweenVectors > closestVectorDistance) && (distanceBetweenVectors < secondClosestVectorDistance)){
			secondClosestVectorDistance = distanceBetweenVectors;
			secondClosestVector = vertexArray[i].position;
		}
	}

	return secondClosestVector;
}

sf::Vector2f FurthestVertexFromVector2(sf::Vector2f vector, sf::Vertex *vertexArray, int vertexCount)
{
	sf::Vector2f furthestVector = sf::Vector2f(0,0);
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