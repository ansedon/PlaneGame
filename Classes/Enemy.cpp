#include<Enemy.h>
USING_NS_CC;

bool Enemy::init()
{
	blood = 0;
	destroy = false;
	name = ENEMY_NAME;
	hit = false;
	return true;
}

void Enemy::update(int num)
{
}
