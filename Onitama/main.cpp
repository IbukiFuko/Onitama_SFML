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
	scene = Scene(scene_mainMenu);
	while (window.isOpen())
	{
		while (window.isOpen())
		{
			resetEvent();//重置事件
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
			mousePos.x = sf::Mouse::getPosition(window).x * WindowWidth / window.getSize().x;
			mousePos.y = sf::Mouse::getPosition(window).y * WindowHeight / window.getSize().y;
		}
		if (event.type == sf::Event::MouseButtonPressed && sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			mouseLeftPressed = true;
		}
		if (event.type == sf::Event::KeyPressed && sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		{
			spacePressed = true;
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
	window.clear();//清屏
	scene.Draw();//绘制当前场景

	testText = sf::Text("fps" + to_string(FPS) + "\tx: " + to_string(mousePos.x) + "\ty: " + to_string(mousePos.y), font, 20);
	//testButton.Draw();
	//window.draw(testText);
	window.display();//更新窗口
}
