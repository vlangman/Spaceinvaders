#include "alien.hpp"

//start canonical
Alien::Alien(void)
{
	return ;
}

Alien::~Alien(void)
{
	return ;
}

Alien::Alien(const Alien & _alien)
{
	*this = _alien;
	return ;
}

Alien	&Alien::operator=(const Alien & _rhs)
{
	*this = _rhs;
	return (*this);
}

void	Alien::updatePosition(Game & _game)
{
	this->setPosition(this->getXPosition(), this->getYPosition() + 1);
	
}

//end canonical!!
