#include "Enemy_3.h"
#include "GameDefine.h"
USING_NS_CC;

bool Enemy_3::init()
{
	initWithFile("feidan.png");
	this->setPosition(Vec2(rand() % SCREEN_WIDTH, SCREEN_HEIGHT + 100));
	auto body = PhysicsBody::createBox(Size(40,115));
	body->setGravityEnable(false);
	body->setCategoryBitmask(1);
	body->setCollisionBitmask(1);
	body->setContactTestBitmask(1);
	this->setPhysicsBody(body);
	//设置速度
	body->setVelocity(Vec2(0,ENEMY_SPEED_3+(rand()%ENEMY_SPEED_3/3)));
	//设置血量
	this->setTag(ENEMY_TAG_1);
	this->blood = ENEMY_BLOOD_3;
	this->name = ENEMY_NAME_3;
	this->hit = false;
	this->destroy = false;
	return true;
}

void Enemy_3::update(int num)
{
	this->blood += num * 5;
}

