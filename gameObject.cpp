#include "gameObject.hpp"

//start
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
	this->sprite = _entity.getSprite();
	return;
}

gameObject& gameObject::operator=(const gameObject & _entityRhs)
{
	this->sprite = _entityRhs.getSprite();
	return *this;
}
//end

void	gameObject::setPosition(int _x, int _y)
{
	this->x_pos = _x;
	this->y_pos = _y;
	return ;
}

void	gameObject::setSprite(char _c)
{
	this->sprite = _c;
	return ;
}

std::string	gameObject::getSprite(void) const
{
	return (this->sprite);
}

int		gameObject::getXPosition(void) const
{
	return (this->x_pos);
}

int		gameObject::getYPosition(void) const
{
	return (this->y_pos);
}

void	gameObject::updatePosition(void)
{
	return ;
}
