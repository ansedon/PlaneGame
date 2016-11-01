#include "GameBackground.h"
bool GameBackground::init()
{
	//±³¾°Í¼Æ¬
	this->sprite1 = Sprite::create("mybg.jpg");
	this->sprite2 = Sprite::create("mybg.jpg");
	//½ð±ÒÍ¼Æ¬
	auto sprite3 = Sprite::create("gold.png");
	sprite3->setAnchorPoint(Vec2(0.5, 0.5));
	sprite3->setPosition(Vec2(110,940));
	addChild(sprite3,1);
	//×êÊ¯Í¼Æ¬
	auto sprite4 = Sprite::create("diamond.png");
	sprite4->setAnchorPoint(Vec2(0.5, 0.5));
	sprite4->setPosition(Vec2(20,940));
	addChild(sprite4,1);
	sprite1->setAnchorPoint(Vec2(0,0));
	sprite2->setAnchorPoint(Vec2(0,0));
	this->size = sprite1->getContentSize();
	sprite1->setPosition(Vec2(0,0));
	sprite2->setPosition(Vec2(0,size.height));
	addChild(sprite1);
	addChild(sprite2);
	//±³¾°¹ö¶¯
	schedule(schedule_selector(GameBackground::update), 1.0/60.0f, kRepeatForever, 0);
	return true;
}