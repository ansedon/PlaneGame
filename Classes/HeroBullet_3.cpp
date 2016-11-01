#include "HeroBullet_3.h"
#include "GameDefine.h"

bool HeroBullet_3::init()
{
	initWithFile("bullet/herobullet_3.png");
	//�����ӵ��˺�
	this->power = BULLET_POWER_3;
	this->destroy = false;

	if (!Bullet::init())
	{
		return false;
	}
	setTag(HERO_BULLET_TAG_1);
	//�����ٶ�
	auto body = this->getPhysicsBody();
	body->setVelocity(Vec2(0, HERO_BULLET_SPEED));
	return true;
}