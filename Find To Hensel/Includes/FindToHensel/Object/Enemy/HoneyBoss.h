#pragma once

#include "FindToHensel\Object\Enemy\Enemy.h"

class HoneyBoss :
	public Enemy
{
	// CBoss을(를) 통해 상속됨
	virtual void update(const float& frametime) override;
	virtual void setLevel(const int&) override;

private:
	float Pattern_Timer = 3.f;
};

