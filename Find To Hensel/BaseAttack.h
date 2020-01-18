#pragma once
#include "Skill.h"

class Skill1 :public CSkill
{
public:
	Skill1() = default;
	Skill1(float, float, float, int, float);
	void update(const float&, float, float);
	float time;
	float timer;
};
