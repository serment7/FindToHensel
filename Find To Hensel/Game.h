#include"Scene.h"
#include <Windows.h>
#include <Mmsystem.h>
#include"Input.h"

#pragma comment(lib,"Winmm.lib")
const float FRAME_RATE = 60.0f;               // the target frame rate (frames/sec)
const float MIN_FRAME_RATE = 10.0f;             // the minimum frame rate
const float MIN_FRAME_TIME = 1.0f / FRAME_RATE;   // minimum desired time for 1 frame
const float MAX_FRAME_TIME = 1.0f / MIN_FRAME_RATE; // maximum time used in calculations

class Game
{
private:
	Scene * scene;
	Scene * nextScene;
	Scene * prevScene;
	LARGE_INTEGER timeStart;    // Performance Counter start value
	LARGE_INTEGER timeEnd;      // Performance Counter end value
	LARGE_INTEGER timerFreq;    // Performance Counter frequency
	float   frameTime;          // time required for last frame
	float   fps;                // frames per second
	DWORD   sleepTime;          // number of milli-seconds to sleep between frames
	bool    paused;             // true if game is paused
	bool    initialized;
public:
	Game();
	~Game();
	void start();
	void update();
	void lastUpdate();
	void stop();
	void messageHandler();
};
Game::Game()
{
}
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
		fps = (fps*0.99f) + (0.01f / frameTime);  // average fps
	if (frameTime > MAX_FRAME_TIME) // if frame rate is very slow
		frameTime = MAX_FRAME_TIME; // limit maximum frameTime
	timeStart = timeEnd;
	nextScene=scene->update(frameTime);
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