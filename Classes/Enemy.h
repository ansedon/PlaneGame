#ifndef __ENEMY__
#define __ENEMY__
#include "cocos2d.h"

class Enemy : public cocos2d::Sprite
{
public:
	virtual bool init();
	CREATE_FUNC(Enemy);
	int blood;
	bool destroy;
	int name;
	bool hit;
};

#endif