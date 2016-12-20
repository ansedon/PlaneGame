#pragma once
#ifndef _STRATEGY_
#define _STRATEGY_
#include "Enemy.h"	
class GameScene;
USING_NS_CC;
class Strategy
{
public:
	Strategy();
	virtual void createEnemy(GameScene *Gs);
};
#endif // !_STRATEGY_

