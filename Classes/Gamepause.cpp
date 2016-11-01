#include "Gamepause.h"  
#include "SimpleAudioEngine.h"
using namespace CocosDenshion;

Scene* Gamepause::scene(RenderTexture* sqr)
{
	auto *scene = Scene::create();
	Gamepause *layer = Gamepause::create();
	scene->addChild(layer, 1);//把游戏层放上面，在这上面放按钮  


	//使用游戏界面中截图的sqr纹理图片创建Sprite  
	//并将Sprite添加到GamePause场景层中  
	//得到窗口的大小  
	auto visibleSize = Director::getInstance()->getVisibleSize();
	auto back_spr = Sprite::createWithTexture(sqr->getSprite()->getTexture());
	back_spr->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));  
	back_spr->setFlippedY(true);             //翻转，因为UI坐标和OpenGL坐标不同 
	back_spr->setColor(Color3B::GRAY); //图片颜色设为灰色  
	scene->addChild(back_spr);


	//添加游戏暂停背景小图，用来放按钮  
	auto back_small_spr = Sprite::create("pause.png");
	back_small_spr->setScale(1.5);
	back_small_spr->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2)); 
	scene->addChild(back_small_spr);
	return scene;
}

bool Gamepause::init()
{
	if (!Layer::init())
	{
		return false;
	}
	//得到窗口的大小  
	auto visibleSize = Director::getInstance()->getVisibleSize();
	//原点坐标  
	auto origin = Director::getInstance()->getVisibleOrigin();

	//继续游戏按钮  
	MenuItemImage *pContinueItem = MenuItemImage::create(
		"game_continue.png",
		"pause_continuedown.png",
		CC_CALLBACK_1(Gamepause::menuContinueCallback,this));

	pContinueItem->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2 + 60));

	//重新开始游戏按钮  
	MenuItemImage *pRestartItem = MenuItemImage::create(
		"game_restart.png",
		"game_restartdown.png",
		CC_CALLBACK_1(Gamepause::menuRestart,this));

	pRestartItem->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2 - 20));

	//回主界面  
	MenuItemImage *pLoginItem = MenuItemImage::create(
		"game_menu.png",
		"game_menudown.png",
		CC_CALLBACK_1(Gamepause::menuLogin,this));

	pLoginItem->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2 - 100));

	Menu* pMenu = Menu::create(pContinueItem, pRestartItem, pLoginItem, NULL);
	pMenu->setPosition(0,0);
	this->addChild(pMenu, 2);
	return true;
}
void Gamepause::menuContinueCallback(Ref* pSender)
{
	//恢复背景音乐
	if (WelcomeScene::voice)
	SimpleAudioEngine::getInstance()->resumeEffect(SimpleAudioEngine::getInstance()->playEffect("music/game.mp3", true));
	Director::getInstance()->popScene();

}
//重新开始游戏  
void  Gamepause::menuRestart(Ref* pSender)
{
	Director::getInstance()->replaceScene(GameScene::createScene());
}
//回菜单  
void  Gamepause::menuLogin(Ref* pSender)
{
	Director::getInstance()->replaceScene(WelcomeScene::createScene());
	WelcomeScene::voice=true;
}