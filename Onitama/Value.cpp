/*********************
*      全局变量      *
*********************/
#include "Value.h"

const int WindowWidth = 1080, WindowHeight = 720;	//窗体大小
const int StageWidth = 1080, StageHeight = 720;		//舞台大小
const wchar_t* WindowName = L"Onitama（李琛承）";//窗体名称
const int FPS = 60;//帧率

sf::Vector2i COORDINATE = sf::Vector2i(0,0);//棋盘左下坐标
sf::Vector2i SIZE = sf::Vector2i(0,0);//棋盘格子像素大小

bool GameOver = false;

sf::RenderWindow window(sf::VideoMode(WindowWidth, WindowHeight), WindowName);//窗体
sf::Font font;//字体
sf::Event event;//事件

const int MaxPlayer = 2;//玩家最大数量
int currentPlayer = 0;//当前玩家

sf::Text testText;//测试文字

sf::Music bgm[4];//BGM（0-Menu; 1~3BGM）

sf::Texture tLogo, tBackground, tChessboard;
sf::Sprite sLogo, sBackground, sChessboard;
sf::Texture tPiece[2][2], tMark[2], tCard[MAX_CARD_NUM];
//sf::Sprite sPiece[2], sMark[2];
sf::Vector2i sizeLogo;
sf::Vector2i sizePiece[2];
sf::IntRect tmp;