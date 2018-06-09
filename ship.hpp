#ifndef SHIP_HPP
#define SHIP_HPP

class Ship {

	private:
		int x_pos;
		int y_pos;
		char sprite;

	public:
		Ship(void);
		~Ship(void);

		Ship(const Ship & _ship);
		Ship	&operator=(const Ship & _rhs);

		void	setPosition(int _x, int _y);
		void	setSprite(char _c);

		char	getSprite(void) const;
		int		getXPosition(void) const;
		int		getYPosition(void) const;
};

#endif
