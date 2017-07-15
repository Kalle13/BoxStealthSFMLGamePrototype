#include "GameInput.h"

void GameInput::GameInputInit()
{
	keyboardPressedFlags = 0;
	keyboardReleasedFlags = 0;
	mouseButtonFlags = 0;
	controllerButtonFlags = 0;

	controllerLeftJoystickPos = sf::Vector2f(0, 0);
	controllerrightJoystickPos = sf::Vector2f(0, 0);

	sf::Joystick::update();

	if (sf::Joystick::isConnected(0)) {
		numControllerButtons = sf::Joystick::getButtonCount(0);
		numControllerJoysticks = 0;
		for (unsigned i = 0; i < sf::Joystick::AxisCount; ++i) {
			if (sf::Joystick::hasAxis(0, (sf::Joystick::Axis)i)) {
				numControllerJoysticks++;
			}
		}
	}
}

void GameInput::GameInputDestroy()
{

}