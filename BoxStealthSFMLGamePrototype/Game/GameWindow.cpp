// GameWindow.cpp
#include "GameWindow.h"

void GameWindow::Initialize(GameInput *initGameInputPtr)
{	
	windowWidth = 800;
	windowHeight = 600;
	videoMode = sf::VideoMode(windowWidth, windowHeight);
	gameWindowTitle = "Game Window";

	gameWindow.create(videoMode, gameWindowTitle);

	gameInputPtr = initGameInputPtr;

	if (gameInputPtr == NULL) {
		printf("(GameWindow::Initialize) Warning: gameInputPtr is uninitialized\n");
	}
}

void GameWindow::Update()
{
	unsigned currentWindowWidth = gameWindow.getSize().x;
	unsigned currentWindowHeight = gameWindow.getSize().y;	

	if ((windowWidth != currentWindowWidth) || (windowHeight != currentWindowHeight)) {
		videoMode.width = windowWidth;
		videoMode.height = windowHeight;
	}

	gameWindow.create(videoMode, gameWindowTitle);
}

void GameWindow::Destroy()
{
	printf("Game Window detroyed\n");
}

bool GameWindow::WindowIsOpen()
{
	if (gameWindow.isOpen() && (gameInputPtr != NULL)) {
		return true;
	}	
	
	return false;
}

void GameWindow::Draw()
{
	gameWindow.clear(sf::Color::Black);
	renderComponentPtr->Draw(gameWindow);
	gameWindow.display();
}

