#ifndef __WELCOME_SCENE__
#define __WELCOME_SCENE__

#include "cocos2d.h"
#include "GameScene.h"

class WelcomeScene : public cocos2d::Layer
{
private:
	cocos2d::Size screenSize;
public:
	void showGold();
	void showDiamond();
	static bool voice;
	static cocos2d::Scene* createScene();
	virtual bool init();
	void menuStartCallback( Ref* pSender );
	void menuVoiceCallback( Ref* pSender );
	void menuCloseCallback(cocos2d::Ref* pSender);
	CREATE_FUNC(WelcomeScene);
};

#endif