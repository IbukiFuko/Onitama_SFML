/*********************
*        卡片        *
*********************/
#pragma once
#include <iostream>
#include <string>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Value.h"
#include "Image.h"

#define CARD_MAX_Y 5
#define CARD_MAX_X 5

//左上角为原点
class Card
{
private:
	int ID;
	static int selID;
	int type;//卡牌编号
	int player;//阵营(0main,1associate,2tmp)
	bool available[CARD_MAX_Y][CARD_MAX_X];//可移动的偏移
	sf::Vector2i targetPos;//当前位置，目标位置
	int deltaRotation;//需要旋转的角度
	int step;//步数
	Image image;//图片
	int SetAvailable();//设置卡片可移动偏移
public:
	Card();
	Card(int);
	void SetPos(int, bool);//设置卡牌坐标
	int getID();//获取ID
	int getSelID();
	sf::Vector2i getPos();//获取坐标
	int getAvailable(sf::Vector2i *, sf::Vector2i *, sf::Vector2i *, sf::Vector2i *);//获取可移动位置
	void Update();
	int Draw();
	static void Reset();//重置选中
};