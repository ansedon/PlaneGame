#ifndef __ENEMY_BULLET__
#define __ENEMY_BULLET__

#include "Bullet.h"

class EnemyBullet : public Bullet
{
public:
	virtual bool init();
	CREATE_FUNC(EnemyBullet);
	void update(int num);
};

#endif