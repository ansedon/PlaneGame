#pragma once
#ifndef _STATECONTROL_
#define _STATECONTROL_
#include "Bullet.h"
class Bullet;

class StateControl
{
private:
	Bullet *bullet;
	int bulletType;
public:
	StateControl(Bullet*bul, int bulType);
	void setType(Bullet*bul, int bulType);
	int getBulletType();
	void push();
	void pull();
};
#endif
