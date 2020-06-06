/*********************
*       初始化       *
*********************/
#pragma once
#include <iostream>
#include <string>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Value.h"

void SetFps(int);	//设置帧率
int LoadFont();		//加载字体
int LoadMusic();	//加载音乐
int LoadSound();	//加载音效
int LoadTexture();	//加载图片