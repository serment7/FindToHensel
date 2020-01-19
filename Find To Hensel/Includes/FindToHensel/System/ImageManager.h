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

typedef struct _IMAGE
{
	D3DXIMAGE_INFO image_info;
	LPDIRECT3DTEXTURE9 image;
	RECT rt;
	D3DXVECTOR3 center;

}IMAGE;

class ImageManager
{
private:
	HRESULT result;
	LPDIRECT3D9 pDirect3D9;
	LPDIRECT3DDEVICE9 pDevice3D9;
	D3DPRESENT_PARAMETERS d3dpp;
	LPD3DXSPRITE pSprite;
	HWND hWnd;

	float fade;
	int screen_width, screen_height;
	bool windowed;
	IMAGE map1;
	RECT maprt;
	IMAGE title;
	IMAGE Logo;
	IMAGE player_image[4];
	char * player_path[4];
	IMAGE enemy_image[9];
	char * enemy_path[9];
	IMAGE boss_image[6];
	char * boss_path[6];
	IMAGE bullet_image[4];
	char * bullet_path[4];
	IMAGE skill_image[10];
	char * skill_path[10];
	IMAGE heart_image;
	IMAGE gameStart[2];
	IMAGE gameEnd[2];
	D3DXMATRIX mat;
	IMAGE clear;
	IMAGE danger;
	IMAGE number[10];
	char * number_path[10];

public:
	ImageManager();
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
