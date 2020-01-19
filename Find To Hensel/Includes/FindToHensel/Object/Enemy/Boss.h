class CBoss
{
protected:
	float x, y;
	int hp;
	float speed;
	int objectcode;
	int imagecode;
	float time;
	float timer;
	bool isRight;
	int score;
public:
	virtual void setPos(float, float) = 0;
	virtual void setHP(int) = 0;
	virtual void setImg(int, int) = 0;
	virtual void skill() = 0;
	virtual float getX() = 0;
	virtual float getY() = 0;
	virtual int getHP() = 0;
	virtual int getImg() = 0;
	virtual 	int getObj() = 0;
	virtual int getScore()=0;
};
class Boss1 :CBoss
{
public:
	void setPos(float, float);
	void setHP(int);
	void setImg(int, int);
	void skill();
	float getX();
	float getY();
	int getHP();
	int getImg();
	int getObj();
	int getScore();
};
void Boss1::skill()
{

}
void Boss1::setHP(int _hp)
{
	hp = hp;
}
void Boss1::setImg(int _obj,int _img)
{
	objectcode = _obj;
	imagecode = _img;
}
void Boss1::setPos(float _x, float _y)
{
	x = _x;
	y = _y;
}
int Boss1::getHP()
{
	return hp;
}
float Boss1::getX()
{
	return x;
}
float Boss1::getY()
{
	return y;
}
int Boss1::getImg()
{
	return imagecode;
}
int Boss1::getObj()
{
	return imagecode;
}
int Boss1::getScore()
{
	return score;
}

class Boss2 :CBoss
{
public:
	void setPos(float, float);
	void setHP(int);
	void setSpeed(int);
	void setImg(int, int);
	void skill();
	float getX();
	float getY();
	int getHP();
	int getImg();
	int getObj();
	int getScore();
	void update();
};
void Boss2::update()
{

}
void Boss2::skill()
{

}
void Boss2::setHP(int _hp)
{
	hp = _hp;
}
void Boss2::setImg(int _obj, int _img)
{
	objectcode = _obj;
	imagecode = _img;
}
void Boss2::setPos(float _x, float _y)
{
	x = _x;
	y = _y;
}
int Boss2::getHP()
{
	return hp;
}
float Boss2::getX()
{
	return x;
}
float Boss2::getY()
{
	return y;
}
int Boss2::getImg()
{
	return imagecode;
}
int Boss2::getObj()
{
	return imagecode;
}
int Boss2::getScore()
{
	return score;
}

class Boss3 :CBoss
{
public:
	void setPos(float, float);
	void setHP(int);
	void setSpeed(int);
	void setImg(int, int);
	void skill();
	float getX();
	float getY();
	int getHP();
	int getImg();
	int getObj();
	int getScore();
};
void Boss3::skill()
{

}
void Boss3::setHP(int _hp)
{
	hp = hp;
}
void Boss3::setImg(int _obj, int _img)
{
	objectcode = _obj;
	imagecode = _img;
}
void Boss3::setPos(float _x, float _y)
{
	x = _x;
	y = _y;
}
int Boss3::getHP()
{
	return hp;
}
float Boss3::getX()
{
	return x;
}
float Boss3::getY()
{
	return y;
}
int Boss3::getImg()
{
	return imagecode;
}
int Boss3::getObj()
{
	return imagecode;
}
int Boss3::getScore()
{
	return score;
}
