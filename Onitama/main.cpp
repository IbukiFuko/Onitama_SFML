#include <iostream>
#include <string>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Value.h"		//全局变量
#include "Initial.h"	//初始化
#include "Scene.h"		//场景
#include "Image.h"		//按钮
#include "Card.h"

/***************************
待补充：
Card.cpp、Mark.cpp
修改位图当前大小和原大小信息

****************************/


using namespace std;

#pragma region Init
Image testButton;
Card card;
int i = 0;
int x = 0, y = 0;
#pragma endregion

#pragma region Function
int Init();		//初始化
int Event();		//事件响应
void DrawWindow();	//绘制窗体
void Update();		//主循环
#pragma endregion

int main()
{
	system("cls");
	while (window.isOpen())
	{
		Init();
		bgm[bgmType_Menu].play();
		while (window.isOpen())
		{
			if (Event() == 1)//事件响应
			{
				break;
			}
			Update();		//主循环
			DrawWindow();	//绘制窗体
		}
	}
	return 0;
}

int Init()//初始化
{
	GameOver = false;
	SetFps(FPS);//设置帧率
	LoadFont();//加载字体
	LoadMusic();//加载音乐
	LoadTexture();//加载图片
	testText = sf::Text("fps" + to_string(FPS), font, 50);
	testButton = Image(540, 360, 108 * 3, 72 * 3, 1080, 720, &tLogo, "TestStr", 50);
	return 0;
}

int Event()//事件响应
{
	while (window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)		//关闭窗口(如X键和Alt+F4)
			window.close();
		if (event.type == sf::Event::Resized) {}	//改变窗口大小
		if (event.type == sf::Event::LostFocus)		//窗口失去焦点
		{

		}	
		if (event.type == sf::Event::GainedFocus)	//窗口得到焦点
		{

		}	
		if (event.type == sf::Event::MouseMoved)
		{
			//testButton.SetPosition(sf::Mouse::getPosition(window).x * WindowWidth / window.getSize().x, sf::Mouse::getPosition(window).y * WindowHeight / window.getSize().y);
			//player1.setPosition(sf::Mouse::getPosition(window).x * WindowWidth / window.getSize().x - rectWidth / 2, player1.getPosition().y);
		}
	}
	if (!GameOver)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			testButton.SetPosition(x, y = y - 10);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			testButton.SetPosition(x, y = y +10);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			testButton.SetPosition(x = x- 10, y);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			testButton.SetPosition(x = x +10, y);
		}
	}
	else
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			return 1;
		}
	}
	return 0;
}

void Update()//主循环
{
	if (!GameOver)
	{
	}
}

void DrawWindow()//绘制窗体
{
	window.clear();//清屏, 
	testText = sf::Text("fps" + to_string(FPS) + "\tx: " + to_string(sf::Mouse::getPosition(window).x * WindowWidth / window.getSize().x) + "\ty: " + to_string(sf::Mouse::getPosition(window).y * WindowHeight / window.getSize().y), font, 20);
	testButton.Draw();
	window.draw(testText);
	window.display();//更新窗口
}
