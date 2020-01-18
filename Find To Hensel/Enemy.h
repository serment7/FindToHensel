#pragma once
#include "Extra.h"
#include "Player.h"

class Enemy
{
protected:
	int hp;
	float speed;
	int objectcode;
	int imagecode;
	float x, y;
	float time;
	float timer;
	bool isRight;
	int score;
public:
	Enemy() = default;
	virtual void update(const float& frametime)=0;
	virtual void setLevel(int) = 0;
	void setPos(float,float);
	void setImage(int, int);
	int getHP();
	int getObj();
	virtual void damaged(int);
	int getImg();
	int getScore( );
	float getX();
	float getY();
};
