#include "StraightEnemy.h"

StraightEnemy::StraightEnemy(int _level)
{
	srand(GetTickCount64());
	setLevel(_level);
	setPos(rand() % SCREEN_WIDTH, TRANS_HEIGHT(-1.0f));
	setImage(1, 1 + (_level - 1) * 3);
	score = _level * 200;
}
void StraightEnemy::update(const float& frametime)
{
	y += speed;
}
void StraightEnemy::setLevel(int _level)
{
	hp = _level * 5 + 10;
	speed = 1 + _level * 1.5;
}
