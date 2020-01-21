#pragma once

#include "FindToHensel\Object\Enemy\Enemy.h"

class StraightEnemy :public Enemy
{
public:
	StraightEnemy(int);
	virtual void update(const float& frametime) override;
	virtual void setLevel(const int&) override;
};
