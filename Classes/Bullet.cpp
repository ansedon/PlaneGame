#include "Bullet.h"
#include "GameDefine.h"

bool Bullet::init()
{
	//��������
	auto body = PhysicsBody::createBox(this->getContentSize());
	body->setGravityEnable(false);
	
		//��������
	body->setCategoryBitmask(1);
	body->setCollisionBitmask(1);
	body->setContactTestBitmask(1);
	this->destroy = false;
	//�󶨸���
	this->setPhysicsBody(body);
	return true;
}
//��ȡ������
int Bullet::getPower()
{
	return this->power;
}
