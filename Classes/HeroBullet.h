#ifndef __HERO_BULLET__
#define __HERO_BULLET__

#include "Bullet.h"

class HeroBullet : public Bullet
{
public:
	virtual bool init();
	CREATE_FUNC(HeroBullet);
};

#endif