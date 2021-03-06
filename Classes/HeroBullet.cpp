#include "HeroBullet.h"
#include "GameDefine.h"


bool HeroBullet::init()
{
	initWithFile("bullet/herobullet.png");
	//设置子弹伤害
	this->power = BULLET_POWER_1;
	this->destroy = false;

	if(!Bullet::init())
	{
		return false;
	}
	setTag(HERO_BULLET_TAG_1);
	//设置速度
	auto body = this->getPhysicsBody();
	body->setVelocity(Vec2(0, HERO_BULLET_SPEED));
	return true;
}

void HeroBullet::next(StateControl*s)
{
	Bullet*b = HeroBullet_2::create();
	s->setType(b, 2);
}

void HeroBullet::last(StateControl*s)
{

}

void HeroBullet::update(int num)
{
	this->power += num / 30*50;
}