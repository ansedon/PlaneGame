#include "EnemyBullet_2.h"
#include "GameDefine.h"

bool EnemyBullet_2::init()
{
	initWithFile("bullet/enemybullet_2.png");
	//�����ӵ��˺�
	this->power = BULLET_POWER_2;
	this->destroy = false;
	if(!Bullet::init())
	{
		return false;
	}
	setTag(ENEMY_BULLET_TAG_1);
	//�����ٶ�
	auto body = this->getPhysicsBody();
	body->setVelocity(Vec2(0,-(BULLET_SPEED_2*3/2 )));
	return true;
}