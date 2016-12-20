#pragma once
#ifndef _STRATEGYB_
#define _STRATEGYB_
#include "Strategy.h"
#include "GameScene.h"
class StrategyB :public Strategy
{
public:
	StrategyB();
	void createEnemy(GameScene*Gs);
};
#endif // !_STRATEGYB_




