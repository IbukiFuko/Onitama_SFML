/*********************
*        场景        *
*********************/
#include "Scene.h"

Scene::Scene()
{

}

Scene::Scene(int _ID)
{
	ID = _ID;
	switch (ID)
	{
	case scene_mainMenu:
		Initial_Scene_MainMenu();
		break;
	case scene_battle:
		Initial_Scene_Battle();
		break;
	case scene_menu:
		Initial_Scene_Menu();
		break;
	default:
		break;
	}
}

#pragma region Initial
int Scene::Initial_Scene_MainMenu()
{
	bgmType = bgmType_Menu;
	return 0;
}

int Scene::Initial_Scene_Battle()
{
	bgmType = rand() % 3 + 1;
	bgm[bgmType].play();
	currentPlayer = mainPlayer;
	for(int i = 0;i < 2;i++)
		for(int j = 0;j < 5;j++)
			free(piece[i][j]);
	piece[0][0] = new Piece(0, true, sf::Vector2i(4, 2));
	piece[1][0] = new Piece(0, false, sf::Vector2i(0, 2));
	piece[0][1] = new Piece(1, true, sf::Vector2i(4, 0));
	piece[0][2] = new Piece(1, true, sf::Vector2i(4, 1)); 
	piece[0][3] = new Piece(1, true, sf::Vector2i(4, 3));
	piece[0][4] = new Piece(1, true, sf::Vector2i(4, 4));
	piece[1][1] = new Piece(1, false, sf::Vector2i(0, 0));
	piece[1][2] = new Piece(1, false, sf::Vector2i(0, 1));
	piece[1][3] = new Piece(1, false, sf::Vector2i(0, 3));
	piece[1][4] = new Piece(1, false, sf::Vector2i(0, 4));

	free(mark);
	mark = new Mark(piece[0][0], piece[0][1], piece[0][2], piece[0][3], piece[0][4],
					piece[1][0], piece[1][1], piece[1][2], piece[1][3], piece[1][4]);

	int tmp[16] = { 0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15 };
	int randomNum, tmpNum;
	for (int i = 15; i > 0; i--)
	{
		randomNum = rand() % (i + 1);
		tmpNum = tmp[i];
		tmp[i] = tmp[randomNum];
		tmp[randomNum] = tmpNum;
	}
	for (int i = 0; i < 5; i++)
	{
		free(card[i]);
		card[i] = new Card(tmp[i]);
		card[i]->SetPos(i, false);//设置画面坐标
		playerCard[i] = i;//分配玩家手牌
	}
	

	return 0;
}

int Scene::Initial_Scene_Menu()
{
	bgmType = bgmType_Menu;
	return 0;
}
#pragma endregion

int Scene::Unload()
{
	bgm[bgmType].pause();
	switch (ID)
	{
	case scene_mainMenu:
		Unload_Scene_MainMenu();
		break;
	case scene_battle:
		Unload_Scene_Battle();
		break;
	case scene_menu:
		Unload_Scene_Menu();
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

int Scene::Update()
{
	switch (ID)
	{
	case scene_mainMenu:
		Update_Scene_MainMenu();
		break;
	case scene_battle:
		Update_Scene_Battle();
		break;
	case scene_menu:
		Update_Scene_Menu();
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

#pragma region Unload
int Scene::Unload_Scene_MainMenu()
{

	return 0;
}

int Scene::Unload_Scene_Battle()
{
	return 0;
}

int Scene::Unload_Scene_Menu()
{
	return 0;
}

#pragma endregion

#pragma region Update
int Scene::Update_Scene_MainMenu()
{
	return 0;
}

int Scene::Update_Scene_Battle()
{
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 5; j++)
			piece[i][j]->Update();
	mark->Update();
	for (int i = 0; i < 5; i++)
		card[i]->Update();
	return 0;
}

int Scene::Update_Scene_Menu()
{
	return 0;
}

#pragma endregion

#pragma region Draw
int Scene::Draw_Scene_MainMenu()
{
	window.draw(sLogo);//绘制Logo背景

	return 0;
}

int Scene::Draw_Scene_Battle()
{
	window.draw(sBackground);
	window.draw(sChessboard);
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 5; j++)
			if (piece[i][j]->Enable())
				piece[i][j]->Draw();
	mark->Draw();
	for (int i = 0; i < 5; i++)
		card[i]->Draw();
	return 0;
}

int Scene::Draw_Scene_Menu()
{
	return 0;
}

#pragma endregion