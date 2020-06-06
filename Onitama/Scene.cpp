/*********************
*        ³¡¾°        *
*********************/
#include "Scene.h"

int Scene::Save()
{
	if (!active)
		return -1;
	bgm[bgmType].stop();
	switch (ID)
	{
	case scene_mainMenu:
		Save_Scene_MainMenu();
		break;
	case scene_battle:
		Save_Scene_Battle();
		break;
	case scene_menu:
		Save_Scene_Menu();
		break;
	default:
		break;
	}
	return 0;
}

int Scene::Load()
{
	bgm[bgmType].play();
	switch (ID)
	{
	case scene_mainMenu:
		Load_Scene_MainMenu();
		break;
	case scene_battle:
		Load_Scene_Battle();
		break;
	case scene_menu:
		Load_Scene_Menu();
		break;
	default:
		break;
	}
	return 0;
}

int Scene::Event()
{
	switch (ID)
	{
	case scene_mainMenu:
		Event_Scene_MainMenu();
		break;
	case scene_battle:
		Event_Scene_Battle();
		break;
	case scene_menu:
		Event_Scene_Menu();
		break;
	default:
		break;
	}
	return 0;
}

int Scene::Draw()
{
	switch (ID)
	{
	case scene_mainMenu:
		Draw_Scene_MainMenu();
		break;
	case scene_battle:
		Draw_Scene_Battle();
		break;
	case scene_menu:
		Draw_Scene_Menu();
		break;
	default:
		break;
	}
	return 0;
}

#pragma region Save
int Scene::Save_Scene_MainMenu()
{

	return 0;
}

int Scene::Save_Scene_Battle()
{
	return 0;
}

int Scene::Save_Scene_Menu()
{
	return 0;
}

#pragma endregion

#pragma region Load
int Scene::Load_Scene_MainMenu()
{
	return 0;
}

int Scene::Load_Scene_Battle()
{
	return 0;
}

int Scene::Load_Scene_Menu()
{
	return 0;
}

#pragma endregion

#pragma region Event
int Scene::Event_Scene_MainMenu()
{
	return 0;
}

int Scene::Event_Scene_Battle()
{
	return 0;
}

int Scene::Event_Scene_Menu()
{
	return 0;
}

#pragma endregion

#pragma region Draw
int Scene::Draw_Scene_MainMenu()
{
	window.draw(sLogo);//»æÖÆLogo±³¾°

	return 0;
}

int Scene::Draw_Scene_Battle()
{
	return 0;
}

int Scene::Draw_Scene_Menu()
{
	return 0;
}

#pragma endregion

void Scene_clean()
{
	//ÔİÊ±Çå³ı»­Ãæ£¬±£ÁôÒ³Ãæ»º´æ
	//ÔİÍ£ËùÓĞÒôÀÖ£¬±£ÁôÒ³Ãæ»º´æ
	//ÇĞ»»EventÏìÓ¦
}
