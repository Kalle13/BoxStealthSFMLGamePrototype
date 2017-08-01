// main.cpp

#include "Game/GameLoop.h"
#include <assert.h>
#include "Systems/CollisionSystem.h"

GameWindow *gGameWindowPtr;
GameInput *gGameInputPtr;
GameConsole *gGameConsolePtr;
SceneManager *gSceneManagerPtr;
LevelManager *gLevelManagerPtr;
EntityManager *gEntityManagerPtr;


int main()
{				
	GameWindow gameWindow;
	GameInput gameInput;		
	CollisionSystem collisionSystem;

	gameInput.Initialize();
	gameWindow.Initialize();
	collisionSystem.Initialize();

	
	int collisionObject1ID = collisionSystem.AddCollisionObject();
	int collisionObject2ID = collisionSystem.AddCollisionObject();

	// Need way to initialize collision objects after getting their IDs
	int object1Index = collisionSystem.GetCollisionObjectIndexFromID(collisionObject1ID);
	collisionSystem.collisionObjectArray[object1Index].numVertices = 3;
	CollisionDataObjectQuickInit(collisionSystem.collisionObjectArray[object1Index]);

	while (gameWindow.WindowIsOpen()) {

		gameInput.UpdateInputState(gameWindow.gameWindow_);
		/*
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
		*/


		gameWindow.Clear(sf::Color::Red);		
		gameWindow.gameWindow_.draw(collisionSystem.collisionObjectArray[object1Index].collisionVerticesArray, collisionSystem.collisionObjectArray[object1Index].numVertices, sf::Triangles);
		gameWindow.Display();
	}

	// Free/Destroy everything
	collisionSystem.Destroy();
	gameInput.Destroy();
	gameWindow.Destroy();	

	return 0;
}