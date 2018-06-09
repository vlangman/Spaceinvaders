#include "ship.hpp"

//start canonical
Ship::Ship(void)
{
	this->x_pos = 0;
	this->y_pos = 0;
	this->sprite = '#';
	return;
}

Ship::~Ship(void)
{
	return;
}

Ship::Ship(const Ship & _ship)
{
	*this = _ship;
	return;
}

Ship	&Ship::operator=(const Ship & _rhs)
{
	*this = _rhs;
	return *this;
}
//end canonical!!

void	Ship::setPosition(int _x, int _y)
{
	this->x_pos = _x;
	this->y_pos = _y;
	return;
}

void	Ship::setSprite(char _c)
{
	this->sprite = _c;
	return;
}

char	Ship::getSprite(void) const
{
	return (this->sprite);
}

int		Ship::getXPosition(void) const
{
	return this->x_pos;
}

int		Ship::getYPosition(void) const
{
	return this->y_pos;
}
