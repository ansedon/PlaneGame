#include "EnemyBullet.h"
#include "GameDefine.h"

bool EnemyBullet::init()
{
	initWithFile("bullet/enemybullet.png");
	//�����ӵ��˺�
	this->power = BULLET_POWER_1;
	this->destroy = false;
	if(!Bullet::init())
	{
		return false;
	}
	setTag(ENEMY_BULLET_TAG_1);
	//�����ٶ�
	auto body = this->getPhysicsBody();
	body->setVelocity(Vec2(0,-BULLET_SPEED_1));
	return true;
}