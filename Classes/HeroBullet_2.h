#ifndef __HERO_BULLET_2__
#define __HERO_BULLET_2__

#include "Bullet.h"
#include "HeroBullet_3.h"
#include "HeroBullet.h"
#include "StateControl.h"

class HeroBullet_2 : public Bullet
{
public:
	virtual bool init();
	CREATE_FUNC(HeroBullet_2);
	void last(StateControl*s);
	void next(StateControl*s);
};

#endif