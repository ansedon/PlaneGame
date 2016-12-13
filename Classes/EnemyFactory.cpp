#include "EnemyFactory.h"
Enemy* EnemyFactory::createEnemy(int type)
{
	switch (type)
	{
	case 1:
		return Enemy_1::create();
		break;
	case 2:
		return Enemy_2::create();
		break;
	case 3:
		return Enemy_3::create();
		break;
	case 4:

		return Enemy_4::create();
		break;
	case 5:
		return Enemy_5::create();
		break;
	default:
		printf("error!");
	}
	return false;
}