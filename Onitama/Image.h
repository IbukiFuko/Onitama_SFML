/*********************
*        按钮        *
*********************/
#pragma once
#include <iostream>
#include <string>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Value.h"

class Image//按钮
{
private:
	bool flag;
	sf::Vector2i position;
	float rotation;
	int imageWidth;
	int imageHeight;
	sf::Sprite sImage;
	int spriteWidth;
	int spriteHeight;
	sf::Text Text;
	int strSize;
	int strLength;
public:
	Image();
	Image(int, int, int, int, int, int, sf::Texture *, std::string, int);//构造函数(坐标,目标尺寸,当前尺寸,位图,文字信息)
	int SetPosition(int, int);//设置位置
	int SetPosition(sf::Vector2i);
	int SetSize(int, int);//设置大小
	int SetSprite(sf::Texture *, int, int);//设置纹理
	int SetText(std::string, int);//设置文字
	int SetRotation(float);//设置旋转
	int Draw();//绘制按钮
	sf::Vector2i GetPos();//获取位置
	sf::Vector2i GetSize();//获取大小
	float GetRotation();//获取旋转

	void Refresh();//刷新状态
};