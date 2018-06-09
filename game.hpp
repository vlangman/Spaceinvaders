#ifndef GAME_HPP
# define GAME_HPP

#include <ncurses.h>
#include <iostream>
#include "gameObject.hpp"

class Game {

private:
	WINDOW *win;
	int isInit;
	gameObject *entityList[100];
	int	listLength;

public:
	Game(void);
	~Game(void);

	Game(const Game & _game);
	Game & operator=(const Game & _rhs);

	int getInit(void);
	
	void init(void);
	void run(void);
	void close(void);


	void assignEntity(gameObject & _entity);
	void updateBoard(void);
};

#endif