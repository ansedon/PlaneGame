#include"bonus.h"
#include "GameDefine.h"
USING_NS_CC;

bool bonus::init()
{
	initWithFile("bonus.png");
	this->setPosition(Vec2(rand() % SCREEN_WIDTH, SCREEN_HEIGHT + 100));
	this->destroy = false;
	this->hit = false;
	//��������
	auto body = PhysicsBody::createBox((this->getContentSize())*0.8);
	body->setGravityEnable(false);
	//�ٶ�����
	body->setVelocity(Vec2(0, BONUS_SPEED + (rand() % (BONUS_SPEED / 2))));
	//��������
	body->setCategoryBitmask(1);
	body->setCollisionBitmask(1);
	body->setContactTestBitmask(1);
	//����tag
	setTag(BONUS_TAG);
	//�󶨸���
	this->setPhysicsBody(body);
	return true;
}