/*********************
*        棋子        *
*********************/
#pragma once
#include <iostream>
#include <string>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Value.h"
#include "Image.h"

#define tSIZE_MASTER_X 110
#define tSIZE_MASTER_Y 110
#define tSIZE_SERVANT_X 100
#define tSIZE_SERVANT_Y 100

#define SIZE_MASTER_X 101
#define SIZE_MASTER_Y 101
#define SIZE_SERVANT_X 62
#define SIZE_SERVANT_Y 62


//左上角为原点
class Piece//棋子
{
private:
	bool enable;//是否可用
	int type;//棋子类型(大师0、弟子1)
	bool isMainPlayer;//是否为主玩家(0是，1否)
	sf::Vector2i position;//棋盘坐标
	sf::Vector2i coordinate;//像素坐标
	Image image;//棋子图像
public:
	Piece();
	Piece(int, bool, sf::Vector2i);
	int Move(sf::Vector2i);//棋子移动
	sf::Vector2i getPos();//获取位置
	sf::Vector2i getCoordinate();//获取坐标
	bool IsHere(sf::Vector2i);//是否存在
	bool Enable();//是否可用
	void Update();
	int Draw();//绘制棋子

	void Refresh();//刷新状态
};
