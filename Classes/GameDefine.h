#ifndef __GAME_DEFINE__
#define __GAME_DEFINE__

//英雄设置
#define HERO_BULLET_RATE_1 0.2f //hero子弹频率
#define HERO_BLOOD 1000//hero基础血量
#define MOVE_VALUE 20//hero键盘控制移动速度


//敌军战机设置
#define ENEMY_SPEED_1 -200  //敌军速度基类
#define ENEMY_BLOOD_1 50 //基础血条
#define ENEMY_NAME_1 1
#define ENEMY_RATE_1 3.0f  //敌军出现频率
#define ENEMY_BULLET_RATE_1 0.6f //敌军子弹频率
#define BOSS_BULLET_RATE 2.0f
//2
#define ENEMY_BLOOD_2 100 //2代血条
#define ENEMY_SPEED_2 -300  //敌军二代速度基类
#define ENEMY_NAME_2 2
//3
#define ENEMY_BLOOD_3 300 
#define ENEMY_SPEED_3 -900  
#define ENEMY_NAME_3 3

//4
#define ENEMY_BLOOD_4 150 
#define ENEMY_SPEED_4 -300  
#define ENEMY_NAME_4 4

//5
#define ENEMY_BLOOD_5 800
#define ENEMY_SPEED_5 -200  
#define ENEMY_NAME_5 5

//boss
#define BOSS_BLOOD 10000
#define BOSS_NAME 6

//屏幕设置
#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 960 

//子弹设置
#define BULLET_SPEED_1 400 //基础子弹速度
#define BULLET_SPEED_2 300
#define BULLET_SPEED_3 400
#define BULLET_POWER_1 50
#define BULLET_POWER_2 100
#define BULLET_POWER_3 150

//玩家子弹速度
#define HERO_BULLET_SPEED 700

//tags
#define HERO_TAG 1 
#define HERO_BULLET_TAG_1 2 //hero子弹基类
#define ENEMY_TAG_1 3		//敌军基类
#define ENEMY_TAG_2 4		//敌军2代类
#define ENEMY_BULLET_TAG_1 5	//敌军子弹基类
#define HERO_BULLET_TAG_2 6

#define BONUS_TAG  7
#define BONUS_SPEED -350

#define BOMB_NUM 3
#endif