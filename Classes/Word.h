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
	int _fontSize;//�����С
	Point _begin;//Ҫ��ӵ��Ĺ�������ĵ�
	Label* m_plabel;//��������
};

#endif