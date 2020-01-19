#include "FindToHensel\Skill\PowerAttackLevelOne.h"

Skill2::Skill2(float _x, float _y, float _speed)
	:CSkill()
{
	setPos(_x, _y);
	speed = _speed;
	setImg(4, 10);
}
void Skill2::update(const float& frametime, float _x, float _y)
{
	y += speed;
}
