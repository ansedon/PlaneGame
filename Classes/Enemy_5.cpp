#include "Enemy_5.h"
#include "GameDefine.h"
USING_NS_CC;

bool Enemy_5::init()
{
	if(!Enemy::init())
	{
		return false;
	}
	initWithFile("enemy5.png");

	//��������
	auto body = PhysicsBody::createBox((this->getContentSize()) * 0.9);

	//50%�ٶȸ���
	body->setVelocity(Vec2(0,ENEMY_SPEED_5 + (rand()%(ENEMY_SPEED_5/2)) ));
	body->setGravityEnable(false);
	//��������
	body->setCategoryBitmask(1);
	body->setCollisionBitmask(1);
	body->setContactTestBitmask(1);
	//�󶨸���
	this->setPhysicsBody(body);

	//����Ѫ��
	this->blood = ENEMY_BLOOD_5;
	this->name = ENEMY_NAME_5;
	this->setTag(ENEMY_TAG_1);
	this->hit = false;
	this->destroy = false;

	//�ı���й켣
	schedule(schedule_selector(Enemy_5::update), 1.0f, kRepeatForever, 1);
	return true;
}

void Enemy_5::update(float dt)
{
	auto body = this->getPhysicsBody();
	//50%�ٶȸ���
	body->setVelocity( Vec2( ( ENEMY_SPEED_5/2 + rand()%ENEMY_SPEED_5 ),
		(ENEMY_SPEED_5+ rand()%(ENEMY_SPEED_5*3/2) )  ));
}
