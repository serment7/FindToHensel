////////////////////////////////
#pragma once
//Skill Base/////////////////////

#include <cmath>

class CSkill abstract
{
protected:
	float x, y;
	int imagecode, objectcode;
	float speed;
	float time;
	CSkill() = default;
public:
	virtual void update(const float&, float, float) = 0;
	void setPos(float, float);
	void setImg(int, int);
	const float& getX() const;
	const float& getY() const;
	const int& getImg() const;
	const int& getObj() const ;
};
////////////////////////////////
//Skill3/////////////////////////
