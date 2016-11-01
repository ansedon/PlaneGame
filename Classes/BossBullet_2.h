#ifndef __BOSSBULLET_2__
#define __BOSSBULLET_2__

#include "Bullet.h"

class BossBullet_2 : public Bullet
{
public:
	static BossBullet_2* create(Vec2  x,Vec2  y);
	bool init(Vec2  x, Vec2  y);
};

#endif