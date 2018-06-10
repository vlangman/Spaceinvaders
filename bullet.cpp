#include "bullet.hpp"
#include "game.hpp"

//start canonical
Bullet::Bullet(void)
{
	return ;
}

Bullet::~Bullet(void)
{
	return ;
}

Bullet::Bullet(const Bullet & _bullet)
{
	*this = _bullet;
	return ;
}

Bullet::Bullet(const int _direction)
{
	this->direction = _direction;
}

Bullet	&Bullet::operator=(const Bullet & _rhs)
{
	*this = _rhs;
	return (*this);
}

void	Bullet::updatePosition(Game & _game)
{
	
	
	this->setPosition(this->getXPosition(), this->getYPosition() + this->direction);
	
	return;
}
//end canonical!!
