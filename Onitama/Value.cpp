/*********************
*      全局变量      *
*********************/
#include "Value.h"

const int WindowWidth = 1080, WindowHeight = 720;	//窗体大小
const int StageWidth = 1080, StageHeight = 720;		//舞台大小
const wchar_t* WindowName = L"Onitama（李琛承）";//窗体名称
const int FPS = 60;//帧率

extern int objectID = 0;//object互斥id

extern int GameMode = pvp;//游戏方式
bool GameOver = false;
bool isPlayingAnimation = false;

sf::RenderWindow window(sf::VideoMode(WindowWidth, WindowHeight), WindowName);//窗体
sf::Font font;//字体
sf::Event event;//事件
sf::Vector2i mousePos;//鼠标位置

const int MaxPlayer = 2;//玩家最大数量
int currentPlayer = 0;//当前玩家
int winner = -1;
int playerCard[5];//卡牌

sf::Text testText;//测试文字

sf::Music bgm[4];//BGM（0-Menu; 1~3BGM）
sf::SoundBuffer bufSelect, bufVictory[3], bufNewTurn, bufStartGame, bufMove, bufEat;
sf::Sound soundSelect, soundVictory[3], soundNewTurn, soundStartGame, soundMove, soundEat;

sf::Texture tLogo, tRedWin, tBlueWin, tBackground, tChessboard;
sf::Sprite sLogo, sRedWin, sBlueWin, sBackground, sChessboard;
sf::Texture tPiece[2][2], tMark[3], tCard[MAX_CARD_NUM];
sf::Sprite sPiece[2][2], sMark[2];
sf::Vector2i sizeLogo;
sf::IntRect tmp;

bool mouseLeftPressed = false;//鼠标左键按下
bool spacePressed = false;//空格按下

void resetEvent()
{
	mouseLeftPressed = false;
	spacePressed = false;
}