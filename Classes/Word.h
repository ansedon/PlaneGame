#ifndef _WOED_H_
#define _WOED_H_
#include "cocos2d.h"
USING_NS_CC;

class Word :public Node
{
public:
	static Word* create(const char *word, const int fontSize, Point begin);
	bool init(const char *word, const int fontSize, Point begin);
	void getmove(const char *word, const int fontSize, Point begin);
	void moveend();
private:
	int _fontSize;//字体大小
	Point _begin;//要添加到的怪物的中心点
	Label* m_plabel;//字体类型
};

#endif