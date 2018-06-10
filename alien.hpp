#ifndef ALIEN_HPP
# define ALIEN_HPP
#include "gameObject.hpp"

class Alien : public gameObject {

private:

public:
	Alien(void);
	~Alien(void);
	Alien(const Alien & _alien);
	Alien	&operator=(const Alien & _rhs);

	void	updatePosition(Game & _game);
};


#endif