#pragma once

#include "Extra.h"
#include <Mmsystem.h>

#pragma comment(lib,"Winmm.lib")
const float FRAME_RATE = 60.0f;               // the target frame rate (frames/sec)
const float MIN_FRAME_RATE = 10.0f;             // the minimum frame rate
const float MIN_FRAME_TIME = 1.0f / FRAME_RATE;   // minimum desired time for 1 frame
const float MAX_FRAME_TIME = 1.0f / MIN_FRAME_RATE; // maximum time used in calculations

class Scene;

class Game
{
private:
	Scene * scene = nullptr;
	Scene * nextScene = nullptr;
	Scene * prevScene = nullptr;
	LARGE_INTEGER timeStart;    // Performance Counter start value
	LARGE_INTEGER timeEnd;      // Performance Counter end value
	LARGE_INTEGER timerFreq;    // Performance Counter frequency
	float   frameTime = 0.f;          // time required for last frame
	float   fps = 0.f;                // frames per second
	DWORD   sleepTime = 0;          // number of milli-seconds to sleep between frames
	bool    paused = 0.f;             // true if game is paused
	bool    initialized = 0.f;
public:
	Game() = default;
	~Game();
	void start();
	void update();
	void lastUpdate();
	void stop();
	void messageHandler();
};
