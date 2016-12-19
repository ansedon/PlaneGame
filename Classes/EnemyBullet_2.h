#ifndef __ENEMY_BULLET_2__
#define __ENEMY_BULLET_2__

#include "Bullet.h"

class EnemyBullet_2 : public Bullet
{
public:
	public:
	virtual bool init();
	CREATE_FUNC(EnemyBullet_2);
	void update(int num);
};

#endif