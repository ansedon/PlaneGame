#ifndef __ENEMY_5__
#define __ENEMY_5__
#include "Enemy.h"
class Enemy_5 : public Enemy
{
public:
	virtual bool init();
	CREATE_FUNC(Enemy_5);
	void update(float dt);
};
#endif