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
	Game() = default;
	~Game();
	void start();
	void update();
	void lastUpdate();
	void stop();
	void messageHandler();
};
