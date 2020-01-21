#pragma once

#include "FindToHensel\Object\Enemy\Enemy.h"

class DiagonalEnemy :public Enemy
{
private:
	D3DXVECTOR2 MoveDir;
public:
	DiagonalEnemy(int, float, float, bool);
	
	virtual void update(const float& frametime) override;
	virtual void setLevel(const int&) override;
};
