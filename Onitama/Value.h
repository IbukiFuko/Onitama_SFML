/*********************
*      全局变量      *
*********************/
#pragma once
#include <iostream>
#include <string>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#define MAX_CARD_NUM 16
#define COORDINATE sf::Vector2i(111,103)//棋盘左上坐标
#define SIZE sf::Vector2i(130,129)//棋盘格子像素大小
#define MAIN_HOME sf::Vector2i(4,2)//主玩家老家
#define ASSOCIATE_HOME sf::Vector2i(0,2)//副玩家老家


extern const int WindowWidth, WindowHeight;	//窗体大小
extern const int StageWidth, StageHeight;		//舞台大小
extern const wchar_t* WindowName;//窗体名称
extern const int FPS;//帧率

extern int objectID;//object互斥id

extern bool GameOver;
extern bool isPlayingAnimation;//是否在播放动画

extern sf::RenderWindow window;//窗体
extern sf::Font font;//字体
extern sf::Event event;//事件
extern sf::Vector2i mousePos;//鼠标位置

extern const int MaxPlayer;//玩家最大数量
extern int currentPlayer;//当前玩家
extern int playerCard[];//卡牌

extern sf::Text testText;//测试文字

enum bgmType//bgm枚举
{
	bgmType_Menu,
	bgmType_01,
	bgmType_02,
	bgmType_03,
};

enum sceneID//scene枚举
{
	scene_mainMenu,
	scene_battle,
	scene_menu,
};

enum cardID//card枚举
{
	mainCard0,		//主玩家0
	mainCard1,		//主玩家1
	associateCard0,	//副玩家0
	associateCard1,	//副玩家1
	tmpCard,		//待定区
};

enum playerID//玩家枚举
{
	mainPlayer,
	associatePlayer,
};

extern sf::Music bgm[];//BGM（0-Menu; 1~3BGM）

extern sf::Texture tLogo, tBackground, tChessboard;
extern sf::Sprite sLogo, sBackground, sChessboard;
extern sf::Texture tPiece[][2], tMark[], tCard[];
//extern sf::Sprite sPiece[][2], sMark[];
extern sf::Vector2i sizeLogo;
extern sf::IntRect a;

//事件相关
extern bool mouseLeftPressed;//鼠标左键按下
extern bool spacePressed;//空格按下

void resetEvent();