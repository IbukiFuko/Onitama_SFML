/*********************
*       指示框       *
*********************/
#pragma once
#include <iostream>
#include <string>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Value.h"
#include "Image.h"
#include "Piece.h"

#define tSIZE_MARK0_X 120
#define tSIZE_MARK0_Y 120
#define tSIZE_MARK1_X 100
#define tSIZE_MARK1_Y 100
#define SIZE_MARK0_X 90
#define SIZE_MARK0_Y 90
#define SIZE_MARK1_X 83
#define SIZE_MARK1_Y 84

class Mark
{
private:
	Piece *piece[2][5];//[0主玩家1副玩家][0master1-4servant]
	Image image[5];//标志图像(0选中，1-4可移动位置)
public:
	Mark();
	Mark(Piece *_0master, Piece *_0servant1, Piece *_0servant2, Piece *_0servant3, Piece *_0servant4,
		 Piece *_1master, Piece *_1servant1, Piece *_1servant2, Piece *_1servant3, Piece *_1servant4);
	void Update();

	int Draw();//绘制标志

	void Refresh();//刷新状态
};