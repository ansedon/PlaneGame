#include "Bullet.h"
#include "GameDefine.h"

bool Bullet::init()
{
	//创建刚体
	auto body = PhysicsBody::createBox(this->getContentSize());
	body->setGravityEnable(false);
	
		//设置掩码
	body->setCategoryBitmask(1);
	body->setCollisionBitmask(1);
	body->setContactTestBitmask(1);
	this->destroy = false;
	//绑定刚体
	this->setPhysicsBody(body);
	return true;
}
//获取攻击力
int Bullet::getPower()
{
	return this->power;
}

void Bullet::last(StateControl*s)
{
	CCLOG("last");
}

void Bullet::next(StateControl*s)
{
	CCLOG("next");
}

void Bullet::update(int num)
{
	CCLOG("update");
}