#include "game.hpp"
#include "ship.hpp"

//start canonical

Game::Game(void){
	this->listLength = 0;
	return;
}

Game::~Game(void){
	return;
}

Game::Game(const Game & _game){
	*this = _game;
}

Game & Game::operator=(const Game & _rhs){
	*this = _rhs;
	return *this;
}

//end canonical!!

int Game::getInit(void){
	std::cout << "called";
	if (this->win){
		return 1;
	}
	return 0;
}

void Game::init(void){	

	this->win = initscr();

	cbreak();
	noecho();
	clear();
	refresh();

	//access keys 
	keypad(stdscr, TRUE);
	//no buffer on key press
	nodelay(this->win, true);
	//hide the cursor
	curs_set(0);

	if(!has_colors()) {
		endwin();
		printf("ERROR: Terminal does not support color.\n");
		exit(1);
	}

	start_color();
	attron(A_BOLD);
	box(this->win, 0, 0);
	attroff(A_BOLD);

	init_pair(1, COLOR_WHITE, COLOR_BLACK);
	wbkgd(this->win, COLOR_PAIR(1));
	
}

void Game::run(void){
	
	gameObject player;
	gameObject enemy;

	enemy.setPosition(20, 10);
	enemy.setSprite('#');

	player.setPosition(10, 5);
	player.setSprite('?');



	assignEntity(player);
	assignEntity(enemy);
	

	updateBoard();
	
	refresh();

	while(1);
}

void Game::close(void){
	endwin();
}

void Game::assignEntity(gameObject & _entity) {
	if (this->listLength + 1 < 100) {
		this->entityList[this->listLength] = &_entity;
		this->listLength += 1;
	}
}

void  Game::updateBoard(void){

	for(int i = 0; i < this->listLength; i++){
		int xpos = this->entityList[i]->getXPosition();
		int ypos = this->entityList[i]->getYPosition();
		std::string pSprite = this->entityList[i]->getSprite();
		mvaddstr(ypos, xpos, pSprite.c_str());
	}
	return;
}