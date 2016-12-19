#ifndef __ENEMY_4__
#define __ENEMY_4__
#include "Enemy.h"
class Enemy_4 : public Enemy
{
public:
	virtual bool init();
	CREATE_FUNC(Enemy_4);
	void updateFly(float dt);
	void update(int num);
};

#endif