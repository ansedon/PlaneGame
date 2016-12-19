#include "HeroBullet_2.h"
#include "GameDefine.h"

bool HeroBullet_2::init()
{
	initWithFile("bullet/herobullet_2.png");
	//设置子弹伤害
	this->power = BULLET_POWER_2;
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

void HeroBullet_2::next(StateControl*s)
{
	Bullet*b = HeroBullet_3::create();
	s->setType(b,3);
}

void HeroBullet_2::last(StateControl*s)
{
	Bullet*b = HeroBullet::create();
	s->setType(b, 1);
}

void HeroBullet_2::update(int num)
{
	this->power += num / 30 * 50;
}
