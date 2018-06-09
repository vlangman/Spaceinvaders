#include "gameObject.hpp"

gameObject::gameObject(void)
{
	return;
}

gameObject::~gameObject(void)
{
	return;
}

gameObject::gameObject(const gameObject & _entity)
{
	*this = _entity;
	return;
}

gameObject	&gameObject::operator=(const gameObject & _entityRhs)
{
	*this = _entityRhs;
	return *this;
}

int			gameObject::getXPosition(void) const
{
	return this->x_pos;
}

int			gameObject::getYPosition(void) const
{
	return this->y_pos;
}


void		gameObject::setSprite(char _c)
{
	this->sprite = _c;
	return;
}

std::string	gameObject::getSprite(void) const
{
	return (this->sprite);
}

void		gameObject::setPosition(int _x, int _y)
{
	this->x_pos = _x;
	this->y_pos = _y;
	return;
}
