#pragma once
#ifndef _STRATEGYD_
#define _STRATEGYD_
#include "Strategy.h"
#include "GameScene.h"
class StrategyD :public Strategy
{
public:
	StrategyD();
	void createEnemy(GameScene*Gs);
};
#endif // !_STRATEGYD_




