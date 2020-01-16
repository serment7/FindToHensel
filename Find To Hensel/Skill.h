////////////////////////////////
#pragma once
//Skill Base/////////////////////
class Marble
{
private:
	float x, y;
	int imagecode, objectcode;
	float speed;
	float time;
public:
	Marble(float, float,int);
	void update(const float&);
	void setPos(float, float);
	void setImg(int, int);
	float getX();
	float getY();
	int getImg();
	int getObj();
};
Marble::Marble(float _x, float _y, int _img)
{
	x = _x;
	y = _y;
	speed = 3.0f;
	setImg(4, _img);
}
void Marble::update(const float& frametime)
{
	y += speed;
}
void Marble::setPos(float _x, float _y)
{
	x = _x;
	y = _y;
}
void  Marble::setImg(int _obj, int _img)
{
	objectcode = _obj;
	imagecode = _img;
}
float  Marble::getX(){ return x; }
float  Marble::getY(){ return y; }
int Marble::getObj() { return objectcode; }
int Marble::getImg() { return imagecode; }
class CSkill
{
protected:
	float x, y;
	int imagecode, objectcode;
	float speed;
	float time;
public:
	virtual void update(const float&,float,float )=0;
	virtual void setPos(float , float )=0;
	virtual void setImg(int, int)=0;
	virtual float getX()=0;
	virtual float getY()=0;
	virtual int getImg()=0;
	virtual int getObj()=0;
};
////////////////////////////////
//Skill1/////////////////////////
class Skill1:public CSkill
{
public:
	Skill1(float,float,float,int,float);
	void update(const float&,float,float);
	void setPos(float, float);
	void setImg(int, int);
	float getX();
	float getY();
	int getDistance();
	int getImg();
	int getObj();
	float time;
	float timer;
};
Skill1::Skill1(float _x,float _y,float _speed,int _img,float _time)
{
	time = _time;
	x = _x;
	y = _y;
	speed = _speed;
	setImg(4, _img);
}
void Skill1::update(const float& frametime,float _x,float _y)
{
	
	if (time > 0){
		x = _x;
		time -= frametime;
	}
	else
	{
		y += speed;
	}
}
void Skill1::setPos(float _x, float _y)
{
	x = _x;
	y = _y;
}
void  Skill1::setImg(int _obj, int _img)
{
	objectcode = _obj;
	imagecode = _img;
}
float  Skill1::getX(){ return x; }
float  Skill1::getY(){ return y; }
int Skill1::getObj() { return objectcode; }
int Skill1::getImg() { return imagecode; }
////////////////////////////////
//Skill2/////////////////////////
class Skill2 :public CSkill
{
public:
	Skill2(float _x, float _y, float _speed);
	void update(const float& frametime, float _x, float _y);
	void setPos(float, float);
	void setImg(int, int);
	float getX();
	float getY();
	int getDistance();
	int getImg();
	int getObj();
};
Skill2::Skill2(float _x,float _y,float _speed)
{
	setPos(_x,_y);
	speed = _speed;
	setImg(4,10);
}
void Skill2::update(const float& frametime, float _x, float _y)
{
	y += speed;
}
void Skill2::setPos(float _x, float _y)
{
	x = _x;
	y = _y;
}
void  Skill2::setImg(int _obj, int _img)
{
	objectcode = _obj;
	imagecode = _img;
}
float  Skill2::getX(){ return x; }
float  Skill2::getY(){ return y; }
int Skill2::getObj() { return objectcode; }
int Skill2::getImg() { return imagecode; }
////////////////////////////////
//Skill3/////////////////////////
class Skill3 :public CSkill
{
private:
	int tox, toy;
	Enemy * enemy;
public:
	Skill3(float _x, float _y, float _speed, float _tox, float _toy);
	void update(const float& frametime, float _x, float _y);
	void setPos(float, float);
	void setImg(int, int);
	float getX();
	float getY();
	int getDistance();
	int getImg();
	int getObj();
};
Skill3::Skill3(float _x,float _y,float _speed,float _tox,float _toy)
{
	setPos(_x, _y);
	speed = _speed;
	tox = _tox;
	toy = _toy;
	setImg(4, 9);
}
void Skill3::update(const float& frametime, float _x, float _y)
{

	if (fabs(x - tox)<2)
	{
		y += speed;
	}
	else if (x - tox > 0)
	{
		x -= 2;
	}
	else
	{
		x += 2;
	}
}
void Skill3::setPos(float _x, float _y)
{
	x = _x;
	y = _y;
}
void  Skill3::setImg(int _obj, int _img)
{
	objectcode = _obj;
	imagecode = _img;
}
float  Skill3::getX(){ return x; }
float  Skill3::getY(){ return y; }
int Skill3::getObj() { return objectcode; }
int Skill3::getImg() { return imagecode; }