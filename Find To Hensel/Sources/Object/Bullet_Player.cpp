#include"FindToHensel\Object\Bullet_Player.h"

void Bullet_Player::SetPos(int _x, int _y)
{
	x = _x;
	y = _y;
}
void Bullet_Player::update()
{
	y -= speed;
}
void Bullet_Player::setSpeed(float _speed)
{
	speed = _speed;
}
int Bullet_Player::getObj()
{
	return objectcode;
}
int Bullet_Player::getImg()
{
	return imagecode;
}
float Bullet_Player::getX()
{
	return (float)x;
}
float Bullet_Player::getY()
{
	return (float)y;
}
void Bullet_Player::setImage(int _obj, int _img)
{
	objectcode = _obj;
	imagecode = _img;
}
Bullet_Player::Bullet_Player(int x, int y,int img)
{
	SetPos(x, y);
	speed = 10;
	objectcode = 3;
	imagecode = img;
}
