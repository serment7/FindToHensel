#include "FindToHensel\Object\Enemy\DiagonalEnemy.h"

DiagonalEnemy::DiagonalEnemy(int _level, float _x, float _y, bool goRight)
{
	setLevel(_level);
	setPos(_x, _y);
	isRight = goRight;
	setImage(1, (_level - 1) * 3);
	score = 100 * _level;
}
void DiagonalEnemy::update(const float& frametime)
{
	if (isRight)
	{
		x += speed;
		y += speed;
	}
	else
	{
		x -= speed;
		y += speed;
	}
}
void DiagonalEnemy::setLevel(int _level)
{
	hp = _level * 5;
	speed = 2 + _level * 1.5;
}
