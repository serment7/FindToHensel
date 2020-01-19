#pragma once

#define MarbleTypeNum 5

enum class EMarbleType
{
	None = 0,
	PowerUp = 5,
	ScoreBonus1 = 1,
	ScoreBonus2 = 2,
	Shield = 3,
	Max
};

class Marble
{
private:
	float x, y;
	int imagecode, objectcode;
	float speed;
	float time;
	EMarbleType MarbleType;
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
	const EMarbleType& getMarbleType();
};
