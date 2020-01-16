#pragma once
#include <dinput.h>
#include"Keys.h"
#pragma comment( lib, "dxguid.lib" )
#pragma comment( lib, "dinput8.lib" )

enum KeyState
{
	DOWN, PRESS, UP
};

enum MouseType
{
	LBUTTON, RBUTTON, MBUTTON
};

class CDirectInput
{
public:
	CDirectInput();
	~CDirectInput();

public:
	HRESULT Initialize(HWND hWnd);

	void Update();

	bool GetKeyboardState(UINT keyState, UINT keyCode);
	bool GetMouseState(UINT keyState, UINT mouseCode);

	void CopyInputMemory();

private:
	LPDIRECTINPUT8 m_pDirectInput8 = nullptr;
	LPDIRECTINPUTDEVICE8 m_pKeyboard = nullptr;
	LPDIRECTINPUTDEVICE8 m_pMouse = nullptr;

	DIMOUSESTATE	m_CurMouseState;
	BYTE m_byCurrKeys[256];

	DIMOUSESTATE	m_PrevMouseState;
	BYTE m_byPrevKeys[256];
};