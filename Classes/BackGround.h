#ifndef __BACKGROUND__
#define __BACKGROUND__

#include "cocos2d.h"
#include "GameDefine.h"
USING_NS_CC;

class BackGround : public Layer
{
public:
	Sprite* sprite1;
	Sprite* sprite2;
	Size size;
	virtual bool init();
	CREATE_FUNC(BackGround);
	void update(float dt);
};


#endif