#ifndef __HERO__
#define __HERO__

#include "cocos2d.h"
#include "Bullet.h"
USING_NS_CC;

class Hero : public Sprite
{
private:
	bool canMove;
	Vec2 cpos;
	Size screenSize;
	int mx;
	int my;
public:
	int blood;
	virtual bool init();
	CREATE_FUNC(Hero);
	bool onTouchBegan(Touch* touch, Event* event);
	void onTouchMoved(Touch* touch, Event* event);
	void onTouchEnded(Touch* touch, Event* event);
	void onKeyPressed(EventKeyboard::KeyCode keyCode,Event * pEvent);
	void onKeyReleased(EventKeyboard::KeyCode keyCode,Event * pEvent);
	void updatePosition(float dt);
	bool hit;
	bool p_w, p_a, p_s, p_d;
};


#endif