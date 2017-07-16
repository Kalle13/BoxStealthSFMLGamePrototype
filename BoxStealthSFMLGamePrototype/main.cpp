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

	gameWindow.renderComponentPtr = &renderComponent;

	gameInput.GameInputInitialize();
	renderComponent.Initialize();
	gameWindow.Initialize(&gameInput);

	float angle = 10;
	float pi = 3.14159;
	
	sf::Vector2f windowCenter = sf::Vector2f(400, 300);
	sf::Vector2f quadCenter = sf::Vector2f(16, 16);
	sf::VertexArray quad(sf::Quads, 4);
	quad[0].position = sf::Vector2f(0, 0) + windowCenter - quadCenter;
	quad[0].color = sf::Color::Red;
	quad[1].position = sf::Vector2f(32, 0) + windowCenter - quadCenter;
	quad[1].color = sf::Color::Blue;
	quad[2].position = sf::Vector2f(32,32) + windowCenter - quadCenter;
	quad[2].color = sf::Color::Green;
	quad[3].position = sf::Vector2f(0, 32) + windowCenter - quadCenter;
	quad[3].color = sf::Color::Yellow;
	sf::Transform transform;
	
	unsigned frameCount = 0;

	float deltaTime = 0;
	float time = 0;
	float prevTime = 0;

	printf("Keycount: %d\n",sf::Keyboard::KeyCount);

	while (gameWindow.WindowIsOpen()) 
	{
		gameInput.UpdateInputState(gameWindow.gameWindow);
		
		if (gameInput.keyboardInputData_.keyPressed_ >= 0) {
			printf("(frame #, key press): (%d,0x%x)\n", frameCount,gameInput.keyboardInputData_.keyPressed_);
		}
		if (gameInput.keyboardInputData_.keyReleased_ >= 0) {
			printf("frame #, key release): (%d,0x%x)\n", frameCount,gameInput.keyboardInputData_.keyReleased_);
		}

		frameCount++;
		frameCount %= 60;

		/*
		transform = sf::Transform::Identity;

		if (gameInput.keyboardPressedFlags & (1<<sf::Keyboard::Right)) {
			angle = 10;
			printf("rotation: %.2f\n", angle);
			transform.rotate(angle, windowCenter);
			for (unsigned i = 0; i < 4; ++i) {
				quad[i].position = transform.transformPoint(quad[i].position);
			}
		}
		else if (gameInput.keyboardPressedFlags & (1 << sf::Keyboard::Left)) {
			angle = -10;
			printf("rotation: %.2f\n", angle);
			transform.rotate(angle, windowCenter);
			for (unsigned i = 0; i < 4; ++i) {
				quad[i].position = transform.transformPoint(quad[i].position);
			}			
		}

		gameWindow.gameWindow.clear(sf::Color::Black);
		gameWindow.gameWindow.draw(quad);
		gameWindow.gameWindow.display();
		*/
	}

	gameInput.GameInputDestroy();
	renderComponent.Destroy();
	gameWindow.Destroy();

	return 0;
}
