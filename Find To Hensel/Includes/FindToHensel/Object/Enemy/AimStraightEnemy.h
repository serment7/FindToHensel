#pragma once

#include "FindToHensel\Object\Enemy\Enemy.h"

class CPlayer;

class AimStraightEnemy :public Enemy
{
private:
	CPlayer* p_player;
	float tox;
public:
	AimStraightEnemy(int, CPlayer*);
	virtual void update(const float& frametime) override;
	void traceTarget(int);
	virtual void setLevel(const int&) override;
};
