#ifndef __ENEMY_1__
#define __ENEMY_1__
#include "cocos2d.h"
#include "Enemy.h"

class Enemy_1 : public Enemy
{
public:
	virtual bool init();
	CREATE_FUNC(Enemy_1);
	void update(int num);
};

#endif