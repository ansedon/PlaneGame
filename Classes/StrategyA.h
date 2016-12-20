#pragma once
#ifndef _STRATEGYA_
#define _STRATEGYA_
#include "Strategy.h"
#include "GameScene.h"
class StrategyA :public Strategy
{
public:
	StrategyA();
	void createEnemy(GameScene*Gs);
};
#endif // !_STRATEGYA_




