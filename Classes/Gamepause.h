#ifndef __GAMEPAUSE__H__  
#define __GAMEPAUSE__H__  
#include "cocos2d.h"  
#include "WelcomeScene.h"
#include "GameScene.h"
USING_NS_CC;
class Gamepause : public cocos2d::Layer
{
public:
	virtual bool init();
	static cocos2d::Scene* scene(RenderTexture* sqr);
	CREATE_FUNC(Gamepause);
	//继续游戏  
	void menuContinueCallback(Ref* pSender);
	//重新开始游戏  
	void menuRestart(Ref* pSender);
	//回主界面  
	void menuLogin(Ref* pSender);
};

#endif 