#include "HeroBullet.h"
#include "GameDefine.h"

bool HeroBullet::init()
{
	initWithFile("bullet/herobullet.png");
	//�����ӵ��˺�
	this->power = BULLET_POWER_1;
	this->destroy = false;

	if(!Bullet::init())
	{
		return false;
	}
	setTag(HERO_BULLET_TAG_1);
	//�����ٶ�
	auto body = this->getPhysicsBody();
	body->setVelocity(Vec2(0, HERO_BULLET_SPEED));
	return true;
}