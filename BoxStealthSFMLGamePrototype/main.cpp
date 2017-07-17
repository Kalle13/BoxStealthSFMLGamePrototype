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
	GameWindow gameWindow;

	gameInput.GameInputInitialize();
	renderComponent.Initialize();
	gameWindow.Initialize();

	float angle = 10;
	float pi = 3.14159;
	float speed = 20.0; // 20 pixels/second

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

	while (gameWindow.WindowIsOpen()) 
	{
		deltaTime = clock.restart().asSeconds();

		gameInput.UpdateInputState(gameWindow.gameWindow_);
		
		transform = sf::Transform::Identity;

		if (gameInput.keyboardInputData_.keyPressed_ == sf::Keyboard::W) {
			finalPositionVector += sf::Vector2f(0, -50);
		}
		else if (gameInput.keyboardInputData_.keyPressed_ == sf::Keyboard::A) {
			finalPositionVector += sf::Vector2f(-50,0);
		}
		else if (gameInput.keyboardInputData_.keyPressed_ == sf::Keyboard::S) {
			finalPositionVector += sf::Vector2f(0, 50);
		}
		else if (gameInput.keyboardInputData_.keyPressed_ == sf::Keyboard::D) {
			finalPositionVector += sf::Vector2f(50, 0);
		}	
		
		displacementVector = speed*deltaTime*(finalPositionVector - quadCenter.position);
		displacementMagnitude = Vector2Magnitude(finalPositionVector - quadCenter.position);

		if (displacementMagnitude < 0.00000001) {
			displacementVector = sf::Vector2f(0, 0);
		}

		transform.translate(displacementVector);

		quadCenter.position = transform.transformPoint(quadCenter.position);
		for (unsigned i = 0; i < 4; ++i) {
			quad[i].position = transform.transformPoint(quad[i].position);
		}

		gameWindow.Clear(sf::Color::Black);
		gameWindow.gameWindow_.draw(quad);
		gameWindow.gameWindow_.draw(&quadCenter,1,sf::Points);
		gameWindow.gameWindow_.draw(&windowCenter,1,sf::Points);
		gameWindow.Display();
		
	}

	gameInput.GameInputDestroy();
	renderComponent.Destroy();
	gameWindow.Destroy();

	return 0;
}
