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
	//������Ϸ  
	void menuContinueCallback(Ref* pSender);
	//���¿�ʼ��Ϸ  
	void menuRestart(Ref* pSender);
	//��������  
	void menuLogin(Ref* pSender);
};

#endif 