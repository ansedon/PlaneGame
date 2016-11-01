#ifndef __BOSS__
#define __BOSS__
#include "BossBullet.h"
#include "BossBullet_2.h"
#include "Enemy.h"
#include "cocos2d.h"
USING_NS_CC;

class Boss: public Enemy
{
private:
	PhysicsBody* body;
	static int flag;
public:
	int boss_time;
	virtual bool init();
	CREATE_FUNC(Boss);
	void action(float dt);
	void movein();
	void movedown();
	void moveleft();
	void moveright();
	void moveleftdown();
	void moverightdown();
	void updateTime(float dt);
};
#endif
