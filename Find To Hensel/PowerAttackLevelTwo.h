#pragma once

#include "Skill.h"

class Skill3 :public CSkill
{
private:
	int tox, toy;
	class Enemy* enemy;
public:
	Skill3() = default;
	Skill3(float _x, float _y, float _speed, float _tox, float _toy);
	void update(const float& frametime, float _x, float _y);
};

