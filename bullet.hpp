#ifndef BULLET_HPP
# define BULLET_HPP
# include "gameObject.hpp"
# include <iostream>

class Game;

class Bullet : public gameObject {
	private:
		int		direction;

	public:
		Bullet(void);
		~Bullet(void);

		Bullet(const Bullet & _bullet);
		Bullet(const int _direction);
		Bullet		&operator=(const Bullet & _rhs);

		void	updatePosition(Game &_game);
};

#endif
