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
	int type;//卡牌编号
	bool available[CARD_MAX_Y][CARD_MAX_X];//可移动的偏移
	Image image;//图片
	int SetAvailable();//设置卡片可移动偏移
public:
	Card();
	Card(int);
	void Draw();
};