#include "FindToHensel\Object\Enemy\Enemy.h"

void Enemy::move(const D3DXVECTOR2& _dir)
{
	pos += _dir;
}

void Enemy::move(const float& _dirX, const float& _dirY)
{
	move(D3DXVECTOR2(_dirX, _dirY));
}

void Enemy::setPos(const float& _x, const float& _y)
{
	pos.x = _x;
	pos.y = _y;
}

void Enemy::setPos(const D3DXVECTOR2& _pos)
{
	pos = _pos;
}

void Enemy::setImage(const int& _obj, const int& _img)
{
	objectcode = _obj;
	imagecode = _img;
}

void Enemy::setHP(const int& _hp)
{
	hp = _hp;
}

void Enemy::setObj(const int& _obj)
{
	objectcode = _obj;
}

void Enemy::setScore(const int& _score)
{
	score = _score;
}

void Enemy::setSpeed(const int& _speed)
{
	speed = _speed;
}

const int& Enemy::getHP() const
{
	return hp;
}

const int& Enemy::getObj() const
{
	return objectcode;
}

void Enemy::damaged(int _ap)
{
	hp -= _ap;
}

const int& Enemy::getImg() const
{
	return imagecode; 
}

const int& Enemy::getScore() const
{
	return score;
}

const int& Enemy::getSpeed() const
{
	return speed;
}

const float& Enemy::getX() const
{
	return pos.x;
}

const float& Enemy::getY() const
{
	return pos.y;
}

const D3DXVECTOR2& Enemy::getPos() const
{
	return pos;
}
