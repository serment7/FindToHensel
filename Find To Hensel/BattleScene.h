#pragma once
#include "Scene.h"
#include <vector>
#include <Windows.h>

class CPlayer;
class Bullet_Player;
class Enemy;
class CSkill;
class Marble;

class Battle :public Scene
{
private:
	CPlayer* player = nullptr;
	std::vector<Bullet_Player*> bullet_player;
	std::vector<Enemy*> enemy_list;
	std::vector<CSkill*> skill_list;
	std::vector<Marble*> marble_list;
	float animation = 0.f;
	float bullet_timer = 0.f;
	int bullet = 0;
	float boss_timer=0.f;
	float game_timer =0.f;
	float enemy_timer=0.f;
	DWORD alpha = 0x000000;
	bool player_powerup = false;
	bool isBack = false;
	int level = -1;
	bool clear = false;
	int score = -1;

	bool player_hitted = false;
	int skillcount = 0;
	float skill_timer = 0.f;
	bool active_shield = false;
	float shield_timer = 0.f;
	bool getSkill = false;
public:
	Battle() = default;
	virtual void start();
	virtual Scene* update(const float& frametime);
	virtual void stop();
	virtual void messageHandler();
	void collision();
	int counter;
};