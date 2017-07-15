// GameLoop.cpp
#include "GameLoop.h"

void GameLoop::GameLoopInit()
{
	gameInputPtr = gGameInputPtr;
	gameConsolePtr = gGameConsolePtr;
	levelManagerPtr = gLevelManagerPtr;
	entityManagerPtr = gEntityManagerPtr;
	
	gameConsolePtr->gameInputPtr = gGameInputPtr;
	entityManagerPtr->gameInputPtr = gGameInputPtr;

	// Initialize various systems
	gameInputPtr->GameInputInit();

}

void GameLoop::GameLoopDestroy()
{

}

void GameLoop::GameLoopRun()
{

   sf::VideoMode videoMode(800,600);
   window.create(videoMode,"Game Window");

   sf::Clock gameClock;
   sf::Time timeSinceLastUpdate = sf::Time::Zero;
   sf::Time timePerFrame = sf::seconds(1.f/60.f);

   while(window.isOpen())
   {
      timeSinceLastUpdate += gameClock.restart();

      while(timeSinceLastUpdate > timePerFrame)
      {
         timeSinceLastUpdate -= timePerFrame;
         GameLoopInput();
         GameLoopUpdate(timePerFrame.asSeconds());
      }

      GameLoopRender();
   }
}


void GameLoop::GameLoopInput()
{
	unsigned keyboardPressedFlags = 0;
	unsigned keyboardReleasedFlags = 0;
	unsigned mouseButtonPressedFlags = 0;
	unsigned mouseButtonReleasedFlags = 0;
	float mouseWheelDelta = 0;
	unsigned controllerButtonPressedFlags = 0;
	unsigned controllerButtonReleasedFlags = 0;

	sf::Event event;
	while(window.pollEvent(event))
	{
		if(event.type == sf::Event::Closed)
		{
			window.close();
		}

		if (event.type == sf::Event::KeyPressed)
		{
			unsigned leftShift = (unsigned)(event.key.code);
			keyboardPressedFlags |= (1 << leftShift);
		}

		if (event.type == sf::Event::KeyReleased)
		{
			unsigned leftShift = (unsigned)(event.key.code);
			keyboardReleasedFlags |= (1 << leftShift);
		}

		if (event.type == sf::Event::MouseButtonPressed) {
			unsigned leftShift = (unsigned)(event.mouseButton.button);
			mouseButtonPressedFlags = (1 << leftShift);
		}

		if (event.type == sf::Event::MouseButtonReleased) {
			unsigned leftShift = (unsigned)(event.mouseButton.button);
			mouseButtonReleasedFlags = (1 << leftShift);
		}

		if (event.type == sf::Event::MouseWheelScrolled) {
			mouseWheelDelta += event.mouseWheelScroll.delta;
		}

		if (event.type == sf::Event::JoystickButtonPressed) {
			unsigned leftShift = (unsigned)(event.joystickButton.button);
			controllerButtonPressedFlags |= (1<<leftShift);
		}

		if (event.type == sf::Event::JoystickButtonReleased) {
			unsigned leftShift = (unsigned)(event.joystickButton.button);
			controllerButtonReleasedFlags |= (1 << leftShift);
		}
	}

	sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
	sf::Vector2f controllerLeftJoystickPos = sf::Vector2f(sf::Joystick::getAxisPosition(0, sf::Joystick::X), sf::Joystick::getAxisPosition(0, sf::Joystick::Y));
	sf::Vector2f controllerrightJoystickPos = sf::Vector2f(sf::Joystick::getAxisPosition(0, sf::Joystick::R), sf::Joystick::getAxisPosition(0, sf::Joystick::U));

	gameInputPtr->keyboardPressedFlags = keyboardPressedFlags;
	gameInputPtr->keyboardReleasedFlags = keyboardReleasedFlags;
	gameInputPtr->mouseButtonPressedFlags = mouseButtonPressedFlags;
	gameInputPtr->mouseButtonReleasedFlags = mouseButtonReleasedFlags;
	gameInputPtr->mouseWheelDelta = mouseWheelDelta;
	gameInputPtr->controllerButtonPressedFlags = controllerButtonPressedFlags;
	gameInputPtr->controllerButtonReleasedFlags = controllerButtonReleasedFlags;
	gameInputPtr->mousePosition;
	gameInputPtr->controllerLeftJoystickPos = controllerLeftJoystickPos;
	gameInputPtr->controllerRightJoystickPos = controllerrightJoystickPos;
}

void GameLoop::GameLoopUpdate(float deltaTInSeconds)
{

}

void GameLoop::GameLoopRender()
{
   window.clear(sf::Color::Black);

   window.display();
}
