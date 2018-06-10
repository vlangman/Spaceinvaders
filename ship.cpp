#include "ship.hpp"

//start canonical
Ship::Ship(void)
{
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
