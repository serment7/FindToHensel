#pragma once

#include "Enemy.h"

class AimStraightEnemy :public Enemy
{
private:
	CPlayer* p_player;
	float tox;
public:
	AimStraightEnemy(int, CPlayer*);
	virtual void update(const float& frametime);
	void setAim(int);
	virtual void setLevel(int);
};
