#include "BackGround.h"

bool BackGround::init()
{
	this->sprite1 = Sprite::create("mybg1.jpg");
	this->sprite2 = Sprite::create("mybg1.jpg");

	sprite1->setAnchorPoint(Vec2(0,0));
	sprite2->setAnchorPoint(Vec2(0,0));

	this->size = sprite1->getContentSize();
	
	sprite1->setPosition(Vec2(0, 0));
	sprite2->setPosition(Vec2(0,size.height));

	setAnchorPoint(Vec2(0, 0));
	setPosition(Vec2(0, 0));


	addChild(sprite1);
	addChild(sprite2);

	schedule(schedule_selector(BackGround::update));

	return true;
}
//使背景以每帧移动2的速度向下滚动
void BackGround::update(float dt)
{
	auto pos1 = sprite1->getPosition();
	auto pos2 = sprite2->getPosition();

	sprite1->setPosition(Vec2(0, pos1.y-2));
	sprite2->setPosition(Vec2(0, pos2.y-2));

	if( pos2.y == 0 )
	{
		sprite1->setPosition(Vec2(0, pos2.y+size.height-2));
	}
	if( pos1.y == 0 )
	{
		sprite2->setPosition(Vec2(0, pos1.y+size.height-2));
	}
}
