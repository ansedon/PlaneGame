#include "EnemyBullet.h"
#include "GameDefine.h"

bool EnemyBullet::init()
{
	initWithFile("bullet/enemybullet.png");
	//设置子弹伤害
	this->power = BULLET_POWER_1;
	this->destroy = false;
	if(!Bullet::init())
	{
		return false;
	}
	setTag(ENEMY_BULLET_TAG_1);
	//设置速度
	auto body = this->getPhysicsBody();
	body->setVelocity(Vec2(0,-BULLET_SPEED_1));
	return true;
}