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
	Mark(Piece *, Piece *, Piece *, Piece *, Piece *, Piece *, Piece *, Piece *, Piece *, Piece *);
	
	int Draw();//绘制标志

	void Refresh();//刷新状态
};