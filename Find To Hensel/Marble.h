#pragma once

class Marble
{
private:
	float x, y;
	int imagecode, objectcode;
	float speed;
	float time;
public:
	Marble() = default;
	Marble(float, float, int);
	void update(const float&);
	void setPos(float, float);
	void setImg(int, int);
	float getX();
	float getY();
	int getImg();
	int getObj();
};
