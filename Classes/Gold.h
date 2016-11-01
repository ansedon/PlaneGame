#ifndef _GOLD_
#define _GOLD_
#include "cocos2d.h"
#include "bonus.h"

USING_NS_CC;

class Gold :public Node
{
private:
	Sprite* gold;
public:
    Vec2 pos;
	static Gold* create(Point begin, const char *name);
	bool init(Point begin, const char *name);
	void moveend(); 

};
#endif