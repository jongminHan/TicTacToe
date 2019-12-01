#include <iostream>
#include "Game.h"

using namespace lecture;

int main()
{	
	Game* game = new Game(SCRREN_WIDTH, SCREEN_HEIGHT, "Tic-Tac-Toe");

	game->Run();

	delete game;
	return EXIT_SUCCESS;
}