#include "AimStraightEnemy.h"

AimStraightEnemy::AimStraightEnemy(int _level, CPlayer* _player)
{
	p_player = _player;
	srand(GetTickCount64());
	setPos(rand() % SCREEN_WIDTH, TRANS_HEIGHT(-1.0f));
	isRight = true;

	setLevel(_level);
	setImage(1, 2 + (_level - 1) * 3);
	time = 0.0f;
	score = _level * 300;
}
void AimStraightEnemy::setAim(int _tox)
{
	tox = _tox;
	if (x < tox)
	{
		isRight = true;
	}
	else
	{
		isRight = false;
	}
}

void AimStraightEnemy::update(const float& frametime)
{
	time += frametime;
	if (y < TRANS_HEIGHT(-0.8f))
	{
		y += speed;
	}
	else if (time < 2)
	{
		setAim(p_player->getX());
		if (isRight)
		{
			if (x < tox)
			{
				x += speed;
			}
		}
		else
		{
			if (x > tox)
			{
				x -= speed;
			}
		}
	}
	else
	{
		y += speed;
	}
}

void AimStraightEnemy::setLevel(int _level)
{
	hp = _level * 5 + 5;
	speed = 2 + _level * 1.5;
}

