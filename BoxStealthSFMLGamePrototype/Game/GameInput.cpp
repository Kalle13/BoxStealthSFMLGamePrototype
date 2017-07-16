#include "GameInput.h"

void GameInput::GameInputInitialize()
{
	keyboardInputData_.Init();
	mouseInputData_.Init();
	controllerInputData_.Init();

	sf::Joystick::update();

	if (sf::Joystick::isConnected(0)) {
		controllerInformation_.controllerID = 0;
		controllerInformation_.numButtons = sf::Joystick::getButtonCount(0);		
		for (unsigned i = 0; i < sf::Joystick::AxisCount; ++i) {
			if (sf::Joystick::hasAxis(0, (sf::Joystick::Axis)i)) {
				controllerInformation_.numJoysticks++;
			}
		}
	}

	printf("Game Input initialized\n");
}

void GameInput::UpdateInputState(sf::RenderWindow& window)
{
	keyboardInputData_.Init();
	mouseInputData_.Init();
	controllerInputData_.Init();

	sf::Event event;
	while (window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		{
			window.close();
		}

		if (event.type == sf::Event::KeyPressed)
		{
			keyboardInputData_.keyPressed_ = (int)(event.key.code);
		}

		if (event.type == sf::Event::KeyReleased)
		{
			keyboardInputData_.keyReleased_ = (int)(event.key.code);			
		}

		if (event.type == sf::Event::MouseButtonPressed) {
			mouseInputData_.mouseButtonPressed_ = (int)(event.mouseButton.button);			
		}

		if (event.type == sf::Event::MouseButtonReleased) {
			mouseInputData_.mouseButtonReleased_ = (int)(event.mouseButton.button);			
		}

		if (event.type == sf::Event::MouseWheelScrolled) {
			mouseInputData_.mouseWheelDelta_ = event.mouseWheelScroll.delta;
		}

		if (event.type == sf::Event::JoystickButtonPressed) {
			controllerInputData_.controllerButtonPressed_ = (int)(event.joystickButton.button);
		}

		if (event.type == sf::Event::JoystickButtonReleased) {
			controllerInputData_.controllerButtonReleased_ = (int)(event.joystickButton.button);
		}

		if (event.type == sf::Event::JoystickConnected) {
			// Really want to call this function right here? Maybe call it at some other time after the joystick is connected
			GetJoystickData();
		}
	}

	mouseInputData_.mousePosition_ = sf::Mouse::getPosition(window);
	sf::Vector2f joystickLeftPos = sf::Vector2f(sf::Joystick::getAxisPosition(0, sf::Joystick::X), sf::Joystick::getAxisPosition(0, sf::Joystick::Y));
	sf::Vector2f joystickRightPos = sf::Vector2f(sf::Joystick::getAxisPosition(0, sf::Joystick::R), sf::Joystick::getAxisPosition(0, sf::Joystick::U));
	controllerInputData_.controllerLeftJoystickPos_ = joystickLeftPos;
	controllerInputData_.controllerRightJoystickPos_ = joystickRightPos;
}
 
void GameInput::GameInputDestroy()
{
	printf("Game Input destroyed\n");
}

void GameInput::GetJoystickData()
{
	controllerInformation_.controllerID = 0;
	controllerInformation_.numButtons = sf::Joystick::getButtonCount(0);
	for (unsigned i = 0; i < sf::Joystick::AxisCount; ++i) {
		if (sf::Joystick::hasAxis(0, (sf::Joystick::Axis)i)) {
			controllerInformation_.numJoysticks++;
		}
	}
}
