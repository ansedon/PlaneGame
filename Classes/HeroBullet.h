#ifndef __HERO_BULLET__
#define __HERO_BULLET__

#include "Bullet.h"
#include "HeroBullet_2.h"
#include "StateControl.h"

class HeroBullet : public Bullet
{
public:
	virtual bool init();
	CREATE_FUNC(HeroBullet);
	void last(StateControl*s);
	void next(StateControl*s);
	void update(int num);
};

#endif