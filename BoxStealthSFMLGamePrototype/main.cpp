// main.cpp

#include "Game/GameLoop.h"

GameWindow *gGameWindowPtr;
GameInput *gGameInputPtr;
GameConsole *gGameConsolePtr;
SceneManager *gSceneManagerPtr;
LevelManager *gLevelManagerPtr;
EntityManager *gEntityManagerPtr;



int main()
{
	GameInput gameInput;
	RenderComponent renderComponent;
	CollisionComponent collisionComponent;
	GameWindow gameWindow;

	gameInput.GameInputInitialize();
	renderComponent.Initialize();
	collisionComponent.Initialize();
	gameWindow.Initialize();

	float angle = 10;
	float pi = 3.14159;
	float speed =  100.0; // 20 pixels/second

	sf::Clock clock;
	float deltaTime = 0;

	sf::Vertex windowCenter;
	sf::Vertex quadCenter;
	windowCenter.position = sf::Vector2f(400, 300);
	windowCenter.color = sf::Color::Cyan;
	quadCenter.position = sf::Vector2f(16, 16);
	quadCenter.color = sf::Color::Magenta;
	sf::VertexArray quad(sf::Quads, 4);
	quad[0].position = sf::Vector2f(0, 0) + windowCenter.position - quadCenter.position;
	quad[0].color = sf::Color::Red;
	quad[1].position = sf::Vector2f(32, 0) + windowCenter.position - quadCenter.position;
	quad[1].color = sf::Color::Blue;
	quad[2].position = sf::Vector2f(32, 32) + windowCenter.position - quadCenter.position;
	quad[2].color = sf::Color::Green;
	quad[3].position = sf::Vector2f(0, 32) + windowCenter.position - quadCenter.position;
	quad[3].color = sf::Color::Yellow;

	quadCenter.position = windowCenter.position;

	sf::Transform transform;

	sf::Vector2f displacementVector = sf::Vector2f(0,0);
	float displacementMagnitude = 0;
	sf::Vector2f finalPositionVector = quadCenter.position;

	unsigned frameCount = 0;

	sf::Vector2f avgVector = sf::Vector2f(0, 0);

	for (unsigned i = 0; i < 4; ++i) {
		avgVector += quad[i].position;
	}

	avgVector = sf::Vector2f(avgVector.x/4.0, avgVector.y/4.0);

	collisionComponent.UpdateCollisionBoundsPositionAndOrientation(windowCenter.position - collisionComponent.collisionBoundsCenterVector_, 0);

	while (gameWindow.WindowIsOpen()) 
	{
		deltaTime = clock.restart().asSeconds();

		gameInput.UpdateInputState(gameWindow.gameWindow_);
		
		transform = sf::Transform::Identity;

		if (gameInput.keyboardInputData_.keyPressed_ == sf::Keyboard::W) {
			finalPositionVector += sf::Vector2f(0, -100);
		}
		else if (gameInput.keyboardInputData_.keyPressed_ == sf::Keyboard::A) {
			finalPositionVector += sf::Vector2f(-100,0);
		}
		else if (gameInput.keyboardInputData_.keyPressed_ == sf::Keyboard::S) {
			finalPositionVector += sf::Vector2f(0, 100);
		}
		else if (gameInput.keyboardInputData_.keyPressed_ == sf::Keyboard::D) {
			finalPositionVector += sf::Vector2f(100,0);
		}
		else if (gameInput.keyboardInputData_.keyPressed_ == sf::Keyboard::Space) {
			printf("average vector: (%.2f,%.2f)\n", avgVector.x, avgVector.y);
		}
		
		transform.translate(SmoothDisplacement(quadCenter.position, finalPositionVector, speed, deltaTime));

		quadCenter.position = transform.transformPoint(quadCenter.position);
		for (unsigned i = 0; i < 4; ++i) {
			quad[i].position = transform.transformPoint(quad[i].position);
		}

		avgVector = sf::Vector2f(0, 0);
		for (unsigned i = 0; i < 4; ++i) {
			avgVector += quad[i].position;
		}		
		avgVector = sf::Vector2f(avgVector.x / 4.0, avgVector.y / 4.0);

		collisionComponent.UpdateCollisionBoundsPositionAndOrientation(avgVector - collisionComponent.collisionBoundsCenterVector_, 0);

		gameWindow.Clear(sf::Color::Black);
		gameWindow.gameWindow_.draw(quad);
		gameWindow.gameWindow_.draw(&quadCenter,1,sf::Points);
		gameWindow.gameWindow_.draw(&windowCenter,1,sf::Points);
		collisionComponent.Draw(gameWindow.gameWindow_);
		gameWindow.Display();
		
	}

	gameInput.GameInputDestroy();
	collisionComponent.Destroy();
	renderComponent.Destroy();
	gameWindow.Destroy();

	return 0;
}