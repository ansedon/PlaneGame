#pragma once
#ifndef _STRATEGYC_
#define _STRATEGYC_
#include "Strategy.h"
#include "GameScene.h"
class StrategyC :public Strategy
{
public:
	StrategyC();
	void createEnemy(GameScene*Gs);
};
#endif // !_STRATEGYC_




