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
	CC_SAFE_DELETE(ret);//��ȫɾ��
	return nullptr;
}

bool Gold::init(CCPoint begin, const char*name)
{
	//���ݴ����name��������
	if (!strcmp(name, "gold"))
	gold = Sprite::create("gold.png");
	else 
	gold = Sprite::create("diamond.png");
	this->addChild(gold);
	this->setPosition(Vec2(begin.x, begin.y));
	pos = GameScene::hero->getPosition();
	//��Ұ������������ƶ�
	ccBezierConfig bezierCon;
	//���Ƶ�1
	bezierCon.controlPoint_1 = CCPointMake(begin.x,pos.y+(begin.y-pos.y)/3);
	//���Ƶ�2
	bezierCon.controlPoint_2 = CCPointMake(begin.x, pos.y+40);
	// ����λ��
	bezierCon.endPosition = CCPointMake(pos.x, pos.y);
	CCActionInterval * action = CCBezierTo::create(0.5, bezierCon);
	CallFunc* callFunc = CallFunc::create(this, callfunc_selector(Gold::moveend));
	auto act = Sequence::create(action, callFunc, NULL);
	this->runAction(act);
	return true;
}

void Gold::moveend()
{
	//���֮��Ѹö�����ڴ���ɾ����
	this->removeAllChildrenWithCleanup(true);
	this->removeFromParentAndCleanup(true);
}
