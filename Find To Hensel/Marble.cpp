#include "Marble.h"

Marble::Marble(float _x, float _y, int _img)
{
	x = _x;
	y = _y;
	speed = 3.0f;
	setImg(4, _img);
}

void Marble::update(const float& frametime)
{
	y += speed;
}

void Marble::setPos(float _x, float _y)
{
	x = _x;
	y = _y;
}

void  Marble::setImg(int _obj, int _img)
{
	objectcode = _obj;
	imagecode = _img;
}

float  Marble::getX() { return x; }
float  Marble::getY() { return y; }
int Marble::getObj() { return objectcode; }
int Marble::getImg() { return imagecode; }
