#include "ship.hpp"

//start canonical
Ship::Ship(void)
{
	this->x_posShip = 0;
	this->y_posShip = 0;
	this->sprite = '#';
	this->maxBullets = 10;
	this->bulletType = ' ';
	return ;
}

Ship::~Ship(void)
{
	return ;
}

Ship::Ship(const Ship & _ship)
{
	*this = _ship;
	return ;
}

Ship	&Ship::operator=(const Ship & _rhs)
{
	*this = _rhs;
	return (*this);
}
//end canonical!!

void	Ship::setPosition(int _x, int _y)
{
	this->x_posShip = _x;
	this->y_posShip = _y;
	return ;
}

void	Ship::setSprite(char _c)
{
	this->sprite = _c;
	return ;
}

std::string	Ship::getSprite(void) const
{
	return (this->sprite);
}

int		Ship::getXPosition(void) const
{
	return (this->x_posShip);
}

int		Ship::getYPosition(void) const
{
	return (this->y_posShip);
}

void	Ship::setBulletPosition(int _x, int _y)
{
	this->x_posBullet = _x;
	this->y_posBullet = _y;
	return ;
}

void	Ship::setBulletType(char _c)
{
	this->bulletType = _c;
	return ;
}

std::string	Ship::getBulletType(void) const
{
	return (this->bulletType);
}

int			Ship::getBulletPos_x() const
{
	return (this->x_posBullet);
}

int			Ship::getBulletPos_y() const
{
	return (this->y_posBullet);
}
