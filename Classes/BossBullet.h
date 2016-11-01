#ifndef __BOSSBULLET__
#define __BOSSBULLET__

#include "Bullet.h"

class BossBullet : public Bullet
{
public:
	static BossBullet* create(float x, float y);
	bool init(float x, float y);
};

#endif