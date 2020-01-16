#pragma once

#define SAFE_DELETE( x ) {\
if (x != 0) {\
	delete (x); \
	(x) = nullptr; \
}\
}

#define SAFE_RELEASE( x ) {\
if (x != 0) {\
	(x)->Release(); \
	(x) = nullptr; \
}\
}
#define SAFE_DELETE_ARRAY(ptr) {if(ptr){delete[] ptr;}}
#define MAGENTA D3DCOLOR_XRGB(255,0,255)
static const char g_game_title[] = "Find to Hensel";


#define SCREEN_HEIGHT 1024
#define SCREEN_WIDTH 768
//#define SCREEN_HEIGHT GetSystemMetrics(SM_CYSCREEN)
//#define SCREEN_WIDTH GetSystemMetrics(SM_CXSCREEN)
#define TRANS_WIDTH(x) ((x+1)*SCREEN_WIDTH/2)
#define TRANS_HEIGHT(y) ((y+1)*SCREEN_HEIGHT/2)
static HWND g_hWnd;
static bool g_windowed = true;