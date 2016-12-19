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
	//记录成绩
	int record(int score);
	//记录金币
	void gold_record(int gold);
	//记录钻石
	void diamond_record(int diamond);
	//显示最高分
	void showTopScore();
	//更新得分
	void updateScore();
	//显示游戏分值
	void showScore();
	//显示金币数量
	void showGold();
	//更新金币数量
	void updateGold();
	//显示钻石数量
	void showDiamond();
	//更新钻石数量
	void updateDiamond();
	//结束游戏
	void GameOver();
	void GameOver_Scene_Change(float dt);
	//移除战机
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
	//检测毁灭
	void updateDestroy(float dt);
	void updateTime(float dt);
	void updateBonus(float dt);
	//声音按钮回调
	void menuVoiceCallback( Ref* pSender );
	void win();

	//炸弹
	void onMouseDown(Event * e);

	//移除所有敌机
	void removeAllEnemy();
};

#endif