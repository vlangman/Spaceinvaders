#ifndef GAMEOBJECT_HPP
# define GAMEOBJECT_HPP
# include <iostream>

class gameObject
{
	private:
		int				x_pos;
		int				y_pos;
		std::string		sprite;

	public:
		gameObject(void);
		~gameObject(void);

		gameObject(const gameObject & _entity);
		gameObject	&operator=(const gameObject & _entityRhs);


		int				getXPosition(void) const;
		int				getYPosition(void) const;
		void			setPosition(int _x, int _y);
		void			setSprite(char _c);
		virtual void	updatePosition(void);

		std::string	getSprite(void) const;
};

#endif
