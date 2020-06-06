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
	return EXIT_SUCCESS;
}

int LoadSound()//加载音效
{

	cout << "音效加载成功。" << endl;
	return EXIT_SUCCESS;
}

int LoadTexture()//加载图片
{
	//加载Logo
	if (!tLogo.loadFromFile("./resource/image/logo.png"))
	{
		cout << "未成功加载/logo.png" << endl;
		return EXIT_FAILURE;
	}
	sLogo.setTexture(tLogo);

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