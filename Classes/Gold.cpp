#include"Gold.h"
#include "GameScene.h"
USING_NS_CC;

Gold* Gold::create(CCPoint begin,const char*name)
{

	Gold* ret = new Gold();

	if (ret && ret->init(begin,name)){
		ret->autorelease();
		return ret;
	}
	CC_SAFE_DELETE(ret);//安全删除
	return nullptr;
}

bool Gold::init(CCPoint begin, const char*name)
{
	//根据传入的name创建精灵
	if (!strcmp(name, "gold"))
	gold = Sprite::create("gold.png");
	else 
	gold = Sprite::create("diamond.png");
	this->addChild(gold);
	this->setPosition(Vec2(begin.x, begin.y));
	pos = GameScene::hero->getPosition();
	//金币按贝赛尔曲线移动
	ccBezierConfig bezierCon;
	//控制点1
	bezierCon.controlPoint_1 = CCPointMake(begin.x,pos.y+(begin.y-pos.y)/3);
	//控制点2
	bezierCon.controlPoint_2 = CCPointMake(begin.x, pos.y+40);
	// 结束位置
	bezierCon.endPosition = CCPointMake(pos.x, pos.y);
	CCActionInterval * action = CCBezierTo::create(0.5, bezierCon);
	CallFunc* callFunc = CallFunc::create(this, callfunc_selector(Gold::moveend));
	auto act = Sequence::create(action, callFunc, NULL);
	this->runAction(act);
	return true;
}

void Gold::moveend()
{
	//完成之后把该对象从内存中删除掉
	this->removeAllChildrenWithCleanup(true);
	this->removeFromParentAndCleanup(true);
}
