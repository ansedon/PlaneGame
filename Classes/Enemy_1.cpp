#include "Enemy_1.h"
#include "GameDefine.h"
USING_NS_CC;

	bool Enemy_1::init()
	{
	initWithFile("enemy.png");
	this->name = ENEMY_NAME_1;
	this->setPosition( Vec2( rand()%SCREEN_WIDTH, SCREEN_HEIGHT+100) );
	this->destroy = false;
	this->hit = false;
	//设置血量
	this->blood = ENEMY_BLOOD_1;
	//创建刚体
	auto body = PhysicsBody::createBox((this->getContentSize())*0.9);
	body->setGravityEnable(false);
	//设置速度
	body->setVelocity(Vec2(0,ENEMY_SPEED_1 + (rand()%(ENEMY_SPEED_1/2)) ));
	//设置掩码
	body->setCategoryBitmask(1);
	body->setCollisionBitmask(1);
	body->setContactTestBitmask(1);
	//设置tag
	setTag(ENEMY_TAG_1);
	//绑定刚体
	this->setPhysicsBody(body);
	return true;
}

void Enemy_1:: update(int num)
{
	this->blood += num * 5;
}


