#include "StrategyB.h"

StrategyB::StrategyB()
{

}

void StrategyB::createEnemy(GameScene*Gs)
{
	//��ӵо�ս��1��
	for (int i = 0; i < 3; i++)
	{
		auto enemy = Gs->fac->createEnemy(1);
		enemy->update(Gs->enemyMum);
		Gs->emys.pushBack(enemy);
		Gs->addChild(enemy);
	}
	//��ӵо�ս��2��
	auto enemy_2 = Gs->fac->createEnemy(2);
	enemy_2->update(Gs->enemyMum);
	Gs->emys.pushBack(enemy_2);
	Gs->addChild(enemy_2);
}