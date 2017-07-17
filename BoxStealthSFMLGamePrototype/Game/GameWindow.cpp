// GameWindow.cpp
#include "GameWindow.h"

void GameWindow::Initialize()
{	
	windowWidth_ = 800;
	windowHeight_ = 600;
	videoMode_ = sf::VideoMode(windowWidth_, windowHeight_);
	gameWindowTitle_ = "Game Window";

	gameWindow_.create(videoMode_, gameWindowTitle_);
}

void GameWindow::Update()
{
	unsigned currentWindowWidth = gameWindow_.getSize().x;
	unsigned currentWindowHeight = gameWindow_.getSize().y;	

	if ((windowWidth_ != currentWindowWidth) || (windowHeight_ != currentWindowHeight)) {
		videoMode_.width = windowWidth_;
		videoMode_.height = windowHeight_;
	}

	gameWindow_.create(videoMode_, gameWindowTitle_);
}

void GameWindow::Destroy()
{
	printf("Game Window detroyed\n");
}

bool GameWindow::WindowIsOpen()
{
	if (gameWindow_.isOpen()) {
		return true;
	}	
	
	return false;
}

void GameWindow::Clear(sf::Color clearWindowColor)
{
	gameWindow_.clear(clearWindowColor);
}

void GameWindow::Display()
{
	gameWindow_.display();
}

