#pragma once
#ifndef _ENEMY_
#define _ENEMY_
#include "cocos2d.h"
#include "GameDefine.h"

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
