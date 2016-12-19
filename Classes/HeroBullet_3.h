#ifndef __HERO_BULLET_3__
#define __HERO_BULLET_3__

#include "Bullet.h"
#include "HeroBullet.h"
#include "HeroBullet_2.h"
#include "StateControl.h"

class HeroBullet_3 : public Bullet
{
public:
	virtual bool init();
	CREATE_FUNC(HeroBullet_3);
	void last(StateControl*s);
	void next(StateControl*s);
	void update(int num);
};

#endif