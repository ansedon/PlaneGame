#include "StrategyA.h"

StrategyA:: StrategyA()
{

}

void StrategyA::createEnemy(GameScene*Gs)
{
	//��ӵо�ս��1��
	for (int i = 0; i < 3; i++)
	{
		auto enemy = Gs->fac->createEnemy(1);
		enemy->update(Gs->enemyMum);
		Gs->emys.pushBack(enemy);
		Gs->addChild(enemy);
	}
}