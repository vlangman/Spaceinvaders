#ifndef GAMEOBJECT_HPP
# define GAMEOBJECT_HPP
#include <iostream>

class gameObject {

private:
	int x_pos;
	int y_pos;
	std::string sprite;

public:
	gameObject(void);
	~gameObject(void);

	gameObject(const gameObject & _entity);
	gameObject & operator=(const gameObject & _entityRhs);

	//setters
	void setSprite(char _c);
	void setPosition(int _x, int _y);

	//getters
	int	getXPosition(void) const;
	int	getYPosition(void) const;
	std::string getSprite(void) const;
};

#endif