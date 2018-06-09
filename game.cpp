#include "game.hpp"
#include "ship.hpp"

//start canonical
Game::Game(void)
{
	this->listLength = 0;
	return;
}

Game::~Game(void)
{
	return;
}

Game::Game(const Game & _game)
{
	*this = _game;
}

Game & Game::operator=(const Game & _rhs)
{
	*this = _rhs;
	return *this;
}
//end canonical!!

int			Game::getInit(void) const
{
	std::cout << "called";
	if (this->win){
		return 1;
	}
	return 0;
}

void		Game::init(void)
{
	this->win = initscr();
	noecho();
	//access keys
	keypad(stdscr, TRUE);
	//no buffer on key press
	nodelay(this->win, true);
	//hide the cursor
	curs_set(0);
	if(!has_colors())
	{
		endwin();
		printf("ERROR: Terminal does not support color.\n");
		exit(1);
	}
	start_color();
	attron(A_BOLD);
	box(this->win, 0, 0);
	attroff(A_BOLD);
}

static int	GameMenu(std::string menuType)
{
	int	read_char;
	int	x, y;
	std::string newgame = menuType;
	std::string quitgame = "QUIT";
	int	start_quit = 0;

	init_pair(1, COLOR_BLUE, COLOR_RED);
	while (1)
	{
		wclear(stdscr);
		getmaxyx(stdscr, y, x);
		
		move(y / 2, (x / 2) - (newgame.length() / 2));
		attron(A_BOLD);
		if (start_quit == 0)
			attron(COLOR_PAIR(1));
		addstr(newgame.c_str());
		if (start_quit == 0)
			attroff(COLOR_PAIR(1));
		move((y / 2) + 1, (x / 2) - (quitgame.length() / 2));
		if (read_char == 27)
			break;
		else if (start_quit == 1)
			attron(COLOR_PAIR(1));
		addstr(quitgame.c_str());
		if (start_quit == 1)
			attroff(COLOR_PAIR(1));
		attroff(A_BOLD);
		read_char = getch();
		if (read_char == 259)
			start_quit = 0;
		else if (read_char == 258)
			start_quit = 1;
		else if (start_quit == 1 && (read_char == 10 || read_char == 32))
		{
			beep();
			flash();
			return (1);
			break;
		}
		else if (start_quit == 0 && (read_char == 10 || read_char == 32))
		{
			beep();
			flash();
			wclear(stdscr);
			return (0);
			break;
		}
		refresh();
	}
	return (0);
}

static void	testkey(void)
{
	int	read_char;
	int	x, y;
	bool	paused;

	paused = false;
	while (1)
	{
		wclear(stdscr);
		getmaxyx(stdscr, y, x);
		move(0,0);
		wprintw(stdscr, "x:%d | y:%d", x, y);
		if ((x < 80) || (y < 40))
		{
			while ((x < 80) || (y < 40))
			{
				getmaxyx(stdscr, y, x);
				wclear(stdscr);
				move(y / 2, (x / 2) - 3);
				attron(A_BOLD);
				addstr("PAUSED");
				attroff(A_BOLD);
				move((y / 2) + 1, (x / 2) - 7);
				addstr("SCREEN TO SMALL");
				move((y / 2) + 2, (x / 2) - 6);
				addstr("PLEASE RESIZE");
				refresh();
				// read_char = getch();
				// if (read_char == 27)
				// 	break;
			}
			paused = true;
		}
		if (paused)
		{
			paused = false;
			if (GameMenu("RESUME"))
				break ;
		}
		read_char = getch();
		if (read_char == 100)
			break;
	}
}

void		Game::run(void)
{	
	gameObject	player;
	gameObject	enemy;
	bool		mainGameLoop = true;
	bool		retryGameLoop = true;

	if (!GameMenu("START GAME"))
	{
		enemy.setPosition(20, 10);
		enemy.setSprite('#');

		player.setPosition(10, 5);
		player.setSprite('?');

		assignEntity(player);
		assignEntity(enemy);

		updateBoard();
		refresh();

		retryGameLoop = true;
		while(retryGameLoop)
		{
			mainGameLoop = true;
			while (mainGameLoop)
			{
				testkey();
				mainGameLoop = false;
			}
			if (GameMenu("RETRY"))
			{
				retryGameLoop = false;
			}
		}
	}
}

void		Game::close(void)
{
	endwin();
}

void		Game::assignEntity(gameObject & _entity)
{
	if (this->listLength + 1 < 100) {
		this->entityList[this->listLength] = &_entity;
		this->listLength += 1;
	}
}

void		Game::updateBoard(void){

	for(int i = 0; i < this->listLength; i++){
		int xpos = this->entityList[i]->getXPosition();
		int ypos = this->entityList[i]->getYPosition();
		std::string pSprite = this->entityList[i]->getSprite();
		mvaddstr(ypos, xpos, pSprite.c_str());
	}
	return;
}
