#include "HeroBullet_3.h"
#include "GameDefine.h"

bool HeroBullet_3::init()
{
	initWithFile("bullet/herobullet_3.png");
	//设置子弹伤害
	this->power = BULLET_POWER_3;
	this->destroy = false;

	if (!Bullet::init())
	{
		return false;
	}
	setTag(HERO_BULLET_TAG_1);
	//设置速度
	auto body = this->getPhysicsBody();
	body->setVelocity(Vec2(0, HERO_BULLET_SPEED));
	return true;
}

void HeroBullet_3::next(StateControl*s)
{
	Bullet*b = HeroBullet::create();
	s->setType(b, 1);
}

void HeroBullet_3::last(StateControl*s)
{
	Bullet*b = HeroBullet_2::create();
	s->setType(b, 2);
}
