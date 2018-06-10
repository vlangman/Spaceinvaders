#ifndef SHIP_HPP
# define SHIP_HPP
# include "gameObject.hpp"
# include "bullet.hpp"
# include "game.hpp"
# include <iostream>


class Ship : public gameObject {
	private:
		

	public:
		Ship(void);
		~Ship(void);

		Ship(const Ship & _ship);
		Ship		&operator=(const Ship & _rhs);
};

#endif
