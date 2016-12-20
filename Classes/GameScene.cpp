#include "GameScene.h"
#include "GameDefine.h"
#include "EnemyBullet.h"
#include "SimpleAudioEngine.h"
#include "HeroBullet.h"
#include "HeroBullet_2.h"
#include "HeroBullet_3.h"
#include "GameBackground.h"
#include "EnemyAll.h"
#include "OverScene.h"
#include "EnemyBullet_2.h"
#include "AppDelegate.h"
#include "bonus.h"
#include "Gamepause.h"
#include "Word.h"
#include "Gold.h"
#include "Win.h"
using namespace CocosDenshion;

USING_NS_CC;
int GameScene::score = 0;
int GameScene::gold = 0;
int GameScene::diamond = 0;
Hero*GameScene::hero = NULL;
Boss*GameScene::boss = NULL;
EnemyFactory* GameScene::fac = NULL;

Scene* GameScene::createScene()
{
	//������������
	auto scene = Scene::createWithPhysics();
	auto layer = GameScene::create();
	scene->addChild(layer);
	return scene;
}

bool GameScene::init()
{
	//Ԥ������Ч
	SimpleAudioEngine::getInstance()->preloadEffect("music/game.mp3");
	SimpleAudioEngine::getInstance()->preloadEffect("music/game_over.wav");
	SimpleAudioEngine::getInstance()->preloadEffect("music/.wav");
	if (!Layer::init())
	{
		return false;
	}
	screenSize = Director::getInstance()->getVisibleSize();

	//��ʼ��ʱ��
	this->time = 0;
	this->bonus_time = 6;

	//��ʼ��bonus_flag
	//bonus_flag = 1;

	//��ʼ��enemy_flag
	enemy_flag = 1;

	//���ս������
	auto bg = GameBackground::create();
	addChild(bg);

	hpBgSprite = Sprite::create("hp_2.png");
	hpBgSprite->setPosition(Point(320, 910));
	this->addChild(hpBgSprite);
	hpBar = CCProgressTimer::create(Sprite::create("hp.png"));
	hpBar->setType(ProgressTimer::Type::BAR);
	hpBar->setMidpoint(Point(0, 0));
	hpBar->setBarChangeRate(Point(1, 0));
	hpBar->setPercentage(100);//Ѫ��
	hpBar->setPosition(Point(320, 910));//����㣬����ڱ�����
	addChild(hpBar);

	//���ը��ͼƬ
	auto b_img = CCSprite::create("bomb.png");
	b_img->setPosition(Vec2(50, SCREEN_HEIGHT - 50));
	addChild(b_img);

	//��ʼ��ը��
	this->bomb_num = BOMB_NUM;
	char temp[20] = "";
	sprintf(temp, "x %d", this->bomb_num);
	bomb_label = Label::createWithTTF(temp, "fonts/Marker Felt.ttf", 35);
	bomb_label->setPosition(Vec2(90, SCREEN_HEIGHT - 50));
	bomb_label->setColor(Color3B::ORANGE);
	addChild(bomb_label);

	//���ը������
	auto b_listener = EventListenerMouse::create();
	b_listener->onMouseDown = CC_CALLBACK_1(GameScene::onMouseDown, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(b_listener, this);

	//��ʾ��óɼ�
	showTopScore();

	//��ʼ��score
	showScore();
	//��ʼ����ʯ
	showDiamond();
	//��ʼ�����
	showGold();

	//���hero
	hero = Hero::create();
	addChild(hero, 1);

	//��ʼ��ɱ������
	enemyMum = 0;

	//��ʼ���ȼ�
	level = 0;

	//��ʼ��StateControl
	auto hbullet = HeroBullet::create();
	S = new StateControl(hbullet, 1);
	hbullet->setPosition(Vec2(hero->getPosition().x, hero->getPosition().y + 30));
	buls.pushBack(hbullet);
	addChild(hbullet);

	//sound
	if (WelcomeScene::voice)
		SimpleAudioEngine::getInstance()->playEffect("music/game.mp3", true);

	//�����ײ���
	auto contactlistener = EventListenerPhysicsContact::create();
	contactlistener->onContactBegin = CC_CALLBACK_1(GameScene::contactBegin, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(contactlistener, this);

	//hero�ӵ�������
	schedule(schedule_selector(GameScene::updateHeroBullet),
		HERO_BULLET_RATE_1, kRepeatForever, 1);

	//�л�������
	schedule(schedule_selector(GameScene::updateEnemy),
		ENEMY_RATE_1, kRepeatForever, 1);
	schedule(schedule_selector(GameScene::updateEnemyBullet),
		ENEMY_BULLET_RATE_1, kRepeatForever, 1);
	schedule(schedule_selector(GameScene::updateBossBullet),
		BOSS_BULLET_RATE, kRepeatForever, 1);

	//bonus������
	schedule(schedule_selector(GameScene::updateBonus),
		1.0, kRepeatForever, 1);

	//����
	schedule(schedule_selector(GameScene::updateDestroy), 1 / 60.0f, kRepeatForever, 0);

	//ʱ�ӵ���
	schedule(schedule_selector(GameScene::updateTime), 1.0f, kRepeatForever, 1);

	//��ͣ��ť
	auto visibleSize = Director::getInstance()->getVisibleSize();
	MenuItemImage *CloseItem = MenuItemImage::create(
		"game_pause.png",
		"game_pause.png",
		CC_CALLBACK_1(GameScene::menuPauseCallback, this));

	CloseItem->setPosition(Vec2(visibleSize.width - CloseItem->getContentSize().width / 2,
		visibleSize.height - CloseItem->getContentSize().height / 2));
	Menu* pMenu = Menu::create(CloseItem, NULL);
	pMenu->setPosition(0, 0);
	this->addChild(pMenu, 1);
	return true;
}

void GameScene::menuPauseCallback(Ref* pSender)
{
	//�õ����ڵĴ�С  
	auto visibleSize = Director::getInstance()->getVisibleSize();
	RenderTexture *renderTexture = RenderTexture::create(visibleSize.width, visibleSize.height);

	//������ǰ��������ӽڵ���Ϣ������renderTexture�С�  
	//�������ƽ�ͼ��  
	renderTexture->begin();
	this->getParent()->visit();
	renderTexture->end();
	//��ͣ��������
	SimpleAudioEngine::getInstance()->pauseEffect(SimpleAudioEngine::getInstance()->playEffect("music/game.mp3", true));
	//����Ϸ������ͣ��ѹ�볡����ջ�����л���GamePause����  
	Director::getInstance()->pushScene(Gamepause::scene(renderTexture));
}

void GameScene::updateHeroBullet(float dt)
{
	if (hero->blood > 0)
	{
		//����bonus���õ�ʱ��
		if (S->getBulletType() == 3)
		{
			if (bonus_time == 8 && S->getBulletType() > 1)
			{
				//bonus_flag--;
				S->push();
				bonus_time = 0;
			}
		}
		if (bonus_time == 8 && S->getBulletType() > 1)
		{
			//	bonus_flag--;
			S->push();
		}
		//���Ӣ���ӵ�
		switch (S->getBulletType())
		{
			//�ӵ�1
		case 1:
		{
			auto bul1_1 = HeroBullet::create();
			bul1_1->update(enemyMum);
			S->setType(bul1_1, 1);
			bul1_1->setPosition(Vec2(hero->getPosition().x, hero->getPosition().y + 30));
			buls.pushBack(bul1_1);
			addChild(bul1_1);
			break;
		}
		case 2:
		{
			//�ӵ�2
			auto bul1_1 = HeroBullet_2::create();
			bul1_1->update(enemyMum);
			S->setType(bul1_1, 2);
			bul1_1->setPosition(Vec2(hero->getPosition().x, hero->getPosition().y));
			buls.pushBack(bul1_1);
			addChild(bul1_1);
			break;
		}
		case 3:
		{
			//�ӵ�3
			auto bul1_2 = HeroBullet_3::create();
			bul1_2->update(enemyMum);
			S->setType(bul1_2, 3);
			bul1_2->setPosition(Vec2(hero->getPosition().x, hero->getPosition().y));
			buls.pushBack(bul1_2);
			addChild(bul1_2);
			break;
		}
		}
	}
	return;
}

//Ϊ�о�����ӵ�
void GameScene::updateEnemyBullet(float dt)
{
	//��ӵо��ӵ�
	for (int i = 0; i < emys.size(); i++)
	{
		//���ݻ��������ӵ�
		auto enemy = emys.at(i);
		if (enemy->name == ENEMY_NAME_1)
		{
			if (rand() % 10 < 4)
			{
				auto emyBul = EnemyBullet::create();
				emyBul->update(enemyMum);
				emyBul->setPosition(Vec2(enemy->getPosition().x, enemy->getPosition().y - 55));
				buls.pushBack(emyBul);
				addChild(emyBul);
			}
		}

		else if (enemy->name == ENEMY_NAME_2)
		{
			if (rand() % 10 < 5)
			{
				auto emyBul = EnemyBullet_2::create();
				emyBul->update(enemyMum);
				emyBul->setPosition(Vec2(enemy->getPosition().x, enemy->getPosition().y));
				buls.pushBack(emyBul);
				addChild(emyBul);
			}
		}
		else if (enemy->name == ENEMY_NAME_4)
		{
			if (rand() % 10 < 6)
			{
				auto emyBul = EnemyBullet_2::create();
				emyBul->update(enemyMum);
				emyBul->setPosition(Vec2(enemy->getPosition().x, enemy->getPosition().y));
				buls.pushBack(emyBul);
				addChild(emyBul);
			}
		}
		else if (enemy->name == ENEMY_NAME_5)
		{
			if (rand() % 10 < 8)
			{
				auto emyBul = EnemyBullet_2::create();
				emyBul->update(enemyMum);
				emyBul->setPosition(Vec2(enemy->getPosition().x, enemy->getPosition().y));
				buls.pushBack(emyBul);
				addChild(emyBul);
				auto emyBul_2 = EnemyBullet::create();
				emyBul_2->update(enemyMum);
				emyBul_2->setPosition(Vec2(enemy->getPosition().x - 160, enemy->getPosition().y));
				buls.pushBack(emyBul_2);
				addChild(emyBul_2);
				auto emyBul_3 = EnemyBullet::create();
				emyBul_3->update(enemyMum);
				emyBul_3->setPosition(Vec2(enemy->getPosition().x + 160, enemy->getPosition().y));
				buls.pushBack(emyBul_3);
				addChild(emyBul_3);
			}

		}
		else if (enemy->name == BOSS_NAME)
		{
			if (time > 102 && rand() % 10 < 5 && time % 16 != 0)
			{
				auto emyBul = EnemyBullet_2::create();
				emyBul->update(enemyMum);
				emyBul->setPosition(Vec2(enemy->getPosition().x - 55, enemy->getPosition().y - 150));
				buls.pushBack(emyBul);
				addChild(emyBul);
				auto emyBul_2 = EnemyBullet_2::create();
				emyBul_2->update(enemyMum);
				emyBul_2->setPosition(Vec2(enemy->getPosition().x + 55, enemy->getPosition().y - 150));
				buls.pushBack(emyBul_2);
				addChild(emyBul_2);
			}
			if (time > 102 && rand() % 10 < 7 && time % 16 != 0)
			{
				auto emyBul_3 = EnemyBullet::create();
				emyBul_3->update(enemyMum);
				emyBul_3->setPosition(Vec2(enemy->getPosition().x - 166, enemy->getPosition().y - 15));
				buls.pushBack(emyBul_3);
				addChild(emyBul_3);
				auto emyBul_4 = EnemyBullet::create();
				emyBul_4->update(enemyMum);
				emyBul_4->setPosition(Vec2(enemy->getPosition().x + 166, enemy->getPosition().y - 15));
				buls.pushBack(emyBul_4);
				addChild(emyBul_4);
			}
		}
	}
}

void GameScene::updateBossBullet(float dt)
{
	for (int i = 0; i < emys.size(); i++)
	{
		auto enemy = emys.at(i);
		if (enemy->name == BOSS_NAME)
		{
			if (time % 16 == 0)
			{
				auto act = RotateBy::create(0.4f, 360.0f);
				boss->runAction(act);
				for (int i = 0; i < 10; i++)
				{
					auto emyBul = BossBullet::create(100 * i, -600);
					emyBul->setPosition(Vec2(enemy->getPosition().x, enemy->getPosition().y));
					buls.pushBack(emyBul);
					addChild(emyBul);
					auto emyBul_2 = BossBullet::create(-100 * i, -600);
					emyBul_2->setPosition(Vec2(enemy->getPosition().x, enemy->getPosition().y));
					buls.pushBack(emyBul_2);
					addChild(emyBul_2);
				}
			}
			if (time % 6 == 0)
			{
				auto orin = Vec2(enemy->getPosition().x + 70, enemy->getPosition().y - 100);
				auto orin_2 = Vec2(enemy->getPosition().x - 70, enemy->getPosition().y - 100);
				auto emyBul = BossBullet_2::create(orin, hero->getPosition());
				emyBul->setPosition(Vec2(enemy->getPosition().x + 70, enemy->getPosition().y - 100));
				buls.pushBack(emyBul);
				addChild(emyBul);
				auto emyBul_2 = BossBullet_2::create(orin_2, hero->getPosition());
				emyBul_2->setPosition(Vec2(enemy->getPosition().x - 70, enemy->getPosition().y - 100));
				buls.pushBack(emyBul_2);
				addChild(emyBul_2);
			}
		}
	}
}

void GameScene::updateEnemy(float dt)
{
	if (time != 0 && time % 15 == 12)
	{
		char szName[100] = { 0 };
		sprintf(szName, "missile coming");
		Word *word = Word::create(szName, 64, CCPointMake(320, 480));
		this->addChild(word, 2);
	}

	if (time != 0 && time % 15 == 0)
	{
		//��ӵо�ս��3��
		auto enemy_3 = fac->createEnemy(3);
		enemy_3->update(enemyMum);
		emys.pushBack(enemy_3);
		addChild(enemy_3);
	}

	if (time != 0 && time % 21 == 0 && time < 90)
	{
		//��ӵо�ս��5��
		auto enemy_5 = fac->createEnemy(5);
		enemy_5->update(enemyMum);
		emys.pushBack(enemy_5);
		addChild(enemy_5);
	}

	//ǰ���벻���ֵл�
	if (time < 3)
	{
	}

	else if (time < 10)
	{
		Strategy*st = new StrategyA();
		stg = st;
		stg->createEnemy(this);
	}

	//2
	else if (time < 30)
	{
		Strategy*st = new StrategyB();
		stg = st;
		stg->createEnemy(this);
	}
	else if (time < 70)
	{
		Strategy*st = new StrategyC();
		stg = st;
		stg->createEnemy(this);
	}
	else if (time <= 94)
	{
		Strategy*st = new StrategyD();
		stg = st;
		stg->createEnemy(this);

	}
	if (time == 96)
	{
		char szName[100] = { 0 };
		sprintf(szName, "BOSS COMING");
		Word *word = Word::create(szName, 84, CCPointMake(320, 480));
		this->addChild(word, 2);
	}
	if (time == 99)
	{
		boss = Boss::create();
		emys.pushBack(boss);
		addChild(boss);
	}
}

void GameScene::updateBonus(float dt) {
	//��ʱ����bonus
	if (time != 0 && time % 15 == 0)
	{
		auto bonus = bonus::create();
		bons.pushBack(bonus);
		addChild(bonus);
	}
	//�������bonus
	if (rand() % 20 == 5)
	{
		auto bonus = bonus::create();
		bons.pushBack(bonus);
		addChild(bonus);
	}
}

bool GameScene::contactBegin(PhysicsContact& contact)
{
	//��ȡ�ڵ�
	auto node1 = contact.getShapeA()->getBody()->getNode();
	auto node2 = contact.getShapeB()->getBody()->getNode();
	auto tag_1 = node1->getTag();
	auto tag_2 = node2->getTag();
	//��node1ΪӢ��ս���ӵ���node2Ϊbonus
	if (tag_1 == HERO_BULLET_TAG_1 && tag_2 == BONUS_TAG)
	{
		auto temp_bons = dynamic_cast<bonus*> (node2);
		temp_bons->hit = false;
		temp_bons->destroy = false;
		auto bullet = dynamic_cast<Bullet*> (node1);
		bullet->destroy = false;
		return false;
	}
	//��node2ΪӢ��ս���ӵ���node1Ϊbonus
	else if (tag_2 == HERO_BULLET_TAG_1 && tag_1 == BONUS_TAG)
	{
		auto temp_bons = dynamic_cast<bonus*> (node1);
		temp_bons->hit = false;
		temp_bons->destroy = false;
		auto bullet = dynamic_cast<Bullet*> (node2);
		bullet->destroy = false;
		return false;
	}
	//���ɻ��Ե�bonus
	else if (tag_1 == HERO_TAG && tag_2 == BONUS_TAG)
	{
		hero->hit = false;
		auto temp_bons = dynamic_cast<bonus*> (node2);
		temp_bons->hit = true;
		temp_bons->destroy = true;
		temp_bons->removeFromParent();
		S->pull();
		this->bonus_time = 0;
		return false;
	}
	//���ɻ��Ե�bonus
	else if (tag_2 == HERO_TAG && tag_1 == BONUS_TAG)
	{
		hero->hit = false;
		auto temp_bons = dynamic_cast<bonus*> (node1);
		temp_bons->hit = true;
		temp_bons->destroy = true;
		temp_bons->removeFromParent();
		S->pull();
		this->bonus_time = 0;
		return false;
	}

	//��node1ΪӢ��ս���ӵ���node2Ϊ�о�ս��
	if (tag_1 == HERO_BULLET_TAG_1 && tag_2 == ENEMY_TAG_1)
	{
		auto enemy = dynamic_cast<Enemy*> (node2);
		enemy->hit = true;
		auto bullet = dynamic_cast<Bullet*> (node1);
		bullet->destroy = true;
		if (enemy->name == BOSS_NAME)
		{
			enemy->blood -= bullet->getPower();
			score += bullet->getPower();
			updateScore();
		}
		else
		{
			enemy->blood -= bullet->getPower();
		}
		if (enemy->blood <= 0)
			enemy->destroy = true;
		return false;
	}
	//��node2ΪӢ��ս���ӵ���node1Ϊ�о�ս��
	else if (tag_2 == HERO_BULLET_TAG_1 && tag_1 == ENEMY_TAG_1)
	{
		auto enemy = dynamic_cast<Enemy*> (node1);
		enemy->hit = true;
		auto bullet = dynamic_cast<Bullet*> (node2);
		bullet->destroy = true;
		if (enemy->name == BOSS_NAME)
		{
			enemy->blood -= bullet->getPower();
			score += bullet->getPower();
			updateScore();
		}
		else
		{
			enemy->blood -= bullet->getPower();
		}
		if (enemy->blood <= 0)
			enemy->destroy = true;
		return false;
	}
	//��ײ���л�
	else if (tag_2 == HERO_TAG && tag_1 == ENEMY_TAG_1)
	{
		hero->hit = true;
		auto enemy = dynamic_cast<Enemy*> (node1);
		hero->blood -= enemy->blood;
		hpBar->setPercentage((hero->blood * 100 + enemyMum / 3 * 10) / (HERO_BLOOD + enemyMum / 3 * 10));//Ѫ���仯
		if (enemy->name != BOSS_NAME)
		{
			enemy->blood = 0;
			enemy->destroy = true;
		}
		return false;
	}
	//��ײ���л�
	else if (tag_1 == HERO_TAG && tag_2 == ENEMY_TAG_1)
	{
		hero->hit = true;
		auto enemy = dynamic_cast<Enemy*> (node2);
		hero->blood -= enemy->blood;
		hpBar->setPercentage((hero->blood * 100 + enemyMum / 3 * 10) / (HERO_BLOOD + enemyMum / 3 * 10));//Ѫ���仯
		if (enemy->name != BOSS_NAME)
		{
			enemy->blood = 0;
			enemy->destroy = true;
		}
		return false;
	}
	//��������
	else if (tag_2 == HERO_TAG && tag_1 == ENEMY_BULLET_TAG_1)
	{
		hero->hit = true;
		//����о��ӵ�
		auto temp_bul = dynamic_cast<Bullet*> (node1);
		temp_bul->destroy = true;
		hero->blood -= temp_bul->power;
		hpBar->setPercentage((hero->blood * 100 + enemyMum / 3 * 10) / (HERO_BLOOD + enemyMum / 3 * 10));//Ѫ���仯
		return false;
	}

	else if (tag_2 == ENEMY_BULLET_TAG_1 && tag_1 == HERO_TAG)
	{
		hero->hit = true;
		//����о��ӵ�
		auto temp_bul = dynamic_cast<Bullet*> (node2);
		temp_bul->destroy = true;
		hero->blood -= temp_bul->power;
		hpBar->setPercentage((hero->blood * 100 + enemyMum / 3 * 10) / (HERO_BLOOD + enemyMum / 3 * 10));//Ѫ���仯
		return true;
	}
	return false;
}

//������Ƽ�¼�򷵻�1��û���򷵻�0
int GameScene::record(int score)
{
	auto record = UserDefault::getInstance();
	auto topScore = record->getIntegerForKey("topScore");
	if (topScore)
	{
		if (score > topScore)
		{
			record->setIntegerForKey("topScore", score);
			char szName[100] = { 0 };
			sprintf(szName, "record breaking");
			Word *word = Word::create(szName, 64, CCPointMake(320, 480));
			this->addChild(word, 2);
			return 1;
		}
	}
	else
		record->setIntegerForKey("topScore", score);
	return 0;
}

void GameScene::gold_record(int gold)
{
	auto record = UserDefault::getInstance();
	auto myGold = record->getIntegerForKey("myGold");
	if (myGold)
		record->setIntegerForKey("myGold", myGold + gold);
	else
		record->setIntegerForKey("myGold", gold);
}

void GameScene::diamond_record(int diamond)
{
	auto record = UserDefault::getInstance();
	auto myDiamond = record->getIntegerForKey("myDiamond");
	if (myDiamond)
		record->setIntegerForKey("myDiamond", myDiamond + diamond);
	else
		record->setIntegerForKey("myDiamond", diamond);
}

//��ʾ��߼�¼
void GameScene::showTopScore()
{
	auto record = UserDefault::getInstance();
	auto topScore = record->getIntegerForKey("topScore");
	if (topScore)
	{
		char temp[20] = "";
		sprintf(temp, "Top Score: %d", topScore);
		auto top_score_label = Label::createWithTTF(temp, "fonts/Marker Felt.ttf", 32);
		top_score_label->setPosition(Vec2(310, SCREEN_HEIGHT - 20));
		top_score_label->setColor(Color3B::ORANGE);
		addChild(top_score_label, 10);
	}
	else
	{
		auto top_score_label = Label::createWithTTF("Top Score: 0", "fonts/Marker Felt.ttf", 32);
		top_score_label->setPosition(Vec2(310, SCREEN_HEIGHT - 20));
		top_score_label->setColor(Color3B::ORANGE);
		addChild(top_score_label);
	}
}

void GameScene::showGold()
{
	auto record = UserDefault::getInstance();
	auto myGold = record->getIntegerForKey("myGold");
	if (myGold)
	{
		char temp[20] = "";
		sprintf(temp, "%d", myGold);
		gold_label = Label::createWithTTF(temp, "fonts/Marker Felt.ttf", 32);
		gold_label->setPosition(Vec2(160, SCREEN_HEIGHT - 20));
		gold_label->setColor(Color3B::YELLOW);
		addChild(gold_label, 10);
	}
	else
	{
		gold_label = Label::createWithTTF("0", "fonts/Marker Felt.ttf", 32);
		gold_label->setPosition(Vec2(150, SCREEN_HEIGHT - 20));
		gold_label->setColor(Color3B::YELLOW);
		addChild(gold_label);
	}
}

void GameScene::showDiamond()
{
	auto record = UserDefault::getInstance();
	auto myDiamond = record->getIntegerForKey("myDiamond");
	if (myDiamond)
	{
		char temp[20] = "";
		sprintf(temp, "%d", myDiamond);
		diamond_label = Label::createWithTTF(temp, "fonts/Marker Felt.ttf", 32);
		diamond_label->setPosition(Vec2(60, SCREEN_HEIGHT - 20));
		diamond_label->setColor(Color3B::GREEN);
		addChild(diamond_label, 10);
	}
	else
	{
		diamond_label = Label::createWithTTF("0", "fonts/Marker Felt.ttf", 32);
		diamond_label->setPosition(Vec2(60, SCREEN_HEIGHT - 20));
		diamond_label->setColor(Color3B::GREEN);
		addChild(diamond_label);
	}
}

//��ʾ����
void GameScene::showScore()
{
	this->score = 0;
	score_label = Label::createWithTTF("Score: 0", "fonts/Marker Felt.ttf", 32);
	score_label->setPosition(Vec2(SCREEN_WIDTH - 150, SCREEN_HEIGHT - 20));
	score_label->setColor(Color3B::ORANGE);
	addChild(score_label, 10);
}

void GameScene::GameOver()
{
	//hero��ը����Ч��
	auto pos = hero->getPosition();
	auto particle = ParticleSystemQuad::create("explosion.plist");
	particle->setBlendAdditive(true);
	particle->setPosition(pos);
	particle->setDuration(0.5);
	addChild(particle);
	particle->setAutoRemoveOnFinish(true);
	hero->setVisible(false);

	//��ʾGAME OVER
	auto label = Label::createWithTTF("GAME OVER", "fonts/Marker Felt.ttf", 80);
	label->setPosition(Vec2(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2));
	label->setColor(Color3B::RED);
	addChild(label, 10);

	//ֹͣ�������ֲ���
	SimpleAudioEngine::getInstance()->stopEffect(SimpleAudioEngine::getInstance()->playEffect("music/game.mp3", true));
	//���Ž�������
	if (WelcomeScene::voice)
	{
		SimpleAudioEngine::getInstance()->playEffect("music/game_over.wav");
	}
	//��¼��Ϸ����
	record(score);
	gold_record(gold);
	diamond_record(diamond);
	//ʹhero��ը����Ч����ʱ����ʾ
	scheduleOnce(schedule_selector(GameScene::GameOver_Scene_Change), 3.0f);
}

void GameScene::GameOver_Scene_Change(float dt)
{
	//��Ϸ�������˳�
	auto scene = OverScene::createScene();
	auto animate = TransitionSlideInL::create(0.5f, scene);
	Director::getInstance()->replaceScene(animate);
}

bool GameScene::removeEnemy(Enemy* enemy)
{
	//���о�Ѫ��
	if (enemy->destroy == true || enemy->blood <= 0)
	{
		//�ӷ�
		if (enemy->name == ENEMY_NAME_1)
			score += 50;
		else if (enemy->name == ENEMY_NAME_2)
			score += 100;
		else if (enemy->name == ENEMY_NAME_3)
			score += 350;
		else if (enemy->name == ENEMY_NAME_4)
			score += 150;
		else if (enemy->name == ENEMY_NAME_5)
			score += 400;
		else if (enemy->name == BOSS_NAME)
			score += 1000;
		this->updateScore();
		enemy->removeFromParent();
		emys.eraseObject(enemy);
		return true;
	}
	return false;
}

//���·�������ʾ
void GameScene::updateScore()
{
	char temp[20] = "";
	sprintf(temp, "Score: %d", this->score);
	score_label->setString(temp);
}

//���½�ҵ���ʾ
void GameScene::updateGold()
{
	auto record = UserDefault::getInstance();
	auto myGold = record->getIntegerForKey("myGold");
	char temp[20] = "";
	sprintf(temp, "%d", gold + myGold);
	gold_label->setString(temp);
}


//������ʯ����ʾ
void GameScene::updateDiamond()
{
	auto record = UserDefault::getInstance();
	auto myDiamond = record->getIntegerForKey("myDiamond");
	char temp[20] = "";
	sprintf(temp, "%d", diamond + myDiamond);
	diamond_label->setString(temp);
}

void GameScene::updateDestroy(float dt)
{
	//���hero��Ѫ��
	if (hero->blood <= 0)
		GameOver();
	for (int i = 0; i < bons.size(); i++)
	{
		//���bonus�Ƿ�ɳ�����
		auto pos = bons.at(i)->getPosition();
		if (pos.x<-100 || pos.x>SCREEN_WIDTH + 100 || pos.y<-100 || pos.y>SCREEN_HEIGHT + 100)
		{
			bons.at(i)->removeFromParent();
			bons.eraseObject(bons.at(i));
			i--;
		}
		else if (bons.at(i)->hit || bons.at(i)->destroy)
		{
			bons.at(i)->removeFromParent();
			bons.eraseObject(bons.at(i));
			i--;
		}
	}

	for (int i = 0; i < emys.size(); i++)
	{
		//���о�ս���Ƿ�ɳ�����
		auto pos = emys.at(i)->getPosition();
		if (pos.x<-100 || pos.x>SCREEN_WIDTH + 100 || pos.y < -100)
		{
			emys.at(i)->removeFromParent();
			emys.eraseObject(emys.at(i));
			i--;
		}
		else if (emys.at(i)->destroy || emys.at(i)->blood <= 0)
		{
			enemyMum++;
			if (enemyMum / 30 > level)
			{
				char szName[100] = { 0 };
				sprintf(szName, "more difficult");
				Word *word = Word::create(szName, 64, CCPointMake(320, 400));
				this->addChild(word, 2);
				Change();
				notifyObserver();
				level++;
			}
			//���ݵл�������������Ч��
			if (emys.at(i)->name == ENEMY_NAME_1)
			{
				auto particle = ParticleSystemQuad::create("explosion.plist");
				particle->setBlendAdditive(true);
				particle->setPosition(pos);
				particle->setDuration(0.5);
				addChild(particle);
				particle->setAutoRemoveOnFinish(true);
				//�ĸ��л�1�г���һ�����
				if (rand() % 4 == 1)
				{
					auto mgold = Gold::create(pos, "gold");
					addChild(mgold, 2);
					gold++;
					this->updateGold();
				}
				//15���л�1�г���һ����ʯ
				if (rand() % 15 == 1)
				{
					auto mdiamond = Gold::create(pos, "diamond");
					addChild(mdiamond, 2);
					diamond++;
					this->updateDiamond();
				}
			}
			else if (emys.at(i)->name == ENEMY_NAME_2)
			{
				auto particle = ParticleSystemQuad::create("explosion2.plist");
				particle->setBlendAdditive(true);
				particle->setPosition(pos);
				particle->setDuration(0.5);
				addChild(particle);
				particle->setAutoRemoveOnFinish(true);
				//����л�2�г���һ�����
				if (rand() % 5 == 1)
				{
					auto mgold = Gold::create(pos, "gold");
					addChild(mgold, 2);
					gold++;
					this->updateGold();
				}
				//14���л�2�г���һ����ʯ
				if (rand() % 14 == 1)
				{
					auto mdiamond = Gold::create(pos, "diamond");
					addChild(mdiamond, 2);
					diamond++;
					this->updateDiamond();
				}
			}
			else if (emys.at(i)->name == ENEMY_NAME_3)
			{
				auto particle = ParticleSystemQuad::create("explosion.plist");
				particle->setBlendAdditive(true);
				particle->setPosition(pos);
				particle->setDuration(0.5);
				addChild(particle);
				particle->setAutoRemoveOnFinish(true);
				//ÿ���л�3���������
				auto mgold = Gold::create(pos, "gold");
				addChild(mgold, 2);
				gold++;
				this->updateGold();
				//ÿ���л�3��������ʯ
				auto mdiamond = Gold::create(pos, "diamond");
				addChild(mdiamond, 2);
				diamond++;
				this->updateDiamond();
			}
			else if (emys.at(i)->name == ENEMY_NAME_4)
			{
				auto particle = ParticleSystemQuad::create("explosion2.plist");
				particle->setBlendAdditive(true);
				particle->setPosition(pos);
				particle->setDuration(0.5);
				addChild(particle);
				particle->setAutoRemoveOnFinish(true);
				//�ĸ��л�4�г���һ�����
				if (rand() % 4 == 1)
				{
					auto mgold = Gold::create(pos, "gold");
					addChild(mgold, 2);
					gold++;
					this->updateGold();
				}
				//����л����в���һ����ʯ
				if (rand() % 6 == 1)
				{
					auto mdiamond = Gold::create(pos, "diamond");
					addChild(mdiamond, 2);
					diamond++;
					this->updateDiamond();
				}
			}
			else if (emys.at(i)->name == ENEMY_NAME_5)
			{
				auto particle = ParticleSystemQuad::create("explosion2.plist");
				particle->setBlendAdditive(true);
				particle->setPosition(pos);
				particle->setDuration(0.5);
				addChild(particle);
				particle->setAutoRemoveOnFinish(true);
				//����һ����Һ�һ����ʯ
				auto mgold = Gold::create(Vec2(pos.x + 100, pos.y), "gold");
				addChild(mgold, 2);
				gold++;
				this->updateGold();
				auto mdiamond = Gold::create(Vec2(pos.x - 100, pos.y), "diamond");
				addChild(mdiamond, 2);
				diamond++;
				this->updateDiamond();
			}
			else if (emys.at(i)->name == BOSS_NAME)
			{
				auto particle = ParticleSystemQuad::create("boss_explosion.plist");
				particle->setBlendAdditive(true);
				particle->setPosition(pos);
				particle->setDuration(0.5);
				addChild(particle);
				particle->setAutoRemoveOnFinish(true);
				for (int i = 0; i < 5; i++)
				{
					auto mgold = Gold::create(Vec2(pos.x - 200 + 75 * i, pos.y), "gold");
					addChild(mgold, 2);
					gold++;
					this->updateGold();
					auto mdiamond = Gold::create(Vec2(pos.x - 200 + 55 * i, pos.y), "diamond");
					addChild(mdiamond, 2);
					diamond++;
					this->updateDiamond();
				}
				auto act = CCDelayTime::create(1.0);
				CallFunc* callFunc = CallFunc::create(this, callfunc_selector(GameScene::win));
				this->runAction(Sequence::create(act, callFunc, NULL));
			}
			if (WelcomeScene::voice)
				SimpleAudioEngine::getInstance()->playEffect("music/explo.wav");
			removeEnemy(emys.at(i));
		}
		else if (emys.at(i)->hit)
		{
			emys.at(i)->hit = false;
		}
	}

	//�ж��ӵ��Ƿ��Ƴ�(����Ӣ���ӵ�)
	for (int i = 0; i < buls.size(); i++)
	{
		auto pos = buls.at(i)->getPosition();
		if (pos.x<-100 || pos.x>SCREEN_WIDTH + 100 || pos.y<-100 || pos.y>SCREEN_HEIGHT + 100
			|| buls.at(i)->destroy)
		{
			buls.at(i)->removeFromParent();
			buls.eraseObject(buls.at(i));
			i--;
		}
	}
}

void GameScene::updateTime(float dt)
{
	if (time == 2)
	{
		char szName[100] = { 0 };
		sprintf(szName, "right click");
		Word *word = Word::create(szName, 64, CCPointMake(320, 560));
		this->addChild(word, 2);
		char szName_2[100] = { 0 };
		sprintf(szName_2, "release bomb");
		Word *word_2 = Word::create(szName_2, 64, CCPointMake(320, 440));
		this->addChild(word_2, 2);
	}
	this->time++;
	this->bonus_time++;
}

void GameScene::onMouseDown(Event* e)
{
	EventMouse* event = (EventMouse*)e;
	if (event->getMouseButton() == MOUSE_BUTTON_RIGHT)
	{
		CCLOG("Right Click");
		if (this->bomb_num > 0)
		{
			this->bomb_num -= 1;
			char temp[20] = "";
			sprintf(temp, "x %d", this->bomb_num);
			this->bomb_label->setString(temp);
			this->removeAllEnemy();
		}
	}
}

void GameScene::removeAllEnemy()
{
	//�Ƴ��ӵ�
	for (int i = 0; i < buls.size(); i++)
	{
		buls.at(i)->removeFromParent();
		buls.eraseObject(buls.at(i));
		i--;
	}
	//�Ƴ��л�
	for (int i = 0; i < emys.size(); i++)
	{
		if (emys.at(i)->name != BOSS_NAME)
		{
			emys.at(i)->destroy = true;
			emys.at(i)->blood = 0;
		}
		else
			emys.at(i)->blood -= 500;
	}
}

void GameScene::win()
{
	//ֹͣ�������ֲ���
	SimpleAudioEngine::getInstance()->stopEffect(SimpleAudioEngine::getInstance()->playEffect("music/game.mp3", true));
	//��¼��Ϸ����
	record(score);
	gold_record(gold);
	diamond_record(diamond);
	auto scene = Win::createScene();
	auto animate = TransitionSlideInR::create(1.0f, scene);
	Director::getInstance()->replaceScene(animate);
}

void GameScene::notifyObserver()
{
	for (int i = 0; i < buls.size(); i++)
	{
		buls.at(i)->update(enemyMum);
	}
	for (int i = 0; i < emys.size(); i++)
	{
		emys.at(i)->update(enemyMum);
	}


}

void GameScene::Change()
{
	hero->update(enemyMum);
}


