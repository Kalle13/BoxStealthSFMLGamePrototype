// main.cpp

#include "Game\GameLoop.h"

EntityManager *gEntityManager;
GameInput *gGameInput;

int main()
{
	GameLoop game;
	game.GameLoopInit();

	return 0;
}
