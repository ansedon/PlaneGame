#ifndef __OVER_SCENE__
#define __OVER_SCENE__

#include "cocos2d.h"

class OverScene : public cocos2d::Layer
{
private:
	Size sreenSize;
	bool voice;
	
public:
	void showScore();
	void showTopScore();
	void showGold();
	void showDiamond();
	bool virtual init();
	static Scene* createScene();
	CREATE_FUNC(OverScene);
	void menuStartCallback( Ref* pSender );
	void menuCloseCallback(cocos2d::Ref* pSender);
	void initVoice();
};

#endif