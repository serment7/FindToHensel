#include "FindToHensel\Scene\BattleScene.h"
#include "FindToHensel\Scene\StartScene.h"
#include "FindToHensel\System\ImageManager.h"
#include "FindToHensel\System\Input.h"

void Start::start()
{
	imageManager = new ImageManager;
	directInput = new CDirectInput;
	logoTime = 2;
	gameStart = 1;
	gameEnd = 0;
	imageManager->createDevice(g_hWnd, SCREEN_WIDTH, SCREEN_HEIGHT, g_windowed);
	imageManager->loadStart();
	directInput->Initialize(g_hWnd);
	isStart = false;
	imageManager->setFade(0);

}
Scene* Start::update(const float& frametime)
{
	directInput->Update();

	if (isStart)
	{
		this->stop();
		return new Battle;
	}
	if (logoTime > 0)
	{

		imageManager->beginScene();
		imageManager->drawLogo();
		imageManager->endScene();
		logoTime -= frametime;
	}
	else
	{
		messageHandler();
		imageManager->beginScene();
		imageManager->drawStart(gameStart, gameEnd);
		imageManager->endScene();
	}
	return nullptr;
}
void Start::stop()
{
	SAFE_DELETE(directInput);
	SAFE_DELETE(imageManager);
}
void Start::messageHandler()
{
	if (directInput->GetKeyboardState(DOWN, DIK_DOWNARROW))
	{
		gameStart = 0;
		gameEnd = 1;
	}
	if (directInput->GetKeyboardState(DOWN, DIK_UPARROW))
	{
		gameStart = 1;
		gameEnd = 0;
	}
	if (directInput->GetKeyboardState(DOWN, DIK_RETURN))
	{
		if (gameStart == 1)
		{
			isStart = true;
		}
		if (gameEnd == 1)
			PostQuitMessage(0);
	}

}