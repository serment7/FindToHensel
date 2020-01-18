#include "PowerAttackLevelTwo.h"
#include "Enemy.h"

Skill3::Skill3(float _x, float _y, float _speed, float _tox, float _toy)
	: CSkill()
{
	enemy = nullptr;
	setPos(_x, _y);
	speed = _speed;
	tox = _tox;
	toy = _toy;
	setImg(4, 9);
}
void Skill3::update(const float& frametime, float _x, float _y)
{

	if (fabs(x - tox) < 2)
	{
		y += speed;
	}
	else if (x - tox > 0)
	{
		x -= 2;
	}
	else
	{
		x += 2;
	}
}