#pragma once
class CPlayer
{
public:
	void moveLeft();
	void moveRight();
	void SetPos(int, int);
	void update(const float&);
	void setSpeed(float);
	void setHP(int);
	void setImage(int, int);
	int getObj();
	int getImg();
	float getX();
	float getY();
	void damaged();
	int getHP();
	void setAP(int);
	int getAP();
	void CPlayer::setHit(bool);
	
private:
	bool hitted;
	float speed ;
	int hp;
	int x, y;
	int objectcode;
	int imagecode;
	int ap;
	float time;
};