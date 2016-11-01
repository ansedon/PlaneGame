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

	//创建刚体
	auto body = PhysicsBody::createBox((this->getContentSize()) * 0.9);

	//50%速度浮动
	body->setVelocity(Vec2(0,ENEMY_SPEED_5 + (rand()%(ENEMY_SPEED_5/2)) ));
	body->setGravityEnable(false);
	//设置掩码
	body->setCategoryBitmask(1);
	body->setCollisionBitmask(1);
	body->setContactTestBitmask(1);
	//绑定刚体
	this->setPhysicsBody(body);

	//设置血量
	this->blood = ENEMY_BLOOD_5;
	this->name = ENEMY_NAME_5;
	this->setTag(ENEMY_TAG_1);
	this->hit = false;
	this->destroy = false;

	//改变飞行轨迹
	schedule(schedule_selector(Enemy_5::update), 1.0f, kRepeatForever, 1);
	return true;
}

void Enemy_5::update(float dt)
{
	auto body = this->getPhysicsBody();
	//50%速度浮动
	body->setVelocity( Vec2( ( ENEMY_SPEED_5/2 + rand()%ENEMY_SPEED_5 ),
		(ENEMY_SPEED_5+ rand()%(ENEMY_SPEED_5*3/2) )  ));
}

