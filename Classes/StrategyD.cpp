#include "StrategyD.h"

StrategyD::StrategyD()
{

}

void StrategyD::createEnemy(GameScene*Gs)
{
	//��ӵо�ս��2��
	auto enemy_2 = Gs->fac->createEnemy(2);
	enemy_2->update(Gs->enemyMum);
	Gs->emys.pushBack(enemy_2);
	Gs->addChild(enemy_2);
	auto enemy_3 = Gs->fac->createEnemy(2);
	enemy_3->update(Gs->enemyMum);
	Gs->emys.pushBack(enemy_3);
	Gs->addChild(enemy_3);
	//��ӵо�4��
	for (int i = 0; i < 3; i++)
	{
		auto enemy_4 = Gs->fac->createEnemy(4);
		enemy_4->update(Gs->enemyMum);
		Gs->emys.pushBack(enemy_4);
		Gs->addChild(enemy_4);
	}
}