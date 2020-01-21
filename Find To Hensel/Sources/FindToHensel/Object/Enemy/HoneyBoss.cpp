#include "FindToHensel\Object\Enemy\HoneyBoss.h"

void HoneyBoss::update(const float& frametime)
{
	
}

void HoneyBoss::setLevel(const int& _level)
{
	setHP(_level * 100);
	setSpeed(2 + _level * 1.5);
}
