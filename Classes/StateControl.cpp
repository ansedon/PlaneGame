#include "StateControl.h"

StateControl::StateControl(Bullet*bul, int bulType)
{
	bullet = bul;
	bulletType = bulType;
}

void StateControl::setType(Bullet*bul, int bulType)
{
	bullet = bul;
	bulletType = bulType;
}

int StateControl::getBulletType()
{
	return bulletType;
}

void StateControl::push()
{
	bullet->last(this);
}

void StateControl::pull()
{
	bullet->next(this);
}