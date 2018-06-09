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
