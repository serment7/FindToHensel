#pragma once

#include "FindToHensel\Object\Enemy\Enemy.h"

class HoneyBoss :
	public Enemy
{
	// CBoss��(��) ���� ��ӵ�
	virtual void update(const float& frametime) override;
	virtual void setLevel(const int&) override;

private:
	float Pattern_Timer = 3.f;
};

