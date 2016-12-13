#include "Enemy_4.h"
#include "GameDefine.h"
USING_NS_CC;

bool Enemy_4::init()
{
	initWithFile("enemy4.png");
	this->setPosition(Vec2(rand() % SCREEN_WIDTH, SCREEN_HEIGHT + 100));
	auto body = PhysicsBody::createBox((this->getContentSize())*0.9);
	body->setGravityEnable(false);
	body->setCategoryBitmask(1);
	body->setCollisionBitmask(1);
	body->setContactTestBitmask(1);
	this->setPhysicsBody(body);
	//设置速度
	body->setVelocity(Vec2(0,ENEMY_SPEED_4 + (rand()%(ENEMY_SPEED_4/2)) ));

	//设置血量
	this->blood = ENEMY_BLOOD_4;
	this->name = ENEMY_NAME_4;
	this->setTag(ENEMY_TAG_1);
	this->hit = false;
	this->destroy = false;

	//改变飞行轨迹
	schedule(schedule_selector(Enemy_4::update), 2.0f, kRepeatForever, 1);
	return true;
}

void Enemy_4::update(float dt)
{
	auto body = this->getPhysicsBody();
	//改变飞行轨迹
	body->setVelocity( Vec2( ( ENEMY_SPEED_4/2 + rand()%ENEMY_SPEED_4 ),
		(ENEMY_SPEED_4+ rand()%(ENEMY_SPEED_4*3/2) )  ));
}

