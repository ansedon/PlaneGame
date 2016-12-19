#ifndef __BULLET__
#define __BULLET__
#include "cocos2d.h"

USING_NS_CC;
class StateControl;
class Bullet : public Sprite
{
public:
	int power;
	int speed;
	virtual bool init();
	CREATE_FUNC(Bullet);
	int getPower();
	//用于判断是否应删除子弹
	bool destroy;
	virtual void last(StateControl*s);
	virtual void next(StateControl*s);
};
#endif