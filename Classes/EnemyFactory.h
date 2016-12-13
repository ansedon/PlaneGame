#pragma once
#ifndef _ENEMYFACTORY_
#define _ENEMYFACTORY_
#include "EnemyAll.h"

class EnemyFactory
{
public:
	Enemy* createEnemy(int type);
};

#endif
