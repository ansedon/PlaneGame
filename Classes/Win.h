#ifndef __WIN__
#define __WIN__

#include "cocos2d.h"

class Win : public cocos2d::Layer
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
	CREATE_FUNC(Win);
	void menuStartCallback( Ref* pSender );
	void menuCloseCallback(cocos2d::Ref* pSender);
	void initVoice();
};

#endif