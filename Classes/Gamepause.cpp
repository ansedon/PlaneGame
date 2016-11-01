#include "Gamepause.h"  
#include "SimpleAudioEngine.h"
using namespace CocosDenshion;

Scene* Gamepause::scene(RenderTexture* sqr)
{
	auto *scene = Scene::create();
	Gamepause *layer = Gamepause::create();
	scene->addChild(layer, 1);//����Ϸ������棬��������Ű�ť  


	//ʹ����Ϸ�����н�ͼ��sqr����ͼƬ����Sprite  
	//����Sprite��ӵ�GamePause��������  
	//�õ����ڵĴ�С  
	auto visibleSize = Director::getInstance()->getVisibleSize();
	auto back_spr = Sprite::createWithTexture(sqr->getSprite()->getTexture());
	back_spr->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));  
	back_spr->setFlippedY(true);             //��ת����ΪUI�����OpenGL���겻ͬ 
	back_spr->setColor(Color3B::GRAY); //ͼƬ��ɫ��Ϊ��ɫ  
	scene->addChild(back_spr);


	//�����Ϸ��ͣ����Сͼ�������Ű�ť  
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
	//�õ����ڵĴ�С  
	auto visibleSize = Director::getInstance()->getVisibleSize();
	//ԭ������  
	auto origin = Director::getInstance()->getVisibleOrigin();

	//������Ϸ��ť  
	MenuItemImage *pContinueItem = MenuItemImage::create(
		"game_continue.png",
		"pause_continuedown.png",
		CC_CALLBACK_1(Gamepause::menuContinueCallback,this));

	pContinueItem->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2 + 60));

	//���¿�ʼ��Ϸ��ť  
	MenuItemImage *pRestartItem = MenuItemImage::create(
		"game_restart.png",
		"game_restartdown.png",
		CC_CALLBACK_1(Gamepause::menuRestart,this));

	pRestartItem->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2 - 20));

	//��������  
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
	//�ָ���������
	if (WelcomeScene::voice)
	SimpleAudioEngine::getInstance()->resumeEffect(SimpleAudioEngine::getInstance()->playEffect("music/game.mp3", true));
	Director::getInstance()->popScene();

}
//���¿�ʼ��Ϸ  
void  Gamepause::menuRestart(Ref* pSender)
{
	Director::getInstance()->replaceScene(GameScene::createScene());
}
//�ز˵�  
void  Gamepause::menuLogin(Ref* pSender)
{
	Director::getInstance()->replaceScene(WelcomeScene::createScene());
	WelcomeScene::voice=true;
}