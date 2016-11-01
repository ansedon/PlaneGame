#include "Enemy_3.h"
#include "GameDefine.h"
USING_NS_CC;

bool Enemy_3::init()
{
	if(!Enemy::init())
	{
		return false;
	}
	initWithFile("feidan.png");
	auto body = PhysicsBody::createBox(Size(40,115));
	body->setGravityEnable(false);
	body->setCategoryBitmask(1);
	body->setCollisionBitmask(1);
	body->setContactTestBitmask(1);
	this->setPhysicsBody(body);
	//�����ٶ�
	body->setVelocity(Vec2(0,ENEMY_SPEED_3+(rand()%ENEMY_SPEED_3/3)));
	//����Ѫ��
	this->setTag(ENEMY_TAG_1);
	this->blood = ENEMY_BLOOD_3;
	this->name = ENEMY_NAME_3;
	this->hit = false;
	this->destroy = false;
	return true;
}

