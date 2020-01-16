#pragma once
class Enemy
{
protected:
	int hp;
	float speed;
	int objectcode;
	int imagecode;
	float x, y;
	float time;
	float timer;
	bool isRight;
	int score;
public:
	virtual void update(const float& frametime)=0;
	virtual void setLevel(int) = 0;
	virtual void setPos(float,float) = 0;
	virtual void setImage(int, int)=0;
	virtual int getHP() = 0;
	virtual int getObj() = 0;
	virtual void damaged(int) = 0;
	virtual int getImg() = 0;
	virtual int getScore( ) = 0;
	virtual float getX() = 0;
	virtual float getY() = 0;
};
//////////////////////////////////////////////////////
//Enemy1//
class Enemy1 :public Enemy
{
private:
public:
	Enemy1( int ,float,float,bool);
	virtual void update(const float& frametime);
	virtual void setPos(float, float);
	virtual void setLevel(int);
	virtual void setImage(int, int);
	virtual int getHP();
	virtual int getObj();
	virtual int getImg();
	virtual float getX();
	virtual int getScore( );
	virtual float getY();
	virtual void damaged(int);
};
Enemy1::Enemy1 (int _level,float _x,float _y,bool goRight)
{
	setLevel(_level);
	setPos(_x, _y);
	isRight = goRight;
	setImage(1, (_level-1)*3);
	score = 100 * _level;
}
void Enemy1::update(const float& frametime)
{
	if (isRight)
	{
		x += speed;
		y += speed;
	}
	else
	{
		x -= speed;
		y += speed;
	}
}
void Enemy1::setImage(int _obj,int _img)
{
	objectcode = _obj;
	imagecode = _img;
}
void Enemy1::setPos(float _x,float _y)
{
	x=_x;
	y = _y;
}
void Enemy1:: setLevel(int _level)
{
	hp = _level*5;
	speed = 2 + _level * 1.5;
}
int Enemy1::getScore( )
{
	return score;
}
int Enemy1::getHP()
{
	return hp;
}
int Enemy1::getObj()
{
	return objectcode;
}
int Enemy1::getImg()
{
	return imagecode;
}
float Enemy1::getX()
{
	return x;
}
float Enemy1::getY()
{
	return y;
}
void Enemy1::damaged(int _ap)
{
	hp -= _ap;
}
//////////////////////////////////////////////////////
//Enemy2//
class Enemy2 :public Enemy
{
private:
public:
	Enemy2(int);
	virtual void update(const float& frametime);
	virtual void setPos(float, float);
	virtual void setLevel(int);
	virtual void setImage(int, int);
	virtual int getHP();
	virtual int getObj();
	virtual int getImg();
	virtual int getScore( );
	virtual float getX();
	virtual float getY();
	virtual void damaged(int);
};
Enemy2::Enemy2(int _level)
{
	srand( GetTickCount( ) );
	setLevel(_level);
	setPos(rand()%SCREEN_WIDTH, TRANS_HEIGHT(-1.0f));
	setImage(1, 1+(_level-1) * 3);
	score = _level * 200;
}
void Enemy2::update(const float& frametime)
{
	y += speed;
}
void Enemy2::setImage(int _obj, int _img)
{
	objectcode = _obj;
	imagecode = _img;
}
void Enemy2::setPos(float _x, float _y)
{
	x = _x;
	y = _y;
}
void Enemy2::setLevel(int _level)
{
	hp = _level *5+ 10;
	speed = 1 + _level * 1.5;
}
int Enemy2::getHP()
{
	return hp;
}
int Enemy2::getScore( )
{
	return score;
}
int Enemy2::getObj()
{
	return objectcode;
}
int Enemy2::getImg()
{
	return imagecode;
}
float Enemy2::getX()
{
	return x;
}
float Enemy2::getY()
{
	return y;
}
void Enemy2::damaged(int _ap)
{
	hp -= _ap;
}

//////////////////////////////////////////////////////
//Enemy3//
class Enemy3 :public Enemy
{
private:
	CPlayer * p_player;
	float tox;
public:
	Enemy3( int ,CPlayer* );
	virtual void update( const float& frametime );
	void setAim( int );
	virtual void setPos( float, float );
	virtual void setLevel( int );
	virtual void setImage( int, int );
	virtual int getHP( );
	virtual int getObj( );
	virtual int getImg( );
	virtual float getX( );
	virtual float getY( );
	virtual int getScore( );
	virtual void damaged( int );
};
Enemy3::Enemy3( int _level,CPlayer* _player)
{
	p_player = _player;
	srand( GetTickCount( ) );
	setPos( rand( ) % SCREEN_WIDTH, TRANS_HEIGHT( -1.0f ) );
	isRight = true;

	setLevel( _level );
	setImage( 1, 2 + (_level - 1) * 3 );
	time = 0.0f;
	score = _level * 300;
}
void Enemy3::setAim( int _tox )
{
	tox = _tox;
	if (x < tox)
	{
		isRight = true;
	}
	else
	{
		isRight = false;
	}
}
int Enemy3::getScore( )
{
	return score;
}
void Enemy3::update( const float& frametime )
{
	time += frametime;
	if (y < TRANS_HEIGHT(-0.8f))
	{
		y += speed;
	}
	else if (time<2)
	{
		setAim( p_player->getX( ) );
		if (isRight)
		{
			if (x < tox)
			{
				x += speed;
			}
		}
		else
		{
			if (x > tox)
			{
				x -= speed;
			}
		}
	}
	else
	{
		y += speed;
	}
}
void Enemy3::setImage( int _obj, int _img )
{
	objectcode = _obj;
	imagecode = _img;
}
void Enemy3::setPos( float _x, float _y )
{
	x = _x;
	y = _y;
}
void Enemy3::setLevel( int _level )
{
	hp = _level * 5+5;
	speed = 2 + _level * 1.5;
}
int Enemy3::getHP( )
{
	return hp;
}
int Enemy3::getObj( )
{
	return objectcode;
}
int Enemy3::getImg( )
{
	return imagecode;
}
float Enemy3::getX( )
{
	return x;
}
float Enemy3::getY( )
{
	return y;
}
void Enemy3::damaged( int _ap )
{
	hp -= _ap;
}
