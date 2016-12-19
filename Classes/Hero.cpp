#include "Hero.h"
#include "GameDefine.h"

bool Hero::init()
{
	initWithFile("myplane.png");
	this->setPosition( Vec2(SCREEN_WIDTH/2, SCREEN_HEIGHT/6) );
	this->blood = HERO_BLOOD;//初始化基础血量

	screenSize = Director::getInstance()->getVisibleSize();

	this->hit = false;

	//创建一个三角形飞机刚体
	Point points[3] = { Point(-40.00000, -30.00000), Point(0.00000, 42.00000), Point(40.00000, -30.00000) };
	auto body = PhysicsBody::createPolygon(points, 3);
	body->setDynamic(false);
	//设置掩码
	body->setCategoryBitmask(1);
	body->setCollisionBitmask(1);
	body->setContactTestBitmask(1);
	
	this->canMove = true;

	//设置tag
	setTag(HERO_TAG);

	//绑定刚体
	this->setPhysicsBody(body);

	//设置键盘控制
	this->p_a = false;
	this->p_d = false;
	this->p_s = false;
	this->p_w = false;
	
	//创建鼠标监听
	auto listener = EventListenerTouchOneByOne::create();
	listener->onTouchBegan = CC_CALLBACK_2(Hero::onTouchBegan, this);

	listener->onTouchMoved = CC_CALLBACK_2(Hero::onTouchMoved, this);

	listener->onTouchEnded = CC_CALLBACK_2(Hero::onTouchEnded, this);

	listener->setSwallowTouches(false);//不截取触摸事件  

	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);

	//更新位置
	schedule(schedule_selector(Hero::updatePosition), 0.05f);

	//键盘监听
	auto kb_listener = EventListenerKeyboard::create();
	kb_listener->onKeyPressed = CC_CALLBACK_2(Hero::onKeyPressed, this);
	kb_listener->onKeyReleased = CC_CALLBACK_2(Hero::onKeyReleased, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(kb_listener, this);

	return true;
}

bool Hero::onTouchBegan(Touch* touch, Event* event)
{
	this->cpos = touch->getLocation();
	
	return true;
}

//移动飞机
void Hero::onTouchMoved(Touch* touch, Event* event)
{

	if( !canMove )
	{
		return;
	}

	auto touPos = touch->getLocation();

	auto mpos = Vec2( touPos.x-cpos.x, touPos.y-cpos.y );
	auto pos = this->getPosition();
	auto toPos = Vec2(pos.x+mpos.x, pos.y+mpos.y);

	if( toPos.x<0 || toPos.x>screenSize.width || toPos.y<0 || toPos.y>screenSize.height )
		return ;
	this->setPosition(toPos);
	
	
	this->cpos = touch->getLocation();
	
}

void Hero::onTouchEnded(Touch* touch, Event* event)
{
}

void Hero::onKeyPressed(EventKeyboard::KeyCode keyCode,Event * pEvent)
{
	if (keyCode == EventKeyboard::KeyCode::KEY_W)
    {
        CCLOG("Pressed KEY_W");
		this->p_w = true;
    }
	else if (keyCode == EventKeyboard::KeyCode::KEY_A)
    {
        CCLOG("Pressed KEY_A");
		this->p_a = true;
    }
	else if (keyCode == EventKeyboard::KeyCode::KEY_S)
    {
        CCLOG("Pressed KEY_S");
		this->p_s = true;
    }
	else if (keyCode == EventKeyboard::KeyCode::KEY_D)
    {
        CCLOG("Pressed KEY_D");
		this->p_d = true;
    }
}

void Hero::onKeyReleased(EventKeyboard::KeyCode keyCode,Event * pEvent)
{
	if (keyCode == EventKeyboard::KeyCode::KEY_W)
    {
        CCLOG("Released KEY_W");
		this->p_w = false;
    }
	else if (keyCode == EventKeyboard::KeyCode::KEY_A)
    {
        CCLOG("Released KEY_A");
		this->p_a = false;
    }
	else if (keyCode == EventKeyboard::KeyCode::KEY_S)
    {
        CCLOG("Released KEY_S");
		this->p_s = false;
    }
	else if (keyCode == EventKeyboard::KeyCode::KEY_D)
    {
        CCLOG("Released KEY_D");
		this->p_d = false;
    }
}

void Hero::updatePosition(float dt)
{
	auto pos = this->getPosition();
	if (this->p_w) {
		auto toPos = Vec2(pos.x, pos.y + MOVE_VALUE);
		if( toPos.x<0 || toPos.x>screenSize.width || toPos.y<0 || toPos.y>screenSize.height )
			return;
		this->setPosition(toPos);
	}
	if (this->p_a) {
		auto toPos = Vec2(pos.x - MOVE_VALUE, pos.y);
		if( toPos.x<0 || toPos.x>screenSize.width || toPos.y<0 || toPos.y>screenSize.height )
			return;
		this->setPosition(toPos);
	}
	if (this->p_s) {
		auto toPos = Vec2(pos.x, pos.y - MOVE_VALUE);
		if( toPos.x<0 || toPos.x>screenSize.width || toPos.y<0 || toPos.y>screenSize.height )
			return;
		this->setPosition(toPos);
	}
	if (this->p_d) {
		auto toPos = Vec2(pos.x + MOVE_VALUE, pos.y);
		if( toPos.x<0 || toPos.x>screenSize.width || toPos.y<0 || toPos.y>screenSize.height )
			return;
		this->setPosition(toPos);
	}
}

void Hero::update(int num)
{
	this->blood += num*10/3;
}


