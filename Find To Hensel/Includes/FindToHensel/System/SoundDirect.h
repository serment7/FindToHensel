#pragma once

#include <Windows.h>
#include <vector>
#include <mmsystem.h>
#include <dsound.h>
#include <mmreg.h>
#pragma comment(lib,"dsound.lib")
#pragma comment(lib,"winmm.lib")

class CDirectSound
{
public:
	CDirectSound(void);
	~CDirectSound(void);
public:

	HRESULT Initialize();
	void Release();
	void Release(int index);

	HRESULT Load_WaveFile(LPSTR filePath); // wav������ �ҷ��´�.
	void Set_Volume(LONG lVolume = 100); // �������� �⺻�� 100
	void Set_PlusVolume(LONG lVolume); // �������� �⺻�� 100
	void Original_Set_Volume(LONG lVolume = -10000);
	void Play_Sound(); // ���
	void Play_Sound(int fileindex, bool bloop = false); // ���������� �����ϰ� �ִ� ���Ϳ��� fileindex�� ���� ��ġ�� �ִ� ������ ���, �ݺ���� �Ұ�����
	void Stop_Sound(); // ����
	void Stop_Sound(int fileindex); // ���������� �����ϰ� �ִ� ���Ϳ��� fileindex�� ���� ��ġ�� �ִ� ������ ����
	inline int GetVolume() { return m_Volume; }

private:
	int m_Volume;
	LPDIRECTSOUND							m_lpDirectSound; // DirectSound ��ü
	std::vector< LPDIRECTSOUNDBUFFER >		m_SoundRepository; // ���������� �����ϴ� ����
};
