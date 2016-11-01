#include "EnemyBullet_2.h"
#include "GameDefine.h"

bool EnemyBullet_2::init()
{
	initWithFile("bullet/enemybullet_2.png");
	//设置子弹伤害
	this->power = BULLET_POWER_2;
	this->destroy = false;
	if(!Bullet::init())
	{
		return false;
	}
	setTag(ENEMY_BULLET_TAG_1);
	//设置速度
	auto body = this->getPhysicsBody();
	body->setVelocity(Vec2(0,-(BULLET_SPEED_2*3/2 )));
	return true;
}