/*********************
*       初始化       *
*********************/
#include "Initial.h"

using namespace std;

void SetFps(int fps)//设置帧率
{
	window.setFramerateLimit(fps);
}

int LoadFont()//加载字体
{
	if (!font.loadFromFile("./resource/font/simsun.ttc"))
	{
		cout << "未成功加载字体文件。" << endl;
		return EXIT_FAILURE;
	}
	cout << "字体加载成功。" << endl;
	return EXIT_SUCCESS;
}

int LoadMusic()//加载音乐
{
	//加载菜单BGM
	if (!bgm[bgmType_Menu].openFromFile("./resource/audio/LuckyHammers_Onitama_Menu.wav"))
	{
		cout << "未成功加载LuckyHammers_Onitama_Menu.wav" << endl;
		return EXIT_FAILURE;
	}
	bgm[bgmType_Menu].setLoop(true);

	//加载BGM01
	if (!bgm[bgmType_01].openFromFile("./resource/audio/LuckyHammers_Onitama_Ingame Fantasy.wav"))
	{
		cout << "未成功加载LuckyHammers_Onitama_Ingame Fantasy.wav" << endl;
		return EXIT_FAILURE;
	}
	bgm[bgmType_01].setLoop(true);

	//加载BGM02
	if (!bgm[bgmType_02].openFromFile("./resource/audio/LuckyHammers_Onitama_Ingame Regular.wav"))
	{
		cout << "未成功加载LuckyHammers_Onitama_Ingame Regular.wav" << endl;
		return EXIT_FAILURE;
	}
	bgm[bgmType_02].setLoop(true);

	//加载BGM03
	if (!bgm[bgmType_03].openFromFile("./resource/audio/LuckyHammers_Onitama_Ingame SciFi.wav"))
	{
		cout << "未成功加载LuckyHammers_Onitama_Ingame SciFi.wav" << endl;
		return EXIT_FAILURE;
	}
	bgm[bgmType_03].setLoop(true);

	cout << "音乐加载成功。" << endl;


	//加载soundSelect
	if (!bufSelect.loadFromFile("./resource/audio/Onitama_Select.wav"))
	{
		cout << "未成功加载Onitama_Select.wav" << endl;
		return EXIT_FAILURE;
	}
	soundSelect.setBuffer(bufSelect);

	//加载soundVictory
	if (!bufVictory[0].loadFromFile("./resource/audio/Onitama_Victory_Fantasy.wav"))
	{
		cout << "未成功加载Onitama_Victory_Fantasy" << endl;
		return EXIT_FAILURE;
	}
	soundVictory[0].setBuffer(bufVictory[0]);
	if (!bufVictory[1].loadFromFile("./resource/audio/Onitama_Victory_Regular.wav"))
	{
		cout << "未成功加载Onitama_Victory_Regular.wav" << endl;
		return EXIT_FAILURE;
	}
	soundVictory[1].setBuffer(bufVictory[1]);
	if (!bufVictory[2].loadFromFile("./resource/audio/Onitama_Victory_SciFi.wav"))
	{
		cout << "未成功加载Onitama_Victory_SciFi.wav" << endl;
		return EXIT_FAILURE;
	}
	soundVictory[2].setBuffer(bufVictory[2]);

	//加载soundNewTurn
	if (!bufNewTurn.loadFromFile("./resource/audio/Onitama_New Turn.wav"))
	{
		cout << "未成功加载Onitama_New Turn.wav" << endl;
		return EXIT_FAILURE;
	}
	soundNewTurn.setBuffer(bufNewTurn);

	//加载soundStartGame
	if (!bufStartGame.loadFromFile("./resource/audio/Onitama_Start Game.wav"))
	{
		cout << "未成功加载Onitama_Start Game.wav" << endl;
		return EXIT_FAILURE;
	}
	soundStartGame.setBuffer(bufStartGame);

	//加载soundMove
	if (!bufMove.loadFromFile("./resource/audio/Onitama_Unit Movement.wav"))
	{
		cout << "未成功加载Onitama_Unit Movement.wav" << endl;
		return EXIT_FAILURE;
	}
	soundMove.setBuffer(bufMove);
	
	//加载soundEat
	if (!bufEat.loadFromFile("./resource/audio/Onitama_Tap Button.wav"))
	{
		cout << "未成功加载Onitama_Tap Button.wav" << endl;
		return EXIT_FAILURE;
	}
	soundEat.setBuffer(bufEat);

	cout << "音效加载成功。" << endl;
	return EXIT_SUCCESS;
}

int LoadSound()//加载音效
{

	cout << "音效加载成功。" << endl;
	return EXIT_SUCCESS;
}

int LoadTexture()//加载图片
{
	//加载Logo,RedWin,BlueWin
	if (!tLogo.loadFromFile("./resource/image/logo.png"))
	{
		cout << "未成功加载/logo.png" << endl;
		return EXIT_FAILURE;
	}
	sLogo.setTexture(tLogo);
	if (!tRedWin.loadFromFile("./resource/image/RedWin.png"))
	{
		cout << "未成功加载/RedWin.png" << endl;
		return EXIT_FAILURE;
	}
	sRedWin.setTexture(tRedWin);
	if (!tBlueWin.loadFromFile("./resource/image/BlueWin.png"))
	{
		cout << "未成功加载/BlueWin.png" << endl;
		return EXIT_FAILURE;
	}
	sBlueWin.setTexture(tBlueWin);

	//加载Background
	if (!tBackground.loadFromFile("./resource/image/background/background01.png"))
	{
		cout << "未成功加载/background/background01.png" << endl;
		return EXIT_FAILURE;
	}
	sBackground.setTexture(tBackground);

	//加载Chessboard
	if (!tChessboard.loadFromFile("./resource/image/chessboard/chessboard01.png"))
	{
		cout << "未成功加载/chessboard/chessboard01.png" << endl;
		return EXIT_FAILURE;
	}
	sChessboard.setTexture(tChessboard);

	//加载Piece
	if (!tPiece[0][0].loadFromFile("./resource/image/chess/Master0.png"))
	{
		cout << "未成功加载/chess/Master0.png" << endl;
		return EXIT_FAILURE;
	}
	if (!tPiece[1][0].loadFromFile("./resource/image/chess/Master1.png"))
	{
		cout << "未成功加载/chess/Master1.png" << endl;
		return EXIT_FAILURE;
	}
	if (!tPiece[0][1].loadFromFile("./resource/image/chess/Servant0.png"))
	{
		cout << "未成功加载/chess/Servant0.png" << endl;
		return EXIT_FAILURE;
	}
	if (!tPiece[1][1].loadFromFile("./resource/image/chess/Servant1.png"))
	{
		cout << "未成功加载/chess/Servant1.png" << endl;
		return EXIT_FAILURE;
	}

	//加载Mark
	if (!tMark[0].loadFromFile("./resource/image/chess/Mark0.png"))
	{
		cout << "未成功加载/chess/Mark0.png" << endl;
		return EXIT_FAILURE;
	}
	if (!tMark[1].loadFromFile("./resource/image/chess/Mark1.png"))
	{
		cout << "未成功加载/chess/Mark1.png" << endl;
		return EXIT_FAILURE;
	}
	if (!tMark[2].loadFromFile("./resource/image/card/selCard.png"))
	{
		cout << "未成功加载/card/selCard.png" << endl;
		return EXIT_FAILURE;
	}

	//加载Card
	char fileSource[64];
	for (int i = 0; i < MAX_CARD_NUM; i++)
	{
		sprintf_s(fileSource, "./resource/image/card/%d.png", i);
		if (!tCard[i].loadFromFile(fileSource))
		{
			cout << "未成功加载/card/" << i << ".png" << endl;
			return EXIT_FAILURE;
		}
	}

	cout << "图片加载成功。" << endl;
	return EXIT_SUCCESS;
}