#include"SoundDirect.h"
#include"Input.h"
#include"Player.h"
#include"Bullet_Player.h"
#include<vector>
#include"Boss.h"
#include"Enemy.h"
#include"Skill.h"
class Scene
{
protected:
	
	ImageManager* imageManager;
	CDirectInput * directInput;
public:
	virtual void start() = 0;
	virtual Scene* update(const float&) = 0;
	virtual void stop() = 0;
};
class Start :public Scene
{
private:
	int gameStart;
	int gameEnd;
	int alphaControl;
	float logoTime;
	bool isStart;
	friend class Battle;
public:
	virtual void start();
	Scene* update(const float&);
	virtual void stop();
	virtual void messageHandler();
};
class Battle :public Scene
{
private:
	CPlayer * player;
	std::vector<Bullet_Player *> bullet_player;
	std::vector<Enemy*> enemy_list;
	std::vector<CSkill*> skill_list;
	std::vector<Marble*> marble_list;
	float animation;
	float bullet_timer;
	int bullet;
	float boss_timer;
	float game_timer;
	float enemy_timer;
	DWORD alpha;
	bool player_powerup;
	bool isBack;
	int level;
	bool clear;
	int score;
	
	bool player_hitted;
	int skillcount;
	float skill_timer;
	bool active_shield;
	float shield_timer;
	bool getSkill;
public:
	virtual void start();
	virtual Scene* update(const float& frametime);
	virtual void stop();
	virtual void messageHandler();
	void collision();
	int counter;
};
void Start::start()
{
	imageManager = new ImageManager;
	directInput = new CDirectInput;
	logoTime = 2;
	gameStart = 1;
	gameEnd = 0;
	imageManager->createDevice(g_hWnd, SCREEN_WIDTH, SCREEN_HEIGHT, g_windowed);
	imageManager->loadStart();
	directInput->Initialize(g_hWnd);
	isStart = false;
	imageManager->setFade(0);

}
Scene* Start::update(const float& frametime)
{
	directInput->Update();

	if (isStart)
	{
		this->stop();
		return new Battle;
	}
	if (logoTime > 0)
	{

		imageManager->beginScene();
		imageManager->drawLogo();
		imageManager->endScene();
		logoTime -= frametime;
	}
	else
	{
		messageHandler();
		imageManager->beginScene();
		imageManager->drawStart(gameStart, gameEnd);
		imageManager->endScene();
	}
	return nullptr;
}
void Start::stop()
{
	SAFE_DELETE(directInput);
	SAFE_DELETE(imageManager);
}
void Start::messageHandler()
{
	if (directInput->GetKeyboardState(DOWN, DIK_DOWNARROW))
	{
		gameStart = 0;
		gameEnd = 1;
	}
	if (directInput->GetKeyboardState(DOWN, DIK_UPARROW))
	{
		gameStart = 1;
		gameEnd = 0;
	}
	if (directInput->GetKeyboardState(DOWN, DIK_RETURN))
	{
		if (gameStart == 1)
		{
			isStart = true;
		}
		if (gameEnd == 1)
			PostQuitMessage(0);
	}

}

void Battle::start()
{
	imageManager = new ImageManager;
	directInput = new CDirectInput;
	player = new CPlayer;
	directInput->Initialize(g_hWnd);
	player->SetPos(TRANS_WIDTH(0), TRANS_HEIGHT(0.7));
	player->setSpeed(10.0f);
	player->setImage(0, 0);
	player->setHP(3);
	player->setAP(5);
	imageManager->createDevice(g_hWnd, SCREEN_WIDTH, SCREEN_HEIGHT, g_windowed);
	imageManager->loadPath();
	imageManager->loadImages();
	animation = 0.0f;
	skillcount = 0;
	clear = false;
	getSkill = false;
	active_shield = false;
	shield_timer = 0.0f;
	bullet = 2;
	alpha = 0xffffffff;
	isBack = false;
	level = 1;
	game_timer = 0;
	bullet_timer = 0;
	animation = 0;

	enemy_timer = 0;
	counter = 0;
	score = 0;
	player_hitted = false;
	player_powerup = false;
}
Scene* Battle::update(const float& frametime)
{
	if (isBack || player->getHP() < 1)
	{
		this->stop();
		return new Start;
	}
	animation += frametime;
	bullet_timer += frametime;
	game_timer += frametime;
	enemy_timer += frametime;
	//enemy update
	if (game_timer>66&&enemy_list.size()<1)
	{
		clear = true;
	}
	else if (game_timer > 66)
	{
		if (counter<77)
		{
			if (enemy_timer > 0.4)
			{
				enemy_list.push_back(new Enemy1(level, TRANS_WIDTH(-1.0), TRANS_HEIGHT(-1.0), true));
				enemy_list.push_back(new Enemy1(level, TRANS_WIDTH(1.0), TRANS_HEIGHT(-1.0), false));
				enemy_list.push_back(new Enemy2(level));
				enemy_list.push_back(new Enemy2(level));
				enemy_list.push_back(new Enemy2(level));
				enemy_list.push_back(new Enemy3(level, player));
				enemy_list.push_back(new Enemy3(level, player));
				enemy_timer = 0;
				++counter;
			}
		}
	}
	else if (game_timer > 63)
	{
		if (counter<75)
		{
			if (enemy_timer > 0.4)
			{
				enemy_list.push_back(new Enemy1(level, TRANS_WIDTH(-1.0), TRANS_HEIGHT(-1.0), true));
				enemy_list.push_back(new Enemy1(level, TRANS_WIDTH(1.0), TRANS_HEIGHT(-1.0), false));
				enemy_list.push_back(new Enemy2(level));
				enemy_list.push_back(new Enemy2(level));
				enemy_list.push_back(new Enemy2(level));
				enemy_list.push_back(new Enemy3(level, player));
				enemy_list.push_back(new Enemy3(level, player));
				enemy_timer = 0;
				++counter;
			}
		}
	}
	else if (game_timer > 60)
	{
		if (counter<70)
		{
			if (enemy_timer > 0.4)
			{
				enemy_list.push_back(new Enemy1(level, TRANS_WIDTH(-1.0), TRANS_HEIGHT(-1.0), true));
				enemy_list.push_back(new Enemy1(level, TRANS_WIDTH(1.0), TRANS_HEIGHT(-1.0), false));
				enemy_list.push_back(new Enemy2(level));
				enemy_list.push_back(new Enemy2(level));
				enemy_list.push_back(new Enemy3(level, player));
				enemy_list.push_back(new Enemy3(level, player));
				enemy_timer = 0;
				++counter;
			}
		}
	}
	else if (game_timer > 58)
	{
		if (counter<65)
		{
			if (enemy_timer > 0.4)
			{
				enemy_list.push_back(new Enemy1(level, TRANS_WIDTH(-1.0), TRANS_HEIGHT(-1.0), true));
				enemy_list.push_back(new Enemy1(level, TRANS_WIDTH(1.0), TRANS_HEIGHT(-1.0), false));
				enemy_list.push_back(new Enemy2(level));
				enemy_list.push_back(new Enemy3(level, player));
				enemy_timer = 0;
				++counter;
			}
		}
	}
	else if (game_timer > 55)
	{
		level = 3;
		if (counter<60)
		{
			if (enemy_timer > 0.4)
			{
				enemy_list.push_back(new Enemy1(level, TRANS_WIDTH(-1.0), TRANS_HEIGHT(-1.0), true));
				enemy_list.push_back(new Enemy1(level, TRANS_WIDTH(1.0), TRANS_HEIGHT(-1.0), false));
				enemy_timer = 0;
				++counter;
			}
		}
	}
	
	else if (game_timer > 50)
	{
		if (counter<55)
		{
			if (enemy_timer > 0.4)
			{
				enemy_list.push_back(new Enemy2(level));
				enemy_list.push_back(new Enemy2(level));
				enemy_list.push_back(new Enemy3(level, player));
				enemy_list.push_back(new Enemy3(level, player));
				enemy_timer = 0;
				++counter;
			}
		}
	}
	else if (game_timer > 45)
	{
		if (counter<50)
		{
			if (enemy_timer > 0.4)
			{
				enemy_list.push_back(new Enemy1(level, TRANS_WIDTH(-1.0), TRANS_HEIGHT(-1.0), true));
				enemy_list.push_back(new Enemy1(level, TRANS_WIDTH(1.0), TRANS_HEIGHT(-1.0), false));
				enemy_list.push_back(new Enemy3(level, player));
				enemy_list.push_back(new Enemy3(level, player));
				enemy_timer = 0;
				++counter;
			}
		}
	}
	else if (game_timer > 40)
	{
		if (counter<45)
		{
			if (enemy_timer > 0.4)
			{
				enemy_list.push_back(new Enemy2(level));
				enemy_list.push_back(new Enemy3(level, player));
				enemy_list.push_back(new Enemy3(level, player));
				enemy_timer = 0;
				++counter;
			}
		}
	}
	else if (game_timer > 35)
	{
		if (counter<40)
		{
			if (enemy_timer > 0.4)
			{
				enemy_list.push_back(new Enemy1(level, TRANS_WIDTH(-1.0), TRANS_HEIGHT(-1.0), true));
				enemy_list.push_back(new Enemy1(level, TRANS_WIDTH(1.0), TRANS_HEIGHT(-1.0), false));
				enemy_list.push_back(new Enemy2(level));
				enemy_list.push_back(new Enemy3(level, player));
				enemy_timer = 0;
				++counter;
			}
		}
	}
	else if (game_timer > 30)
	{
		level = 2;
		if (counter<35)
		{
			if (enemy_timer > 0.4)
			{
				enemy_list.push_back(new Enemy1(level, TRANS_WIDTH(-1.0), TRANS_HEIGHT(-1.0), true));
				enemy_list.push_back(new Enemy1(level, TRANS_WIDTH(1.0), TRANS_HEIGHT(-1.0), false));
				enemy_list.push_back(new Enemy3(level, player));
				enemy_timer = 0;
				++counter;
			}
		}
	}
	else if (game_timer > 25)
	{
		if (counter<30)
		{
			if (enemy_timer > 0.4)
			{
				enemy_list.push_back(new Enemy1(level, TRANS_WIDTH(-1.0), TRANS_HEIGHT(-1.0), true));
				enemy_list.push_back(new Enemy1(level, TRANS_WIDTH(1.0), TRANS_HEIGHT(-1.0), false));
				enemy_list.push_back(new Enemy3(level, player));
				enemy_timer = 0;
				++counter;
			}
		}

	}
	else if (game_timer > 20)
	{
		if (counter<25)
		{
			if (enemy_timer > 0.4)
			{
				enemy_list.push_back(new Enemy3(level, player));
				enemy_list.push_back(new Enemy3(level, player));
				enemy_timer = 0;
				++counter;
			}
		}
	}
	else if (game_timer > 15)
	{
		if (counter<20)
		{
			if (enemy_timer > 0.4)
			{
				enemy_list.push_back( new Enemy2( level) );
				enemy_list.push_back( new Enemy3( level ,player) );
				enemy_timer = 0;
				++counter;
			}
		}
	}
	else if (game_timer > 10)
	{
		if (counter<15)
		{
			if (enemy_timer > 0.4)
			{
				enemy_list.push_back(new Enemy2(level));
				enemy_list.push_back(new Enemy2(level));
				enemy_timer = 0;
				++counter;
			}
		}
	}
	else if (game_timer > 5)
	{
		if (counter<10)
		{
			if (enemy_timer > 0.4)
			{
				enemy_list.push_back( new Enemy1( level, TRANS_WIDTH( -1.0 ), TRANS_HEIGHT( -1.0 ), true ) );
				enemy_list.push_back( new Enemy1( level, TRANS_WIDTH( 1.0 ), TRANS_HEIGHT( -1.0 ), false ) );
				enemy_list.push_back(new Enemy2(level));
				enemy_timer = 0;
				++counter;
			}
		}
	}
	else if (game_timer > 1)
	{
		if (counter<5)
		{
			if (enemy_timer > 0.4)
			{
				enemy_list.push_back( new Enemy1( level, TRANS_WIDTH( -1.0 ), TRANS_HEIGHT( -1.0 ), true ) );
				enemy_list.push_back( new Enemy1( level, TRANS_WIDTH( 1.0 ), TRANS_HEIGHT( -1.0 ), false ) );
				enemy_timer = 0;
				++counter;
			}
		}
	}
	else
	{

	}
	if (skill_timer)
	{

	}
	if (shield_timer>0)
	{
		shield_timer -= frametime;
	}
	else
	{
		active_shield = false;
	}
	if (animation > 0.2f)
	{
		player->update(animation);
		animation = 0.0f;
	}
	if (bullet_timer > 0.25f)
	{
		if (player_powerup)
		{
			bullet = 3;
		}
		else
		{
			bullet = 2;
		}
		bullet_player.push_back(new Bullet_Player(player->getX(), player->getY() - 150, bullet));

		bullet_timer = 0.0f;
	}
	for (int i = 0; i < bullet_player.size(); ++i)
	{
		bullet_player[i]->update();
	}
	for (int i = 0; i < enemy_list.size(); ++i)
	{
		enemy_list[i]->update(frametime);
	}
	for (int i = 0; i < skill_list.size(); ++i)
	{
		skill_list[i]->update(frametime,player->getX(),player->getY());
	}
	for (int i = 0; i <marble_list.size(); ++i)
	{
		marble_list[i]->update(frametime);
	}
	collision();
	directInput->Update();
	messageHandler();
	imageManager->beginScene();
	imageManager->drawMap();
	for (int i = 0; i < bullet_player.size(); ++i)
	{
		imageManager->draw(bullet_player[i]->getObj(), bullet_player[i]->getImg(), D3DXVECTOR3(bullet_player[i]->getX(), bullet_player[i]->getY(), 0.0f));
	}
	for (int i = 0; i < skill_list.size(); ++i)
	{
		imageManager->draw(skill_list[i]->getObj(), skill_list[i]->getImg(), D3DXVECTOR3(skill_list[i]->getX(), skill_list[i]->getY(), 0.0f));
	}
	
	for (int i = 0; i < marble_list.size(); ++i)
	{
		imageManager->draw(marble_list[i]->getObj(), marble_list[i]->getImg(), D3DXVECTOR3(marble_list[i]->getX(), marble_list[i]->getY(), 0.0f));
	}
	imageManager->draw(player->getObj(), player->getImg(), D3DXVECTOR3(player->getX(), player->getY(), 0.0f));
	if (active_shield)
	{
		imageManager->drawShield(D3DXVECTOR3(player->getX(), player->getY(), 0.0f));
	}
	
	for (int i = 0; i < enemy_list.size(); ++i)
	{
		imageManager->draw(enemy_list[i]->getObj(), enemy_list[i]->getImg(), D3DXVECTOR3(enemy_list[i]->getX(), enemy_list[i]->getY(), 0.0f));
	}
	
	imageManager->drawHeart(player->getHP());
	imageManager->drawScore(score);
	if (clear)
	imageManager->drawClear();
	imageManager->endScene();
	return nullptr;
}
void Battle::stop()
{
	bullet_player.clear();
	enemy_list.clear();
	skill_list.clear();
	marble_list.clear();
	SAFE_DELETE(directInput);
	SAFE_DELETE(player);
	SAFE_DELETE(imageManager);
}
void Battle::messageHandler()
{
	if (directInput->GetKeyboardState(PRESS, DIK_LEFTARROW))
		player->moveLeft();
	if (directInput->GetKeyboardState(PRESS, DIK_RIGHTARROW))
		player->moveRight();
	if (directInput->GetKeyboardState(DOWN, DIK_0))
	{
		player_powerup = !(player_powerup);
		if (player_powerup)
		{
			player->setAP(15);
		}
		else
		{
			player->setAP(5);
		}
	}

	if (directInput->GetKeyboardState(DOWN, DIK_BACK))
	{
		isBack = true;
	}
}
void Battle::collision()
{
	std::vector<Bullet_Player*>::iterator iter = bullet_player.begin();
	std::vector<Enemy*>::iterator iter2 = enemy_list.begin();
	std::vector<CSkill*>::iterator iter3 = skill_list.begin();
	std::vector<Marble*>::iterator iter4 = marble_list.begin();
	for (int j = 0; j < enemy_list.size(); ++j)
	{
		if ( hypot( enemy_list[ j ]->getX( ) - player->getX( ), enemy_list[ j ]->getY( ) - player->getY( ) ) <100)
		{
			if (!active_shield)
			{
				if (player_powerup)
				{
					player_powerup = false;
					player->setAP(5);
				}
				player->setHit(true);
				player->damaged();
			}
			enemy_list.erase(iter2 + j);
			return;
		}
	}
	for (int j = 0; j < marble_list.size(); ++j)
	{
		if (hypot(marble_list[j]->getX() - player->getX(), marble_list[j]->getY() - player->getY()) < 70 && (marble_list[j]->getImg()<4||marble_list[j]->getImg()==5))
		{
			int index = 0;
			float distance = 0;
			switch (marble_list[j]->getImg())
			{
			case 0:
				for (int i = 0; i < 3; ++i)
				{
					skill_list.push_back(new Skill1(player->getX(), player->getY()-100, -10, 6+i, i*0.7));
				}
				break;
			case 1:
				score += 200;
				break;
			case 2:
				score += 300;
				break;
			case 3:
				active_shield = true;
				shield_timer = 3.0f;
				break;
			case 5:
				player_powerup = true;
				player->setAP(15);
				break;
			}
			marble_list.erase(iter4 + j);
			return;
		}
	}
	for (int i = 0; i < bullet_player.size(); ++i)
	{
		for (int j = 0; j < enemy_list.size(); ++j)
		{
			if (hypot(enemy_list[j]->getX() - bullet_player[i]->getX(), enemy_list[j]->getY() - bullet_player[i]->getY()) <((player_powerup)?100:70))
			{
				enemy_list[j]->damaged(player->getAP());
				if (enemy_list[j]->getHP() < 1)
				{
					score+=enemy_list[ j ]->getScore( );
					srand(GetTickCount());
					if ( 30> (rand()%100))
					{
						int ima = rand() % 5;
						if (ima == 4)
							ima = 5;
						marble_list.push_back(new Marble(enemy_list[j]->getX(),enemy_list[j]->getY(),ima));
					}
					enemy_list.erase(iter2 + j);
				}
				bullet_player.erase(iter + i);
				return;
			}
			else if ((bullet_player[i]->getY() < 0))
			{
				bullet_player.erase(iter + i);
				return;
			}
		}
	}
	for (int j = 0; j < skill_list.size(); ++j)
	{
		for (int i = 0; i < enemy_list.size(); ++i){
			if (hypot(skill_list[j]->getX() - enemy_list[i]->getX(), skill_list[j]->getY() - enemy_list[i]->getY()) < (skill_list[j]->getImg()==10)?300:100)
			{
				switch (skill_list[j]->getImg())
				{
				case 6:
				case 7:
				case 8:
					enemy_list[i]->damaged(20);
					break;
				case 9:
					enemy_list[i]->damaged(15);
					break;
				case 10:
					enemy_list[i]->damaged(30);
					break;
				}
				if (enemy_list[i]->getHP()<1)
					enemy_list.erase(iter2 + i);
				skill_list.erase(iter3 + i);
				return;
			}
		}
	}


}