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
	Load();
}

#pragma region Initial
int Scene::Initial_Scene_MainMenu()
{
	bgmType = bgmType_Menu;
	startButton[0] = Image(930, 540, 200, 60, 1080, 720, &tBackground, "PVP", 50);
	startButton[1] = Image(930, 610, 200, 60, 1080, 720, &tBackground, "PVE", 50);
	startButton[2] = Image(930, 680, 200, 60, 1080, 720, &tBackground, "EVE", 50);
	return 0;
}

int Scene::Initial_Scene_Battle()
{
	bgmType = rand() % 3 + 1;
	bgm[bgmType].stop();
	currentPlayer = rand() % 2;
	if (currentPlayer == mainPlayer)
		printf("\n红方先!");
	else
		printf("\n蓝方先!");
	GameOver = false;
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
	

	free(mark);
	mark = new Mark(piece[0][0], piece[0][1], piece[0][2], piece[0][3], piece[0][4],
		piece[1][0], piece[1][1], piece[1][2], piece[1][3], piece[1][4], card);

	free(bot);
	bot = new Bot(associatePlayer, piece[0][0], piece[0][1], piece[0][2], piece[0][3], piece[0][4],
		piece[1][0], piece[1][1], piece[1][2], piece[1][3], piece[1][4], card);
	free(bot2);
	bot2 = new Bot(mainPlayer, piece[0][0], piece[0][1], piece[0][2], piece[0][3], piece[0][4],
		piece[1][0], piece[1][1], piece[1][2], piece[1][3], piece[1][4], card);

	menuButton = Image(1000, 50, 120, 50, 1080, 720, &tBackground, "Menu", 30);

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
	case scene_win:
		Unload_Scene_Win();
		break;
	default:
		break;
	}
	return 0;
}

int Scene::Load()
{
	window.setTitle(L"Onitama（李琛承）");
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
	case scene_win:
		Load_Scene_Win();
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
	case scene_win:
		Update_Scene_Win();
		break;
	default:
		break;
	}
	/*
	if (spacePressed)//作弊按键
	{
		spacePressed = false;
		Mark::Reset();
		currentPlayer = currentPlayer == mainPlayer ? associatePlayer : mainPlayer;
	}
	/**/
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
	case scene_win:
		Draw_Scene_Win();
		break;
	default:
		break;
	}
	return 0;
}

#pragma region Load
int Scene::Load_Scene_MainMenu()
{
	window.setTitle(L"Onitama（李琛承）");
	ID = scene_mainMenu;
	bgmType = bgmType_Menu;
	bgm[bgmType].stop();
	bgm[bgmType].play();
	return 0;
}

int Scene::Load_Scene_Battle()
{
	ID = scene_battle;
	bgmType = rand() % 3 + 1;
	bgm[bgmType].play();
	return 0;
}

int Scene::Load_Scene_Menu()
{
	ID = scene_menu;
	bgmType = bgmType_Menu;
	bgm[bgmType].stop();
	bgm[bgmType].play();
	return 0;
}

int Scene::Load_Scene_Win()
{
	ID = scene_win;
	int tmp = rand() % 3;
	soundVictory[tmp].play();
	menuButton = Image(900, 650, 250, 70, 1080, 720, &tBackground, "Main Menu", 40);
	return 0;
}

#pragma endregion

#pragma region Unload
int Scene::Unload_Scene_MainMenu()
{
	bgm[bgmType].pause();
	return 0;
}

int Scene::Unload_Scene_Battle()
{
	bgm[bgmType].pause();
	return 0;
}

int Scene::Unload_Scene_Menu()
{
	bgm[bgmType].pause();
	return 0;
}

int Scene::Unload_Scene_Win()
{
	return 0;
}

#pragma endregion

#pragma region Update
int Scene::Update_Scene_MainMenu()
{
	for(int i = 0;i < 3;i++)
		if (startButton[i].isSelected())
		{
			startButton[i].SetColor(sf::Color(255, 255, 55, 255));
			if (mouseLeftPressed)
			{
				soundStartGame.play();
				GameMode = i;
				Unload();
				Initial_Scene_Battle();
				Load_Scene_Battle();
				mouseLeftPressed = false;
			}
		}
		else
		{
			startButton[i].SetColor(sf::Color(255, 255, 255, 255));
		}
	return 0;
}

int Scene::Update_Scene_Battle()
{
	//菜单按钮
	if (!isPlayingAnimation && menuButton.isSelected())
	{
		menuButton.SetColor(sf::Color(255, 255, 55, 255));
		if (mouseLeftPressed)
		{
			Unload();
			ID = scene_mainMenu;
			Load_Scene_MainMenu();
			mouseLeftPressed = false;
		}
	}
	else
	{
		menuButton.SetColor(sf::Color(255, 255, 255, 255));
	}

	if (!GameOver)
	{
		if (!isPlayingAnimation && (!piece[mainPlayer][0]->Enable() || piece[associatePlayer][0]->getPos() == MAIN_HOME))
		{
			printf("\n蓝方胜利！");
			winner = associatePlayer;
			Unload();
			Load_Scene_Win();
			GameOver = true;
			return 0;
		}
		else if (!isPlayingAnimation && (!piece[associatePlayer][0]->Enable() || piece[mainPlayer][0]->getPos() == ASSOCIATE_HOME))
		{
			printf("\n红方胜利！");
			winner = mainPlayer;
			Unload();
			Load_Scene_Win();
			GameOver = true;
			return 0;
		}
	}
	else
	{
		return 0;
	}

	if (GameMode == pvp)			//单机双人对弈
	{
		for (int i = 0; i < 2; i++)
			for (int j = 0; j < 5; j++)
				piece[i][j]->Update();
		for (int i = 0; i < 5; i++)
			card[i]->Update();
		mark->Update();
	}
	else if (GameMode == pve)		//人机对弈
	{
		for (int i = 0; i < 2; i++)
			for (int j = 0; j < 5; j++)
				piece[i][j]->Update();
		for (int i = 0; i < 5; i++)
			card[i]->Update();
		if (currentPlayer == mainPlayer)
		{
			mark->Update();
		}
		else if(currentPlayer == associatePlayer)
		{
			if(!(!isPlayingAnimation && (!piece[mainPlayer][0]->Enable() || piece[associatePlayer][0]->getPos() == MAIN_HOME)||
				!isPlayingAnimation && (!piece[associatePlayer][0]->Enable() || piece[mainPlayer][0]->getPos() == ASSOCIATE_HOME)))
				bot->Update();
		}
	}
	else if (GameMode == eve)	//双人机对弈
	{
		for (int i = 0; i < 2; i++)
			for (int j = 0; j < 5; j++)
				piece[i][j]->Update();
		for (int i = 0; i < 5; i++)
			card[i]->Update();
		if (currentPlayer == mainPlayer)
		{
			if (!(!isPlayingAnimation && (!piece[mainPlayer][0]->Enable() || piece[associatePlayer][0]->getPos() == MAIN_HOME) ||
				!isPlayingAnimation && (!piece[associatePlayer][0]->Enable() || piece[mainPlayer][0]->getPos() == ASSOCIATE_HOME)))
				bot2->Update();
		}
		else if (currentPlayer == associatePlayer)
		{
			if (!(!isPlayingAnimation && (!piece[mainPlayer][0]->Enable() || piece[associatePlayer][0]->getPos() == MAIN_HOME) ||
				!isPlayingAnimation && (!piece[associatePlayer][0]->Enable() || piece[mainPlayer][0]->getPos() == ASSOCIATE_HOME)))
				bot->Update();
		}
	}
	if (currentPlayer == mainPlayer)
	{
		window.setTitle(L"Onitama（李琛承）--红方回合");
	}
	else
	{
		window.setTitle(L"Onitama（李琛承）--蓝方回合");
	}

	return 0;
}

int Scene::Update_Scene_Menu()
{
	return 0;
}

int Scene::Update_Scene_Win()
{
	//菜单按钮
	if (menuButton.isSelected())
	{
		menuButton.SetColor(sf::Color(255, 255, 55, 255));
		if (mouseLeftPressed)
		{
			Unload();
			Load_Scene_MainMenu();
			mouseLeftPressed = false;
		}
	}
	else
	{
		menuButton.SetColor(sf::Color(255, 255, 255, 255));
	}
	return 0;
}

#pragma endregion

#pragma region Draw
int Scene::Draw_Scene_MainMenu()
{
	window.draw(sLogo);//绘制Logo背景
	for(int i = 0;i < 3;i++)
		startButton[i].Draw();
	return 0;
}

int Scene::Draw_Scene_Battle()
{
	window.draw(sBackground);
	window.draw(sChessboard);

	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 5; j++)
			if (piece[i][j]->Enable() && !piece[i][j]->isPlaying)
				piece[i][j]->Draw();

	for (int i = 0; i < 5; i++)
		card[i]->Draw();

	if(GameMode == pvp)
		mark->Draw();
	else if (GameMode == pve)
	{
		mark->Draw();
		bot->Draw();
	}
	else if (GameMode == eve)
	{
		bot->Draw();
		bot2->Draw();
	}

	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 5; j++)
			if (piece[i][j]->Enable() && piece[i][j]->isPlaying)
				piece[i][j]->Draw();

	menuButton.Draw();
	
	return 0;
}

int Scene::Draw_Scene_Menu()
{
	return 0;
}

int Scene::Draw_Scene_Win()
{
	switch (winner)
	{
	case mainPlayer:
		window.setTitle(L"Onitama（李琛承）--红方胜");
		window.draw(sRedWin);
		break;
	case associatePlayer:
		window.setTitle(L"Onitama（李琛承）--蓝方胜");
		window.draw(sBlueWin);
		break;
	default:
		break;
	}
	menuButton.Draw();
	return 0;
}

#pragma endregion

int Scene::Restart()
{
	bgm[bgmType].stop();
	Initial_Scene_Battle();
	return 0;
}