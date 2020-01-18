#include "Player.h"

void CPlayer::moveLeft()
{
	if ((x-speed)>0)
		x -= speed;
}
void CPlayer::moveRight()
{
	if ((x+speed)<768)
		x += speed;
}
void CPlayer::SetPos(int _x,int _y)
{
	x = _x;
	y = _y;
}
void CPlayer::update(const float& frametime)
{
	if (hitted)
	{
		time += frametime;
		if (time > 1)
		{
			time = 0;
			hitted = false;
			imagecode -= 2;
		}
	}
	if (hitted)
	{
		imagecode += 1;
		if (imagecode > 3)
			imagecode = 2;
	}
	else
	{
		imagecode += 1;
		if (imagecode > 1)
			imagecode = 0;
	}
}
void CPlayer::setSpeed(float _speed)
{
	speed = _speed;
}
void CPlayer::setHP(int _hp)
{
	hp = _hp;
}
int CPlayer::getObj()
{
	return objectcode;
}
int CPlayer::getImg()
{
	return imagecode;
}
float CPlayer::getX()
{
	return (float)x;
}
float CPlayer::getY()
{
	return (float)y;
}
void CPlayer::setImage(int _obj, int _img)
{
	objectcode = _obj;
	imagecode = _img;
	hitted = false;
}
void CPlayer::damaged()
{
	hp -= 1;
}
int CPlayer::getHP()
{
	return hp;
}
void CPlayer::setAP(int _ap)
{
	ap = _ap;
}
int CPlayer::getAP()
{
	return ap;
}
void CPlayer::setHit(bool _hit)
{
	hitted = _hit;
	if (hitted)
	{
		imagecode = 2;
		time = 0;
	}
	else
	{
		imagecode = 0;
	}
	
}
