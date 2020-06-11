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
#include "Object.h"

class Scene//场景
{
private:
	int ID;//场景ID
	int bgmType;//场景背景音乐

#pragma region Initial
	int Initial_Scene_MainMenu();
	int Initial_Scene_Battle();
	int Initial_Scene_Menu();
#pragma endregion


#pragma region Load
	int Load_Scene_MainMenu();
	int Load_Scene_Battle();
	int Load_Scene_Menu();
	int Load_Scene_Win();
#pragma endregion

#pragma region Unload
	int Unload_Scene_MainMenu();
	int Unload_Scene_Battle();
	int Unload_Scene_Menu();
	int Unload_Scene_Win();
#pragma endregion

#pragma region Update
	int Update_Scene_MainMenu();
	int Update_Scene_Battle();
	int Update_Scene_Menu();
	int Update_Scene_Win();
#pragma endregion

#pragma region Draw
	int Draw_Scene_MainMenu();
	int Draw_Scene_Battle();
	int Draw_Scene_Menu();
	int Draw_Scene_Win();
#pragma endregion


public:
	Scene();
	Scene(int );
	int Load();//加载场景
	int Unload();//卸载场景
	int Update();//场景逻辑
	int Draw();//场景绘制
	int Restart();//重新开始
};