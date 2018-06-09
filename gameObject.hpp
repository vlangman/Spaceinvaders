#ifndef GAMEOBJECT_HPP
# define GAMEOBJECT_HPP
# include <iostream>
# include "ship.hpp"

class gameObject : public Ship
{
	private:
		std::string sprite;

	public:
		gameObject(void);
		~gameObject(void);

		gameObject(const gameObject & _entity);
		gameObject	&operator=(const gameObject & _entityRhs);
};

#endif
