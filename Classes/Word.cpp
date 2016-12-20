#include"Word.h"

Word* Word::create(const char *word, const int fontSize, Point begin){

Word* ret = new Word();

	if (ret && ret->init(word, fontSize, begin)){
		ret->autorelease();
		return ret;
	}
	CC_SAFE_DELETE(ret);//安全删除
	return nullptr;
}

bool Word::init(const char *word, const int fontSize, Point begin){
	if (!Node::init()){
		return false;
	}
	getmove(word, fontSize, begin);
	return true;
}

//文字从下到上飘动
void Word::getmove(const char *word, const int fontSize, Point begin)
{
	if (!strcmp(word, "more difficult"))
	{
		//初始化
		_begin = begin;
		m_plabel = Label::createWithTTF(word, "fonts/arial.ttf", fontSize);
		m_plabel->setColor(Color3B::WHITE);

		this->addChild(m_plabel);
		this->setPosition(Vec2(begin.x, begin.y));
		MoveBy* moveact = MoveBy::create(1.0f, CCPointMake(0, 300));//1.0秒向上移动300

		//创建回调动作，文字飘动完后
		CallFunc* callFunc = CallFunc::create(this, callfunc_selector(Word::moveend));
		//创建连续动作
		ActionInterval* act = Sequence::create(moveact, callFunc, NULL);
		this->runAction(act);
	}
	else if (!strcmp(word, "record breaking"))
	{
		//初始化
		_begin = begin;
		m_plabel = Label::createWithTTF(word, "fonts/consola.ttf", fontSize);
		m_plabel->setColor(Color3B::RED);

		this->addChild(m_plabel);
		this->setPosition(Vec2(begin.x, begin.y));
		ScaleBy* scaleact = ScaleBy::create(1.0f, 2);
		//创建回调动作，文字飘动完后
		CallFunc* callFunc = CallFunc::create(this, callfunc_selector(Word::moveend));
		//创建连续动作
		ActionInterval* act = Sequence::create(scaleact, callFunc, NULL);
		this->runAction(act);
	}
	else if (!strcmp(word, "missile coming")||!strcmp(word, "right click")||!strcmp(word, "release bomb"))
	{
		//初始化
		_begin = begin;
		m_plabel = Label::createWithTTF(word, "fonts/arial.ttf", fontSize);
		m_plabel->setColor(Color3B::RED);

		this->addChild(m_plabel);
		this->setPosition(Vec2(begin.x, begin.y));
		ScaleBy* scaleact = ScaleBy::create(1.0f, 1.3f);
		ScaleBy* scaleact_2 = ScaleBy::create(1.0f, 0.8f);

		//创建回调动作，文字飘动完后
		CallFunc* callFunc = CallFunc::create(this, callfunc_selector(Word::moveend));
		//创建连续动作
		ActionInterval* act = Sequence::create(scaleact, scaleact_2, callFunc, NULL);
		this->runAction(act);
	}
	else if (!strcmp(word, "Plane Game"))
	{
		//初始化
		_begin = begin;
		m_plabel = Label::createWithTTF(word, "fonts/cooperblack.ttf", fontSize);
		m_plabel->setColor(Color3B::YELLOW);
		this->addChild(m_plabel);
		this->setPosition(Vec2(begin.x, begin.y));
		ScaleBy* scaleact = ScaleBy::create(1.0f, 1.3f);
		ScaleBy* scaleact_2 = ScaleBy::create(2.0f, 1.0f);
		ScaleBy* scaleact_3 = ScaleBy::create(0,1/1.3f);
		ScaleBy* scaleact_4 = ScaleBy::create(1.0f, 1.0f);
		auto scaleact_5 = Sequence::create(scaleact, scaleact_2, scaleact_3, scaleact_4,NULL);
		auto act = CCRepeatForever::create(scaleact_5);
		this->runAction(act);
	}
	else if (!strcmp(word, "BOSS COMING"))
	{
		//初始化
		_begin = begin;
		m_plabel = Label::createWithTTF(word, "fonts/cooperblack.ttf", fontSize);
		m_plabel->setColor(Color3B::RED);
		this->addChild(m_plabel);
		this->setPosition(Vec2(begin.x, begin.y));
		ScaleBy* scaleact = ScaleBy::create(1.0f, 1.3f);
		ScaleBy* scaleact_2 = ScaleBy::create(2.0f, 1.0f);
		ScaleBy* scaleact_3 = ScaleBy::create(0,1/1.3f);
		ScaleBy* scaleact_4 = ScaleBy::create(1.0f, 1.0f);
		CallFunc* callFunc = CallFunc::create(this, callfunc_selector(Word::moveend));
		auto act= Sequence::create(scaleact, scaleact_2, scaleact_3, scaleact_4,callFunc,NULL);
		this->runAction(act);
	}
	else if (!strcmp(word, "YOU WIN"))
	{
		//初始化
		_begin = begin;
		m_plabel = Label::createWithTTF(word, "fonts/cooperblack.ttf", fontSize);
		m_plabel->setColor(Color3B::YELLOW);
		this->addChild(m_plabel);
		this->setPosition(Vec2(begin.x, begin.y));
		ScaleBy* scaleact = ScaleBy::create(1.0f, 1.3f);
		ScaleBy* scaleact_2 = ScaleBy::create(2.0f, 1.0f);
		ScaleBy* scaleact_3 = ScaleBy::create(0,1/1.3f);
		ScaleBy* scaleact_4 = ScaleBy::create(1.0f, 1.0f);
		auto scaleact_5 = Sequence::create(scaleact, scaleact_2, scaleact_3, scaleact_4,NULL);
		auto act = CCRepeatForever::create(scaleact_5);
		this->runAction(act);
	}
}
void Word::moveend()
{
	//完成之后把该对象从内存中删除掉
	this->removeAllChildrenWithCleanup(true);
	this->removeFromParentAndCleanup(true);
}
