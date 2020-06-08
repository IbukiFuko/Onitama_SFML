#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Value.h"		//全局变量
#include "Initial.h"	//初始化
#include "Scene.h"
#include "Object.h"

/***************************
待补充：
Card.cpp、Mark.cpp
修改位图当前大小和原大小信息
Object.cpp
初始场景指针位置

****************************/

using namespace std;

#pragma region Init
Scene scene;
int i = 0;
int x = 0, y = 0;
#pragma endregion

#pragma region Function
int Init();		//初始化
int Event();		//事件响应
void DrawWindow();	//绘制窗体
#pragma endregion

int main()
{
	system("cls");
	srand((int)time(NULL));//设置随机数种子
	Init();
	scene = Scene(scene_battle);
	while (window.isOpen())
	{
		while (window.isOpen())
		{
			if (Event() == 1)//事件响应
			{
				break;
			}
			scene.Update();
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

void DrawWindow()//绘制窗体
{
	window.clear();//清屏, 
	scene.Draw();//绘制当前场景

	testText = sf::Text("fps" + to_string(FPS) + "\tx: " + to_string(sf::Mouse::getPosition(window).x * WindowWidth / window.getSize().x) + "\ty: " + to_string(sf::Mouse::getPosition(window).y * WindowHeight / window.getSize().y)
		, font, 20);
	//testButton.Draw();
	window.draw(testText);
	window.display();//更新窗口
}
