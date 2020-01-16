#pragma once
class Bullet_Player
{
private:
	float speed;
	int x, y;
	int objectcode;
	int imagecode;
public:
	Bullet_Player(int,int,int);
	void SetPos(int _x, int _y);
	void update();
	void setSpeed(float);
	void setImage(int, int);
	int getObj();
	int getImg();
	float getX();
	float getY();
};