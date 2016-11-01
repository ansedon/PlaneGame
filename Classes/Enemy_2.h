#ifndef __ENEMY_2__
#define __ENEMY_2__

#include "Enemy.h"

class Enemy_2 : public Enemy
{
public:
	virtual bool init();
	CREATE_FUNC(Enemy_2);
	void update(float dt);
};
#endif
