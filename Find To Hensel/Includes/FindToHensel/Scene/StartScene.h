#pragma once

#include "FindToHensel\Scene\Scene.h"

class Start :
	public Scene
{
private:
	int gameStart = 0;
	int gameEnd = 0;
	int alphaControl = 0;
	float logoTime = 0.f;
	bool isStart = false;
	friend class Battle;

public:
	Start() = default;
	virtual void start();
	Scene* update(const float&);
	virtual void stop();
	virtual void messageHandler();
};

