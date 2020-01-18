#pragma once

#include "Enemy.h"

class DiagonalEnemy :public Enemy
{
private:
public:
	DiagonalEnemy(int, float, float, bool);
	virtual void update(const float& frametime);
	virtual void setLevel(int);
};
