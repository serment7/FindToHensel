#include "FindToHensel\Extra.h"
#include "FindToHensel\Object\Enemy\StraightEnemy.h"
#include "FindToHensel\Object\Player.h"
#include "FindToHensel\Extra.h"
#ifdef _DEBUG
#define new new(_CLIENT_BLOCK, __FILE__, __LINE__)
#endif
StraightEnemy::StraightEnemy(int _level)
	:Enemy()
{
	srand(GetTickCount64());
	setLevel(_level);
	setPos(rand() % SCREEN_WIDTH, TRANS_HEIGHT(-1.0f));
	setImage(1, 1 + (_level - 1) * 3);
	setScore(_level * 200);
}
void StraightEnemy::update(const float& frametime)
{
	move(0.f, getSpeed());
}
void StraightEnemy::setLevel(const int& _level)
{
	setHP(_level * 5 + 10);
	setSpeed(1 + _level * 1.5);
}
