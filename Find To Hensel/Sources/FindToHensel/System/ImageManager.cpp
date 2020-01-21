#include "FindToHensel\System\ImageManager.h"

void ImageManager::initD3Dpp()
{
	DWORD behavior;
	D3DCAPS9 caps9;
	pDirect3D9 = Direct3DCreate9(D3D_SDK_VERSION);
	ZeroMemory(&d3dpp, sizeof(d3dpp));
	d3dpp.BackBufferFormat = D3DFMT_X8R8G8B8;
	d3dpp.BackBufferHeight = screen_height;
	d3dpp.BackBufferWidth = screen_width;
	d3dpp.FullScreen_RefreshRateInHz = D3DPRESENT_RATE_DEFAULT;
	d3dpp.hDeviceWindow = hWnd;
	d3dpp.Windowed = windowed;
	d3dpp.PresentationInterval = D3DPRESENT_INTERVAL_IMMEDIATE;
	d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
	pDirect3D9->GetDeviceCaps(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, &caps9);
	if ((caps9.DevCaps&D3DDEVCAPS_HWTRANSFORMANDLIGHT) == 0 || caps9.VertexShaderVersion < D3DVS_VERSION(1, 1))
		behavior = D3DCREATE_SOFTWARE_VERTEXPROCESSING;
	else
		behavior = D3DCREATE_HARDWARE_VERTEXPROCESSING;
	pDirect3D9->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, hWnd, behavior, &d3dpp, &pDevice3D9);
	D3DXCreateSprite(pDevice3D9, &pSprite);
}

void ImageManager::loadPath()
{
	player_path[0] = GRETEL_NORMAL_1;
	player_path[1] = GRETEL_NORMAL_2;
	player_path[2] = GRETEL_HIT_1;
	player_path[3] = GRETEL_HIT_2;
	enemy_path[0]=HONEY_BEE;
	enemy_path[1] = HONEY_SLIME;
	enemy_path[2] = HONEY_BEAR;
	enemy_path[3]=STRAW_RABBIT;
	enemy_path[4]=STRAW_CHICK;
	enemy_path[5]=STRAW_MOUSE;
	enemy_path[6]=CANDY_DEVIL;
	enemy_path[7]=KISSES_DEVIL;
	enemy_path[8]=ICE_DEVIL;
	boss_path[0]=HONEY_BOSS;
	boss_path[1] = HONEY_BOSS_HIT;
	boss_path[2]=STRAW_BOSS;
	boss_path[3] = STRAW_BOSS_HIT;
	boss_path[4]=DEVIL_BOSS;
	boss_path[5] = DEVIL_BOSS_HIT;
	bullet_path[0]=BULLET_BOSS;
	bullet_path[1]=METEOR;
	bullet_path[2]=BULLET_PLAYER;
	bullet_path[3]=BULLET_PLAYER_POWER;
	skill_path[0] = MARBLE1;
	skill_path[1] = MARBLE2;
	skill_path[2] = MARBLE3;
	skill_path[3] = SHIELD_ITEM;
	skill_path[4] = SHIELD;
	skill_path[5] = BULLET_POWER;
	skill_path[6] = SKILL1_1;
	skill_path[7] = SKILL1_2;
	skill_path[8] = SKILL1_3;
	skill_path[9] = SKILL2;
	skill_path[10] = SKILL3;
	number_path[0] = NUMBER_0;
	number_path[1] = NUMBER_1;
	number_path[2] = NUMBER_2;
	number_path[3] = NUMBER_3;
	number_path[4] = NUMBER_4;
	number_path[5] = NUMBER_5;
	number_path[6] = NUMBER_6;
	number_path[7] = NUMBER_7;
	number_path[8] = NUMBER_8;
	number_path[9] = NUMBER_9;
}
void ImageManager::releaseAll()
{
	SAFE_RELEASE(pSprite);
	SAFE_RELEASE(pDevice3D9);
	SAFE_RELEASE(pDirect3D9);
}
ImageManager::~ImageManager()
{
	releaseAll();
}
void ImageManager::createDevice(const HWND& _hWnd, const int& _width, const int& _height, bool _windowed)
{
	hWnd = _hWnd;
	screen_width = _width;
	screen_height = _height;
	windowed = _windowed;
	initD3Dpp();
}
void ImageManager::loadImages()
{
	clear.rt = { 0, };
	loadImage(CLEAR, clear);
	map1.rt = { 0, };
	loadImage(MAP1, map1);
	loadImage(DANGER, danger);
	map1.rt.top = map1.rt.bottom - SCREEN_HEIGHT;
	maprt = map1.rt;
	loadImage(HEART, heart_image);
	for(int i = 0; i < 4; ++i)
	{
		loadImage(player_path[i], player_image[i]);
	}
	for (int i = 0; i < 9; ++i)
	{
		loadImage(enemy_path[i], enemy_image[i]);
	}
	for (int i = 0; i < 6; ++i)
	{
		loadImage(boss_path[i], boss_image[i]);
	}
	for (int i = 0; i < 4; ++i)
	{
		loadImage(bullet_path[i], bullet_image[i]);
	}
	for (int i = 0; i < 10; ++i)
	{
		loadImage(skill_path[i], skill_image[i]);
	}
	for (int i = 0; i < 10; ++i)
	{
		loadImage(number_path[i], number[i]);
	}
}
void ImageManager::loadImage(const char*_path,IMAGE& image)
{
	ZeroMemory(&image.image_info, sizeof(&image.image_info));
	D3DXGetImageInfoFromFile(_path, &image.image_info);
	image.rt = { 0, };
	result = D3DXCreateTextureFromFileEx(pDevice3D9, _path, D3DX_DEFAULT_NONPOW2, D3DX_DEFAULT_NONPOW2,
		1, 0, D3DFMT_UNKNOWN, D3DPOOL_DEFAULT, D3DX_DEFAULT, D3DX_DEFAULT, D3DCOLOR_XRGB(255, 0, 255), &image.image_info, NULL, &image.image);
	image.center = D3DXVECTOR3(image.image_info.Width / 2, image.image_info.Height / 2, 0);
	image.rt.right = image.image_info.Width;
	image.rt.bottom = image.image_info.Height;
}
void ImageManager::beginScene()
{
	pDevice3D9->Clear(0, nullptr, D3DCLEAR_TARGET, D3DCOLOR_XRGB(255, 255, 255), 0.0f, 0);
	pDevice3D9->BeginScene();
	pSprite->Begin(D3DXSPRITE_ALPHABLEND);

}
void ImageManager::endScene()
{

	pSprite->End();
	pDevice3D9->EndScene();
	pDevice3D9->Present(NULL, NULL, NULL, NULL);
}

void ImageManager::draw(int objectcode,int imagecode,D3DXVECTOR3 pos)
{
	switch (objectcode)
	{
	case PLAYER_CODE:
		pSprite->Draw(player_image[imagecode].image, &player_image[imagecode].rt, &player_image[imagecode].center, &pos, (DWORD)0xffffffff);
		break;
	case ENEMY_CODE:
		pSprite->Draw(enemy_image[imagecode].image, &enemy_image[imagecode].rt, &enemy_image[imagecode].center, &pos, (DWORD)0xffffffff);
		break;
	case BOSS_CODE:
		pSprite->Draw(boss_image[imagecode].image, &boss_image[imagecode].rt, &boss_image[imagecode].center, &pos, (DWORD)0xffffffff);
		break;
	case BULLET_CODE:
		pSprite->Draw(bullet_image[imagecode].image, &bullet_image[imagecode].rt, &bullet_image[imagecode].center, &pos, (DWORD)0xffffffff);
		break;
	case SKILL_CODE:
		pSprite->Draw(skill_image[imagecode].image, &skill_image[imagecode].rt, &skill_image[imagecode].center, &pos, (DWORD)0xffffffff);
		break;
	}
}
void ImageManager::drawMap()
{
	pSprite->Draw(map1.image, &map1.rt, NULL, &D3DXVECTOR3(0.0f, 0.0f, 0.0f), (D3DCOLOR)0xffffffff);
	map1.rt.top -= 2;
	map1.rt.bottom -= 2;
	if (map1.rt.bottom<2769)
	{
		map1.rt.top = maprt.top;
		map1.rt.bottom = maprt.bottom;
	}
}
void ImageManager::drawClear()
{
	pSprite->Draw(clear.image, &clear.rt, &clear.center, &D3DXVECTOR3(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 0.0f), (D3DCOLOR)0xffffffff);
}
void ImageManager::drawHeart(int HP)
{
	for (int i = 0; i < HP; ++i)
	{
		pSprite->Draw(heart_image.image, &heart_image.rt, &heart_image.center, &D3DXVECTOR3(50 + (i * 100),TRANS_HEIGHT(-0.9),0.0f), (D3DCOLOR)0xffffffff);
	}
}
void ImageManager::loadStart()
{
	loadImage(LOGO, Logo);
	loadImage(TITLE, title);
	loadImage(STARTUNFOCUS, gameStart[0]);
	loadImage(STARTFOCUS, gameStart[1]);
	loadImage(ENDUNFOCUS, gameEnd[0]);
	loadImage(ENDFOCUS, gameEnd[1]);
	title.rt.bottom = SCREEN_HEIGHT;
}
void ImageManager::drawStart(int start,int end)
{
	pSprite->Draw(title.image, &title.rt, NULL, &D3DXVECTOR3(0.0f, 0.0f, 0.0f), (DWORD)0xffffffff);
	pSprite->Draw(gameStart[start].image, &gameStart[start].rt, &gameStart[start].center, &D3DXVECTOR3(TRANS_WIDTH(0), TRANS_HEIGHT(0.60), 0.0f), (DWORD)0xffffffff);
	pSprite->Draw(gameEnd[end].image, &gameEnd[end].rt, &gameEnd[end].center, &D3DXVECTOR3(TRANS_WIDTH(0), TRANS_HEIGHT(0.80), 0.0f), (DWORD)0xffffffff);
}
void ImageManager::drawLogo()
{
	pSprite->Draw(Logo.image, &Logo.rt, &D3DXVECTOR3((float)SCREEN_WIDTH / 2, (float)SCREEN_HEIGHT / 2,0.0f), &D3DXVECTOR3((float)SCREEN_WIDTH / 2, (float)SCREEN_HEIGHT / 2, 0.0f), D3DCOLOR_COLORVALUE(1, fade, fade, fade));
	if ((fade +0.2f)< 1)
	{
		fade += 0.01f;
	}
}
void ImageManager::setFade(float _fade)
{
	fade = _fade;
}
void ImageManager::drawScore(int _score)
{
	int j=0;
	int set = 1;
	for (int i = 0; i < 6; ++i)
	{
		j=(_score % (set*10))/set;
		pSprite->Draw(number[j].image, &number[j].rt, &number[j].center, &D3DXVECTOR3(TRANS_WIDTH(0.9 - 0.15*i), TRANS_HEIGHT(-0.9), 0.0f), (DWORD)0xffffffff);
		set *= 10;
	}
}
void ImageManager::drawShield(D3DXVECTOR3 pos)
{
	pSprite->Draw(skill_image[4].image, &skill_image[4].rt, &skill_image[4].center, &pos, (D3DCOLOR)0xffffffff);
}
void ImageManager::drawDanger(float time,const float& frametime)
{
	static float timer = 0;
	timer += frametime;
	if (timer < time)
	{
		pSprite->Draw(danger.image, &danger.rt, &danger.center, &D3DXVECTOR3(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 0.0f), (D3DCOLOR)0xffffffff);
	}	
}