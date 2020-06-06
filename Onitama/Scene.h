/*********************
*        场景        *
*********************/
#pragma once
#include <iostream>
#include <string>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Value.h"

class Scene//场景
{
private:
	int ID;//场景ID
	int bgmType;
	bool active;
public:
	int Save();//缓存
#pragma region Save
	int Save_Scene_MainMenu();
	int Save_Scene_Battle();
	int Save_Scene_Menu();

#pragma endregion

	int Load();//读取缓存
#pragma region Load
	int Load_Scene_MainMenu();
	int Load_Scene_Battle();
	int Load_Scene_Menu();

#pragma endregion

	int Event();//场景对应的事件响应
#pragma region Event
	int Event_Scene_MainMenu();
	int Event_Scene_Battle();
	int Event_Scene_Menu();

#pragma endregion

	int Draw();//场景绘制
#pragma region Event
	int Draw_Scene_MainMenu();
	int Draw_Scene_Battle();
	int Draw_Scene_Menu();

#pragma endregion
};

int LoadScene(Scene);//加载场景

void Scene_clean();