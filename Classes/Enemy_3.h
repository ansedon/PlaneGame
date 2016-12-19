#ifndef __ENEMY_3__
#define __ENEMY_3__
#include "Enemy.h"
class Enemy_3: public Enemy
{
public:
	virtual bool init();
	CREATE_FUNC(Enemy_3);
	void update(int num);
};

#endif