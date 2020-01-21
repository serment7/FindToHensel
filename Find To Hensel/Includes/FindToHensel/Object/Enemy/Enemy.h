#pragma once

#include <d3dx9math.h>

class Enemy
{
private:
	int hp = 0;
	float speed = 0.f;
	int objectcode = 0;
	int imagecode = 0;
	D3DXVECTOR2 pos = D3DXVECTOR2(0.f,0.f);
	int score=0;

protected:
	float time = 0.f;
	float timer = 0.f;

public:
	Enemy() = default;
	~Enemy() = default;
	virtual void update(const float& frametime) = 0;
	virtual void setLevel(const int&) = 0;
	void move(const D3DXVECTOR2&);
	void move(const float&, const float&);
	void setPos(const float&, const float&);
	void setPos(const D3DXVECTOR2&);
	void setImage(const int&, const int&);
	void setHP(const int&);
	void setObj(const int&);
	void setScore(const int&);
	void setSpeed(const int&);

	const int& getHP() const;
	const int& getObj() const;
	virtual void damaged(int);
	const int& getImg() const;
	const int& getScore( ) const;
	const int& getSpeed() const;
	const float& getX() const;
	const float& getY() const;
	const D3DXVECTOR2& getPos() const;
};
