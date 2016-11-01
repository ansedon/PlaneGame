#include "Boss.h"
#include "GameDefine.h"

USING_NS_CC;

int Boss::flag = 0;

bool Boss::init()
{
	if (!Enemy::init())
	{
		return false;
	}
	boss_time=99;
	initWithFile("boss.png");
	this->setPosition(Vec2(SCREEN_WIDTH/2, SCREEN_HEIGHT+150));
	//创建边界为一个多边形的boss刚体
	body = PhysicsBody::create();
	Point vert1[4] = { Point(-59.00000, 121.50000), Point(-12.00000, -128.50000), Point(-197.00000, 70.50000), Point(-148.00000, 153.50000) };
	body->addShape(PhysicsShapePolygon::create(vert1, 4));
	Point vert2[4] = { Point(202.00000, 79.50000), Point(22.00000, -126.50000), Point(62.00000, 125.50000), Point(145.00000, 160.50000) };
	body->addShape(PhysicsShapePolygon::create(vert2, 4));
	Point vert3[5] = { Point(22.00000, -126.50000), Point(-12.00000, -128.50000), Point(-59.00000, 121.50000), Point(1.00000, 131.50000), Point(62.00000, 125.50000) };
	body->addShape(PhysicsShapePolygon::create(vert3, 5));
	body->setGravityEnable(false);
	body->setCategoryBitmask(0);
	body->setCollisionBitmask(1);
	body->setContactTestBitmask(1);
	this->setPhysicsBody(body);
	//设置血量
	this->blood = BOSS_BLOOD;
	this->name = BOSS_NAME;
	//方便在GameScene中进行碰撞检测
	setTag(ENEMY_TAG_1);
	this->destroy = false;
	//boss进入的两秒不被打中
	movein();
	//时间调度
	schedule(schedule_selector(Boss::updateTime),
		1, kRepeatForever, 1);
	//boss动作调度
	schedule(schedule_selector(Boss::action),
		4, kRepeatForever, 1);
	return true;
}
//boss的动作
void Boss:: action(float dt)
{
	if (this->boss_time <= 101)
		return;
	else
	{
		if(this->boss_time!=16)
		{
		flag = rand()%6;
		switch (flag)
			{
				case 1:movedown(); break;	
				case 2:moveleft();break;
				case 3:moveright();break;
				case 4:moveleftdown();break;		
				case 5:moverightdown();break;
				default:break;
			}
		}
	}
}

void Boss:: updateTime(float dt)
{
	this->boss_time++;
	//2秒后使boss能被打到
	if (boss_time ==101)
	body->setCategoryBitmask(1);
}

void Boss::movein()
{
	CCActionInterval * blink = CCBlink ::create(2, 6);
	auto movedown = MoveBy::create(2,CCPointMake(0,-330));
	this->runAction( CCSpawn::create(movedown,blink,NULL));
}

void Boss::movedown()
{
	auto mdown = MoveBy::create(1, CCPointMake(0, -200));
	auto mup = MoveBy::create(1, CCPointMake(0, 200));
	runAction(Sequence::create(mdown, mup,NULL));
}

void Boss::moveright()
{
	auto mright = MoveBy::create(1, CCPointMake(100, 0));
	auto mleft= MoveBy::create(1, CCPointMake(-100, 0));
	runAction(Sequence::create(mright, mleft, NULL));
}

void Boss::moveleft()
{
	auto mleft = MoveBy::create(1, CCPointMake(-100, 0));
	auto mright = MoveBy::create(1, CCPointMake(100, 0));
	runAction(Sequence::create( mleft,mright, NULL));
}

void Boss::moveleftdown()
{
	auto act_1 = MoveBy::create(1, CCPointMake(-100, -200));
	auto act_2 = MoveBy::create(1, CCPointMake(100, 200));
	runAction(Sequence::create(act_1, act_2, NULL));
}

void Boss::moverightdown()
{
	auto act_1 = MoveBy::create(1, CCPointMake(100, -200));
	auto act_2 = MoveBy::create(1, CCPointMake(-100, 200));
	runAction(Sequence::create(act_1, act_2, NULL));
}
