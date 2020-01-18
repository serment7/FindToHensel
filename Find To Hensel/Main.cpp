#include"Game.h"
#include "Extra.h"

LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam);

Game * game;
HWND g_hWnd;

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	MSG msg;
	WNDCLASSEX wcx;
	ZeroMemory(&wcx, sizeof(wcx));
	wcx.cbClsExtra = 0;
	wcx.cbSize = sizeof(wcx);
	wcx.cbWndExtra = 0;
	wcx.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wcx.hCursor = LoadCursor(NULL, IDC_ARROW);
	wcx.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wcx.hIconSm = NULL;
	wcx.hInstance = hInstance;
	wcx.lpfnWndProc = WndProc;
	wcx.lpszClassName = g_game_title;
	wcx.lpszMenuName = NULL;
	wcx.style = CS_VREDRAW | CS_HREDRAW;
	RegisterClassEx(&wcx);
	
	g_hWnd = CreateWindow(g_game_title, g_game_title, (g_windowed)?WS_OVERLAPPEDWINDOW:WS_EX_TOPMOST | WS_VISIBLE | WS_POPUP, GetSystemMetrics(SM_CXSCREEN) / 2 - 384, 0, SCREEN_WIDTH, SCREEN_HEIGHT, (HWND)NULL, (HMENU)NULL, hInstance, (LPVOID)NULL);
	game = new Game;
	game->start();

	ShowWindow(g_hWnd, nCmdShow);
	UpdateWindow(g_hWnd);

	bool run = true;
	while (run)
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			//Logic
			if (msg.message == WM_QUIT)
				run = false;

			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		else
		{
			//rendering
			game->update();
		}
	}
	SAFE_DELETE(game);
	return msg.wParam;
}
LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	switch (iMessage)
	{
	case WM_KEYDOWN:
		switch (wParam)
		{
		case VK_ESCAPE:
			PostQuitMessage(0);
			break;
		}
		break;

	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	}
	
	return DefWindowProc(hWnd, iMessage, wParam, lParam);
}