/*********************
*       指示框       *
*********************/
#include "Bot.h"

Bot::Bot()
{

}

Bot::Bot(Piece *_0master, Piece *_0servant1, Piece *_0servant2, Piece *_0servant3, Piece *_0servant4,
	Piece *_1master, Piece *_1servant1, Piece *_1servant2, Piece *_1servant3, Piece *_1servant4,
	Card **_card)
{
	selPiece = -1, selCard = -1;
	time = 0;

	piece[0][0] = _0master;		//主玩家
	piece[0][1] = _0servant1;
	piece[0][2] = _0servant2;
	piece[0][3] = _0servant3;
	piece[0][4] = _0servant4;

	piece[1][0] = _1master;		//副玩家
	piece[1][1] = _1servant1;
	piece[1][2] = _1servant2;
	piece[1][3] = _1servant3;
	piece[1][4] = _1servant4;

	for (int i = 0; i < 5; i++)
		card[i] = _card[i];

	image[0] = Image(-1000, -1000, tSIZE_MARK0_X, tSIZE_MARK0_Y, SIZE_MARK0_X, SIZE_MARK0_Y, &tMark[0], "", 6);
	for (int i = 1; i < 5; i++)
		image[i] = Image(-1000, -1000, tSIZE_MARK1_X, tSIZE_MARK1_Y, SIZE_MARK1_X, SIZE_MARK1_Y, &tMark[1], "", 6);
	image[5] = Image(-1000, -1000, 142, 170, 142, 170, &tMark[2], "", 6);
}

void Bot::Update()
{
	time++;
	if (time == FPS * 2)
		time = FPS;
	if (selCard == -1)
		time = 0;
	//选中棋子
	for (int i = 0; i < 5; i++)
	{
		if (piece[currentPlayer][i]->getSelID() == piece[currentPlayer][i]->getID())
		{
			selPiece = i;
			break;
		}
		selPiece = -1;
	}
	if (selPiece > -1)
		image[0].SetPosition(piece[currentPlayer][selPiece]->getCoordinate());
	else
		image[0].SetPosition(-1000, -1000);
	//选中卡片
	for (int i = 0; i < 5; i++)
	{
		if (card[i]->getSelID() == card[i]->getID())
		{
			selCard = i;
			break;
		}
		selCard = -1;
	}
	if (selCard > -1)
	{
		image[5].SetPosition(card[selCard]->getPos());
	}
	else
		image[5].SetPosition(-1000, -1000);
	//可移动位置
	int count = 1, sum = 0;
	for (int i = 1; i < 5; i++)
		image[i].SetPosition(-1000, -1000);
	if (selPiece > -1 && selCard > -1)//同时选中了卡片和棋子
	{
		sum = card[selCard]->getAvailable(&available[0], &available[1], &available[2], &available[3]);
		for (int i = 0; i < sum; i++)
		{
			if (currentPlayer == associatePlayer)
				available[i] *= -1;
			available[i].x += piece[currentPlayer][selPiece]->getPos().x;
			available[i].y += piece[currentPlayer][selPiece]->getPos().y;
			if (available[i].x >= 0 && available[i].x <= 4 && available[i].y >= 0 && available[i].y <= 4)
			{
				int j = 0;
				for (j = 0; j < 5; j++)
					if (piece[currentPlayer][j]->getPos() == available[i] && piece[currentPlayer][j]->Enable())
						break;
				if (j == 5)
				{
					image[count].SetPosition(sf::Vector2i(COORDINATE.x + available[i].y * SIZE.x, COORDINATE.y + available[i].x * SIZE.y));
					imagePos[count] = available[i];
					count++;
				}
			}
		}
	}
	for (int i = 1; i < 5; i++)
	{
		if (image[i].isSelected())
		{
			if (mouseLeftPressed)
			{
				//棋子操作
				piece[currentPlayer][selPiece]->Move(imagePos[i]);
				for (int j = 0; j < 5; j++)
					if (piece[currentPlayer == mainPlayer ? associatePlayer : mainPlayer][j]->getPos() == imagePos[i])
						piece[currentPlayer == mainPlayer ? associatePlayer : mainPlayer][j]->SetEnable(false, FPS);
				//卡片操作
				int tmpIndex = -1, tmpVal;
				for (int j = 0; j < 5; j++)//找到selCard对应的playerCard的下标
					if (card[playerCard[j]]->getID() == card[selCard]->getID())
					{
						tmpIndex = j;
						break;
					}
				//交换位置
				card[playerCard[tmpCard]]->SetPos(tmpIndex, true);
				card[selCard]->SetPos(tmpCard, true);
				tmpVal = playerCard[tmpIndex];
				playerCard[tmpIndex] = playerCard[tmpCard];
				playerCard[tmpCard] = tmpVal;


				Reset();
				mouseLeftPressed = false;
				break;
			}
		}
	}
}

int Bot::Draw()
{
	for (int i = 0; i < 5; i++)
	{
		image[i].Draw();
	}
	if (time <= FPS * 9 / 5)//呼吸灯效果
		image[5].Draw();
	return 0;
}

void Bot::Reset()//重置状态
{
	Piece::Reset();
	Card::Reset();
}

void Bot::Refresh()//刷新状态
{

}