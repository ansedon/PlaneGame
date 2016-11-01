#include "BossBullet.h"
#include "GameDefine.h"

BossBullet* BossBullet::create(float x, float y)
{
	BossBullet* ret = new BossBullet();

	if (ret && ret->init(x,y)){
		ret->autorelease();
		return ret;
	}
	CC_SAFE_DELETE(ret);//安全删除
	return nullptr;
}
bool BossBullet::init(float x,float y)
{
	initWithFile("bullet/enemybullet.png");
	//设置子弹伤害
	this->power = BULLET_POWER_1;
	this->destroy = false;
	if (!Bullet::init())
	{
		return false;
	}
	setTag(ENEMY_BULLET_TAG_1);
	auto body = this->getPhysicsBody();
	//设置速度
	body->setVelocity(Vec2(x,y));
	return true;
}