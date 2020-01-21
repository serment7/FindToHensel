#include "FindToHensel\Skill\BaseAttack.h"

Skill1::Skill1(float _x, float _y, float _speed, int _img, float _time)
	: CSkill()
{
	time = _time;
	timer = 0.f;
	setPos(_x, _y);
	speed = _speed;
	setImg(4, _img);
}

void Skill1::update(const float& frametime, float _x, float _y)
{
	if (time > 0) {
		x = _x;
		time -= frametime;
	}
	else
	{
		y += speed;
	}
}