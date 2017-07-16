#include "GameInput.h"

void GameInput::GameInputInitialize()
{
	keyboardPressedFlags = 0;
	keyboardReleasedFlags = 0;
	mouseButtonPressedFlags = 0;
	mouseButtonReleasedFlags = 0;
	mouseWheelDelta = 0;
	controllerButtonPressedFlags = 0;
	controllerButtonReleasedFlags = 0;
	mousePosition = sf::Vector2i(0, 0);
	controllerLeftJoystickPos = sf::Vector2f(0, 0);
	controllerRightJoystickPos = sf::Vector2f(0, 0);

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

	printf("Game Input initialized\n");
}
 
void GameInput::GameInputDestroy()
{
	printf("Game Input destroyed\n");
}