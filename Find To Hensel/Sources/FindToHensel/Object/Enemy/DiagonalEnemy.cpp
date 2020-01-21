#include "FindToHensel\Object\Enemy\DiagonalEnemy.h"

DiagonalEnemy::DiagonalEnemy(int _level, float _x, float _y, bool goRight)
	: Enemy()
{
	setLevel(_level);
	setPos(_x, _y);

	const float speed = getSpeed();

	if (goRight)
	{
		MoveDir = D3DXVECTOR2(speed, speed);
	}
	else
	{
		MoveDir = D3DXVECTOR2(-speed, speed);
	}

	setImage(1, (_level - 1) * 3);
	setScore(100 * _level);
}
void DiagonalEnemy::update(const float & frametime)
{
	move(MoveDir);
}
void DiagonalEnemy::setLevel(const int& _level)
{
	setHP(_level * 5);
	setSpeed(2 + _level * 1.5);
}
