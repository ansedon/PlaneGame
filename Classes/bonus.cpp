#include"bonus.h"
#include "GameDefine.h"
USING_NS_CC;

bool bonus::init()
{
	initWithFile("bonus.png");
	this->setPosition(Vec2(rand() % SCREEN_WIDTH, SCREEN_HEIGHT + 100));
	this->destroy = false;
	this->hit = false;
	//创建刚体
	auto body = PhysicsBody::createBox((this->getContentSize())*0.8);
	body->setGravityEnable(false);
	//速度设置
	body->setVelocity(Vec2(0, BONUS_SPEED + (rand() % (BONUS_SPEED / 2))));
	//设置掩码
	body->setCategoryBitmask(1);
	body->setCollisionBitmask(1);
	body->setContactTestBitmask(1);
	//设置tag
	setTag(BONUS_TAG);
	//绑定刚体
	this->setPhysicsBody(body);
	return true;
}