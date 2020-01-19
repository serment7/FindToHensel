#pragma once

#include "FindToHensel\Skill\Skill.h"

class Skill2 :public CSkill
{
public:
	Skill2() = default;
	Skill2(float _x, float _y, float _speed);
	void update(const float& frametime, float _x, float _y);
};
