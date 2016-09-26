#include "Game.h"

int main(int argc, char *argv[])
{
	std::srand(std::time(nullptr));

	Game g;

	g.work();

	if(DEBUG_MODE)
		_CrtDumpMemoryLeaks();

	return 0;
}