#include "BossBullet_2.h"
#include "GameDefine.h"

BossBullet_2* BossBullet_2::create(Vec2 x, Vec2  y)
{
	BossBullet_2* ret = new BossBullet_2();

	if (ret && ret->init(x,y)){
		ret->autorelease();
		return ret;
	}
	CC_SAFE_DELETE(ret);//��ȫɾ��
	return nullptr;
}

bool BossBullet_2::init(Vec2 x,Vec2 y)
{
	initWithFile("bullet/enemybullet_2.png");
	//�����ӵ��˺�
	this->power = BULLET_POWER_2;
	this->destroy = false;
	if (!Bullet::init())
	{
		return false;
	}
	setTag(ENEMY_BULLET_TAG_1);
	auto body = this->getPhysicsBody();
	//�����ٶ�
	body->setVelocity(Vec2(2*(y.x-x.x),2*(y.y-x.y)));
	return true;
}