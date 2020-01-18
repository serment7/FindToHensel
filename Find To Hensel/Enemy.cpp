#include "Enemy.h"

void Enemy::setPos(float _x, float _y)
{
	x = _x;
	y = _y;
}

void Enemy::setImage(int _obj, int _img)
{
	objectcode = _obj;
	imagecode = _img;
}

int Enemy::getHP()
{
	return hp;
}

int Enemy::getObj()
{
	return objectcode;
}

void Enemy::damaged(int _ap)
{
	hp -= _ap;
}

int Enemy::getImg()
{
	return imagecode;
}

int Enemy::getScore()
{
	return score;
}

float Enemy::getX()
{
	return x;
}

float Enemy::getY()
{
	return y;
}
