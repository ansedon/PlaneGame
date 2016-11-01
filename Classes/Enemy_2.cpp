#include "Enemy_2.h"
#include "GameDefine.h"
USING_NS_CC;

bool Enemy_2::init()
{
	if(!Enemy::init())
	{
		return false;
	}
	initWithFile("enemy2.png");
	this->setPosition(Vec2(rand() % SCREEN_WIDTH, SCREEN_HEIGHT + 100));
	auto body = PhysicsBody::createBox((this->getContentSize())*0.9);
	body->setGravityEnable(false);
	body->setCategoryBitmask(1);
	body->setCollisionBitmask(1);
	body->setContactTestBitmask(1);
	this->setPhysicsBody(body);
	//�����ٶ�
	body->setVelocity(Vec2(0,ENEMY_SPEED_2 + (rand()%(ENEMY_SPEED_2/2)) ));
	//����Ѫ��
	this->blood = ENEMY_BLOOD_2;

	this->name = ENEMY_NAME_2;

	this->hit = false;

	this->destroy = false;
	//�ı���й켣
	schedule(schedule_selector(Enemy_2::update), 0.5f, kRepeatForever, 1);
	return true;
}

void Enemy_2::update(float dt)
{
	auto body = this->getPhysicsBody();
	//�ı��˶�����
	body->setVelocity( Vec2( ( ENEMY_SPEED_2/2 + rand()%ENEMY_SPEED_2 ),
		(ENEMY_SPEED_2+ rand()%(ENEMY_SPEED_2*3/2) )  ));
}