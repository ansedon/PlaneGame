#include "BackGround.h"
#include "Win.h"
#include "GameScene.h"
#include "SimpleAudioEngine.h"
#include "Word.h"
USING_NS_CC;
using namespace CocosDenshion;

Scene* Win::createScene()
{
    auto scene = Scene::create();
    auto layer = Win::create();
    scene->addChild(layer);
    return scene;
}

bool Win::init()
{
    if ( !Layer::init() )
    {
        return false;
    }

	auto screenSize= Director::getInstance()->getVisibleSize();

	char szName[100] = { 0 };
	sprintf(szName, "YOU WIN");
	Word *word = Word::create(szName, 110, CCPointMake(screenSize.width / 2, screenSize.height / 2 + 300));
	this->addChild(word, 2);

    //加载背景图片
	auto bg = BackGround::create();
	addChild(bg, 0);

	//加载开始按钮
	auto startItem = MenuItemImage::create( "prestart.png",
		"prestartdown.png",
		CC_CALLBACK_1(Win::menuStartCallback, this));
	startItem->setPosition( Vec2( screenSize.width/2, screenSize.height/2-100 ) );
	//加载返回菜单按钮
	auto QuitItem = MenuItemImage::create( "returnmenu.png",
		"returnmenudown.png",
		CC_CALLBACK_1(Win::menuCloseCallback, this));
	QuitItem->setPosition( Vec2( screenSize.width/2, (screenSize.height/2)-250 ) );
	auto menu = Menu::create( startItem, QuitItem,NULL );
	menu->setAnchorPoint(Vec2(0,0));
	menu->setPosition(Vec2(0,0));
	addChild(menu);
	showScore();
	showTopScore();
	showDiamond();
	showGold();
    return true;
}

void Win::menuStartCallback( Ref* pSender )
{
	//点击start后,切换主游戏场景
	auto scene = GameScene::createScene();
	auto animate = TransitionSlideInR::create(0.5f, scene);
	Director::getInstance()->replaceScene(animate);
}


void Win::showScore()
{
	auto score_label = Label::createWithTTF("", "fonts/cooperblack.ttf", 48);
	score_label->setPosition(Vec2(SCREEN_WIDTH / 2, SCREEN_HEIGHT - 450));
	score_label->setColor(Color3B::ORANGE);
	addChild(score_label, 10);
	char temp[20] = "";
	sprintf(temp, "Score: %d", GameScene::score);
	score_label->setString(temp);
}

void Win::showTopScore()
{
	auto record = UserDefault::getInstance();
	auto topScore = record->getIntegerForKey("topScore");
	if (topScore)
	{
		char temp[20] = "";
		sprintf(temp, "Top Score: %d", topScore);
		auto top_score_label = Label::createWithTTF(temp, "fonts/cooperblack.ttf", 48);
		top_score_label->setPosition(Vec2(SCREEN_WIDTH / 2, SCREEN_HEIGHT - 350));
		top_score_label->setColor(Color3B::ORANGE);
		addChild(top_score_label, 10);
	}
	else
	{
		auto top_score_label = Label::createWithTTF("Top Score: 0", "fonts/cooperblack.ttf", 35);
		top_score_label->setPosition(Vec2(SCREEN_WIDTH / 2, SCREEN_HEIGHT - 350));
		top_score_label->setColor(Color3B::ORANGE);
		addChild(top_score_label);
	}
}

void Win::showGold()
{
	auto sprite = Sprite::create("gold.png");
	sprite->setAnchorPoint(Vec2(0.5, 0.5));
	sprite->setPosition(Vec2(170, 940));
	addChild(sprite, 1);
	auto record = UserDefault::getInstance();
	auto myGold = record->getIntegerForKey("myGold");
	if (myGold)
	{
		char temp[20] = "";
		sprintf(temp, "%d", myGold);
		auto gold_label = Label::createWithTTF(temp, "fonts/cooperblack.ttf", 32);
		gold_label->setPosition(Vec2(230, SCREEN_HEIGHT - 20));
		gold_label->setColor(Color3B::YELLOW);
		addChild(gold_label, 10);
	}
	else
	{
		auto gold_label = Label::createWithTTF("0", "fonts/cooperblack.ttf", 32);
		gold_label->setPosition(Vec2(210, SCREEN_HEIGHT - 20));
		gold_label->setColor(Color3B::YELLOW);
		addChild(gold_label);
	}
}

void Win::showDiamond()
{
	auto sprite = Sprite::create("diamond.png");
	sprite->setAnchorPoint(Vec2(0.5, 0.5));
	sprite->setPosition(Vec2(20, 940));
	addChild(sprite, 1);
	auto record = UserDefault::getInstance();
	auto myDiamond = record->getIntegerForKey("myDiamond");
	if (myDiamond)
	{
		char temp[20] = "";
		sprintf(temp, "%d", myDiamond);
		auto diamond_label = Label::createWithTTF(temp, "fonts/cooperblack.ttf", 32);
		diamond_label->setPosition(Vec2(80, SCREEN_HEIGHT - 20));
		diamond_label->setColor(Color3B::GREEN);
		addChild(diamond_label, 10);
	}
	else
	{
		auto diamond_label = Label::createWithTTF("0", "fonts/cooperblack.ttf", 32);
		diamond_label->setPosition(Vec2(80, SCREEN_HEIGHT - 20));
		diamond_label->setColor(Color3B::GREEN);
		addChild(diamond_label);
	}
}

void Win::menuCloseCallback(Ref* pSender)
{
	//sound
	if (this->voice)
		SimpleAudioEngine::getInstance()->playEffect("music/button.mp3");

	//点击返回菜单后,切换主游戏场景
	auto scene = WelcomeScene::createScene();
	WelcomeScene::voice = true;
	auto animate = TransitionSlideInL::create(0.5f, scene);
	Director::getInstance()->replaceScene(animate);
}
