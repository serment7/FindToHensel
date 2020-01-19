#include "FindToHensel\Game.h"
#include "FindToHensel\Scene\Scene.h"
#include "FindToHensel\Scene\StartScene.h"
#include "FindToHensel\System\Input.h"

Game::~Game()
{
	stop();
}

void Game::start()
{
	scene = new Start;
	nextScene = nullptr;
	scene->start();
	QueryPerformanceFrequency(&timerFreq);
	QueryPerformanceCounter(&timeStart);
}
void Game::update()
{
	QueryPerformanceCounter(&timeEnd);
	frameTime = (float)(timeEnd.QuadPart - timeStart.QuadPart) / (float)timerFreq.QuadPart;
	if (frameTime < MIN_FRAME_TIME)
	{
		sleepTime = (DWORD)((MIN_FRAME_TIME - frameTime) * 1000);
		timeBeginPeriod(1);         // Request 1mS resolution for windows timer
		Sleep(sleepTime);           // release cpu for sleepTime
		timeEndPeriod(1);           // End 1mS timer resolution
		return;
	}
	if (frameTime > 0.0)
		fps = (fps * 0.99f) + (0.01f / frameTime);  // average fps
	if (frameTime > MAX_FRAME_TIME) // if frame rate is very slow
		frameTime = MAX_FRAME_TIME; // limit maximum frameTime
	timeStart = timeEnd;
	nextScene = scene->update(frameTime);
	if (nextScene)
	{
		stop();
		scene = nextScene;
		scene->start();
		nextScene = nullptr;
	}
}
void Game::stop()
{
	SAFE_DELETE(scene);
}
