#include"Input.h"
#include"Extra.h"
#include"Keys.h"

CDirectInput::CDirectInput()
{
	m_CurMouseState = DIMOUSESTATE();
	m_PrevMouseState = m_CurMouseState;

	ZeroMemory(m_byCurrKeys, sizeof(m_byCurrKeys));
	ZeroMemory(m_byPrevKeys, sizeof(m_byPrevKeys));
}

CDirectInput::~CDirectInput()
{
	if (m_pKeyboard)
	{
		m_pKeyboard->Unacquire();
		m_pKeyboard->Release();
		m_pKeyboard = nullptr;
	}

	if (m_pMouse)
	{
		m_pMouse->Unacquire();
		m_pMouse->Release();
		m_pMouse = nullptr;
	}

	SAFE_RELEASE(m_pDirectInput8);
}

HRESULT CDirectInput::Initialize(HWND hWnd)
{
	HRESULT hr;

	if (FAILED(hr = DirectInput8Create(GetModuleHandle(NULL),
		DIRECTINPUT_VERSION, IID_IDirectInput8, (void**)&m_pDirectInput8, NULL)))
		return hr;

	// Create Device
	if (FAILED(hr = m_pDirectInput8->CreateDevice(GUID_SysKeyboard, &m_pKeyboard, NULL)) ||
		FAILED(hr = m_pDirectInput8->CreateDevice(GUID_SysMouse, &m_pMouse, NULL)))
	{
	
		return hr;
	}

	if (FAILED(hr = m_pKeyboard->SetDataFormat(&c_dfDIKeyboard)) ||
		FAILED(hr = m_pMouse->SetDataFormat(&c_dfDIMouse)))
	{
		
		return hr;
	}

	if (FAILED(hr = m_pMouse->SetCooperativeLevel(hWnd, DISCL_NONEXCLUSIVE | DISCL_FOREGROUND)) ||
		FAILED(hr = m_pKeyboard->SetCooperativeLevel(hWnd, DISCL_NONEXCLUSIVE | DISCL_FOREGROUND)))
	{
		
		return hr;
	}

	return S_OK;
}

void CDirectInput::Update()
{
	HRESULT hr;
	if (m_pKeyboard == nullptr || m_pMouse == nullptr)
		return;

	CopyInputMemory();

	// Keyboard
	if (FAILED(m_pKeyboard->GetDeviceState(sizeof(m_byCurrKeys), static_cast<LPVOID>(m_byCurrKeys))))
	{
		hr = m_pKeyboard->Acquire();

		while (hr == DIERR_INPUTLOST)
			hr = m_pKeyboard->Acquire();
	}

	// Mouse
	if (FAILED(m_pMouse->GetDeviceState(sizeof(m_CurMouseState), static_cast<LPVOID>(&m_CurMouseState))))
	{
		hr = m_pMouse->Acquire();

		while (hr == DIERR_INPUTLOST)
			hr = m_pMouse->Acquire();

		if (FAILED(m_pMouse->GetDeviceState(sizeof(m_pMouse), (LPVOID)(&m_CurMouseState))))
			return;
	}
}

void CDirectInput::CopyInputMemory()
{
	memcpy(m_byPrevKeys, m_byCurrKeys, sizeof(m_byPrevKeys));
	m_PrevMouseState = m_CurMouseState;
}

bool CDirectInput::GetKeyboardState(UINT keyState, UINT keyCode)
{
	if (keyState == KeyState::DOWN)
	{
		if (!(m_byPrevKeys[keyCode] & 0x80) && m_byCurrKeys[keyCode] & 0x80)
			return true;
	}
	else if (keyState == KeyState::PRESS)
	{
		if (m_byPrevKeys[keyCode] & 0x80 && m_byCurrKeys[keyCode] & 0x80)
			return true;
	}
	else if (keyState == KeyState::UP)
	{
		if (m_byPrevKeys[keyCode] & 0x80 && !(m_byCurrKeys[keyCode] & 0x80))
			return true;
	}
	return false;
}

bool CDirectInput::GetMouseState(UINT keyState, UINT mouseCode)
{
	if (keyState == KeyState::DOWN)
	{
		if (!(m_PrevMouseState.rgbButtons[mouseCode] & 0x80) &&
			m_CurMouseState.rgbButtons[mouseCode] & 0x80)
			return true;
	}
	else if (keyState == KeyState::PRESS)
	{
		if (m_PrevMouseState.rgbButtons[mouseCode] & 0x80 &&
			m_CurMouseState.rgbButtons[mouseCode] & 0x80)
			return true;
	}
	else if (keyState == KeyState::UP)
	{
		if (m_PrevMouseState.rgbButtons[0] & 0x80 &&
			!(m_CurMouseState.rgbButtons[0] & 0x80))
			return true;
	}
	return false;
}