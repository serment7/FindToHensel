#pragma once

#include "Enemy.h"

class StraightEnemy :public Enemy
{
private:
public:
	StraightEnemy(int);
	virtual void update(const float& frametime);
	virtual void setLevel(int);
};
