#include "game.hpp"

int	main(void)
{
	Game _game;

	if (!_game.getInit()){
		_game.init();
	}

	_game.run();

	_game.close();

	return 0;
}