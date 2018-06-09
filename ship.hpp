#ifndef SHIP_HPP
# define SHIP_HPP
# include <iostream>

class Ship
{
	private:
		int			x_posShip;
		int			y_posShip;
		std::string	sprite;
		int			maxBullets;
		std::string	bulletType;
		int			x_posBullet;
		int			y_posBullet;

	public:
		Ship(void);
		~Ship(void);

		Ship(const Ship & _ship);
		Ship		&operator=(const Ship & _rhs);

		void		setPosition(int _x, int _y);
		void		setSprite(char _c);

		std::string	getSprite(void) const;
		int			getXPosition(void) const;
		int			getYPosition(void) const;

		void		setBulletPosition(int _x, int _y);
		void		setBulletType(char _c);
		std::string	getBulletType() const;
		int			getBulletPos_x() const;
		int			getBulletPos_y() const;
};

#endif
