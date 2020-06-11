/*********************
*        ≥°æ∞        *
*********************/
#pragma once
#include <iostream>
#include <string>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Value.h"
#include "Object.h"

class Scene//≥°æ∞
{
private:
	int ID;//≥°æ∞ID
	int bgmType;//≥°æ∞±≥æ∞“Ù¿÷

#pragma region Initial
	int Initial_Scene_MainMenu();
	int Initial_Scene_Battle();
	int Initial_Scene_Menu();
#pragma endregion


#pragma region Load
	int Load_Scene_MainMenu();
	int Load_Scene_Battle();
	int Load_Scene_Menu();

#pragma endregion

#pragma region Unload
	int Unload_Scene_MainMenu();
	int Unload_Scene_Battle();
	int Unload_Scene_Menu();

#pragma endregion

#pragma region Update
	int Update_Scene_MainMenu();
	int Update_Scene_Battle();
	int Update_Scene_Menu();

#pragma endregion

#pragma region Draw
	int Draw_Scene_MainMenu();
	int Draw_Scene_Battle();
	int Draw_Scene_Menu();

#pragma endregion


public:
	Scene();
	Scene(int );
	int Load();//º”‘ÿ≥°æ∞
	int Unload();//–∂‘ÿ≥°æ∞
	int Update();//≥°æ∞¬ﬂº≠
	int Draw();//≥°æ∞ªÊ÷∆
};