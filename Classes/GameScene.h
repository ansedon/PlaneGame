#ifndef __GAME_SCENE__
#define __GAME_SCENE__

#include "EnemyFactory.h"
#include "cocos2d.h"
#include "WelcomeScene.h"
#include "Bullet.h"
#include "Hero.h"
#include "Enemy.h"
#include "bonus.h"
#include "Gold.h"
#include "Boss.h"
#include "BossBullet.h"
#include "StateControl.h"
USING_NS_CC;

class GameScene : public Layer
{
private:
	ProgressTimer*hpBar;
	Sprite* hpBgSprite;
	Vec2 heropos;
	Size screenSize;
	Vector<Bullet*> buls;
	Vector<Enemy*> emys;
	Vector<bonus*> bons;
	//int bonus_flag; 
	int bonus_time;
	Label * score_label;
	Label * diamond_label;
	Label * gold_label;
	Label * bomb_label;
	int time;
	int enemy_flag;
	int bomb_num;
public:
	static Hero* hero;
	static Boss*boss;
	static int score;
	static int gold;
	static int diamond;
	static EnemyFactory* fac;
	StateControl* S;
	//��¼�ɼ�
	int record(int score);
	//��¼���
	void gold_record(int gold);
	//��¼��ʯ
	void diamond_record(int diamond);
	//��ʾ��߷�
	void showTopScore();
	//���µ÷�
	void updateScore();
	//��ʾ��Ϸ��ֵ
	void showScore();
	//��ʾ�������
	void showGold();
	//���½������
	void updateGold();
	//��ʾ��ʯ����
	void showDiamond();
	//������ʯ����
	void updateDiamond();
	//������Ϸ
	void GameOver();
	void GameOver_Scene_Change(float dt);
	//�Ƴ�ս��
	bool removeEnemy(Enemy* emy);
	static Scene* createScene();
	virtual bool init();
	CREATE_FUNC(GameScene);
	void menuPauseCallback(Ref* sender);
	void updateHeroBullet(float dt);
	void updateEnemyBullet(float dt);
	void updateBossBullet(float dt);
	void updateEnemy(float dt);
	bool contactBegin(PhysicsContact& contact);
	//������
	void updateDestroy(float dt);
	void updateTime(float dt);
	void updateBonus(float dt);
	//������ť�ص�
	void menuVoiceCallback( Ref* pSender );
	void win();

	//ը��
	void onMouseDown(Event * e);

	//�Ƴ����ел�
	void removeAllEnemy();
};

#endif