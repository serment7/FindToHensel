#pragma once
#pragma comment(lib,"d3d9.lib")
#pragma comment(lib,"d3dx9.lib")

#include<d3d9.h>
#include<d3dx9.h>

#include "FindToHensel\Extra.h"
#include "FindToHensel\Resources.h"

#define PLAYER_CODE 0
#define ENEMY_CODE 1
#define BOSS_CODE 2
#define BULLET_CODE 3
#define SKILL_CODE 4

struct IMAGE
{
	D3DXIMAGE_INFO image_info;
	LPDIRECT3DTEXTURE9 image;
	RECT rt;
	D3DXVECTOR3 center;
};

class ImageManager
{
private:
	HRESULT result = 0;
	LPDIRECT3D9 pDirect3D9 = nullptr;
	LPDIRECT3DDEVICE9 pDevice3D9 = nullptr;
	D3DPRESENT_PARAMETERS d3dpp;
	LPD3DXSPRITE pSprite = nullptr;
	HWND hWnd = nullptr;

	float fade = 0.f;
	int screen_width, screen_height = 0;
	bool windowed = true;
	IMAGE map1;
	RECT maprt;
	IMAGE title;
	IMAGE Logo;
	IMAGE player_image[4] = { IMAGE(), };;
	char* player_path[4] = { nullptr, };
	IMAGE enemy_image[9] = { IMAGE(), };
	char* enemy_path[9] = { nullptr, };
	IMAGE boss_image[6] = { IMAGE(), };
	char* boss_path[6] = {nullptr,};
	IMAGE bullet_image[4] = { IMAGE(), };
	char* bullet_path[4] = { nullptr, };
	IMAGE skill_image[10] = { IMAGE(), };
	char* skill_path[11] = { nullptr, };
	IMAGE heart_image;
	IMAGE gameStart[2] = { IMAGE(), };
	IMAGE gameEnd[2] = { IMAGE(), };
	D3DXMATRIX mat;
	IMAGE clear;
	IMAGE danger;
	IMAGE number[10] = { IMAGE(), };
	char * number_path[10] = { nullptr, };

public:
	ImageManager() = default;
	~ImageManager();
	void createDevice(const HWND& hWnd, const int& _width, const int& _height,bool _windowed);
	void initD3Dpp();
	void loadImages();
	void draw(int objectcode, int imagecode, D3DXVECTOR3 pos);
	void drawPlayer();
	void beginScene();
	void endScene();
	void releaseAll();
	void drawMap();
	void loadImage(const char*_path, IMAGE& image);
	void loadPath();
	void drawHeart(int HP);
	void loadStart();
	void drawStart(int,int);
	void drawLogo();
	void setFade(float);
	void drawClear();
	void drawScore(int);
	void drawShield(D3DXVECTOR3 pos);
	void drawDanger(float time, const float& frametime);
};
