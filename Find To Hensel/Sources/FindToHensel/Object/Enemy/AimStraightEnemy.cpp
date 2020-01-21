#include "FindToHensel\Object\Enemy\AimStraightEnemy.h"
#include "FindToHensel\Object\Player.h"
#include "FindToHensel\Extra.h"

AimStraightEnemy::AimStraightEnemy(int _level, CPlayer* _player)
	: Enemy()
{
	p_player = _player;
	srand(GetTickCount64());
	setPos(rand() % SCREEN_WIDTH, TRANS_HEIGHT(-1.0f));

	setLevel(_level);
	setImage(1, 2 + (_level - 1) * 3);
	time = 0.0f;
	setScore(_level * 300);
}
void AimStraightEnemy::traceTarget(int _tox)
{
	const float& MoveForceX = _tox - getX();

	setPos(!!MoveForceX * getSpeed(), 0.f);
}

void AimStraightEnemy::update(const float& frametime)
{
	if (p_player == nullptr || p_player->getHP() < 1)
	{
		return;
	}

	time += frametime;

	const D3DXVECTOR2& CurPos = getPos();
	const float MoveDir = CurPos.x - tox;

	if (CurPos.y < TRANS_HEIGHT(-0.8f))
	{
		move(0.f, getSpeed());
	}
	else if (time < 2)
	{
		traceTarget(p_player->getX());
	}
	else
	{
		move(0.f, getSpeed());
	}
}

void AimStraightEnemy::setLevel(const int& _level)
{
	setHP(_level * 5 + 5);
	setSpeed(2 + _level * 1.5);
}

