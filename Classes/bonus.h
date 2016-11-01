#ifndef _BONUS_
#define _BONUS_
#include "cocos2d.h"

USING_NS_CC;

class bonus :public cocos2d::Sprite
{
public:
	virtual bool init();
	CREATE_FUNC(bonus);
	bool destroy;
	int name;
	bool hit;
};
#endif