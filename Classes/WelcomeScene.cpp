#include "WelcomeScene.h"
#include "GameScene.h"
#include "BackGround.h"
#include "SimpleAudioEngine.h"
#include "AppDelegate.h"
#include "Word.h"
USING_NS_CC;
using namespace CocosDenshion;

bool WelcomeScene::voice = true;

Scene* WelcomeScene::createScene()
{

    auto scene = Scene::create();
    
    auto layer = WelcomeScene::create();

    scene->addChild(layer);

    return scene;
}


bool WelcomeScene::init()
{
    if ( !Layer::init() )
    {
        return false;
    }
	auto screenSize = Director::getInstance()->getVisibleSize();
	//Ô¤¼ÓÔØ±³¾°ÒôÀÖ
	SimpleAudioEngine::getInstance()->preloadEffect("music/game_music.mp3");
    //¼ÓÔØ±³¾°Í¼Æ¬
	auto bg = BackGround::create();
	addChild(bg,0);

	char szName[100] = { 0 };
	sprintf(szName, "Plane Game");
	Word *word = Word::create(szName, 84, CCPointMake(screenSize.width / 2, screenSize.height / 2 + 330));
	this->addChild(word, 2);

	//¼ÓÔØ¿ªÊ¼°´Å¥
	auto startItem = MenuItemImage::create( "start.png",
		"start1.png",
		CC_CALLBACK_1(WelcomeScene::menuStartCallback, this));
	startItem->setPosition( Vec2( screenSize.width/2, screenSize.height/2+50 ) );
	//¼ÓÔØ½áÊø°´Å¥
	auto QuitItem = MenuItemImage::create( "quit.png",
		"quit1.png",
		CC_CALLBACK_1(WelcomeScene::menuCloseCallback, this));
	QuitItem->setPosition( Vec2( screenSize.width/2, (screenSize.height/2)-150 ) );
	//¼ÓÔØÉùÒô°´Å¥
	auto soundon = MenuItemImage::create("soundon.png", "soundon.png");
	auto soundoff = MenuItemImage::create("soundoff.png", "soundoff.png");
	MenuItemToggle *sounditem = MenuItemToggle::createWithCallback(CC_CALLBACK_1(WelcomeScene::menuVoiceCallback, this), soundon, soundoff, NULL);
	sounditem->setPosition(Vec2(25,25));
	auto menu = Menu::create(startItem, QuitItem, sounditem, NULL);
	menu->setAnchorPoint(Vec2(0,0));
	menu->setPosition(Vec2(0,0));
	addChild(menu);
	showDiamond();
	showGold();
    return true;
}

void WelcomeScene::showGold()
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
		gold_label->setPosition(Vec2(230, SCREEN_HEIGHT - 20));
		gold_label->setColor(Color3B::YELLOW);
		addChild(gold_label);
	}
}

void WelcomeScene::showDiamond()
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
		diamond_label->setPosition(Vec2(70, SCREEN_HEIGHT - 20));
		diamond_label->setColor(Color3B::GREEN);
		addChild(diamond_label, 10);
	}
	else
	{
		auto diamond_label = Label::createWithTTF("0", "fonts/cooperblack.ttf", 32);
		diamond_label->setPosition(Vec2(70, SCREEN_HEIGHT - 20));
		diamond_label->setColor(Color3B::GREEN);
		addChild(diamond_label);
	}
}

void WelcomeScene::menuVoiceCallback(Ref* pSpender){
	if (voice){
		voice = false;
	}
	else
		voice = true;
}


void WelcomeScene::menuStartCallback( Ref* pSender )
{
	//µã»÷startºó,ÇÐ»»Ö÷ÓÎÏ·³¡¾°
	auto scene = GameScene::createScene();
	auto animate = TransitionSlideInR::create(1.0f, scene);
	Director::getInstance()->replaceScene(animate);
}

void WelcomeScene::menuCloseCallback(Ref* pSender)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WP8) || (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT)
	MessageBox("You pressed the close button. Windows Store Apps do not implement a close button.","Alert");
    return;
#endif

    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
