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
	if (isPlayingAnimation || currentPlayer == mainPlayer)
		return;
	for (int k = 0; k < 5; k++)
	{
		if (!piece[currentPlayer][k]->Enable())
		{
			for (int l = 0; l < 4; l++)
			{
				Weights[k][0][l] = std::numeric_limits<int>::lowest();//棋子不可用，权重设置为最小
				Weights[k][1][l] = std::numeric_limits<int>::lowest();
			}
			continue;
		}
		for (int l = 2; l < 4; l++)
		{
			for(int m = 0;m < 4;m++)
				Weights[k][l - 2][m] = std::numeric_limits<int>::lowest();;//初始化权重
			selPiece = k;
			selCard  = l;
			//可移动位置
			int count = 1, sum = 0;
			for (int i = 1; i < 5; i++)
				image[i].SetPosition(-1000, -1000);
			if (selPiece > -1 && selCard > -1)//同时选中了卡片和棋子
			{
				//当前回合计算
				sum = card[playerCard[selCard]]->getAvailable(&available[0], &available[1], &available[2], &available[3]);
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
							Weights[k][l - 2][count - 1] = 0;
							if(selPiece == 0)
								Weights[k][l - 2][count - 1] -= 2;
							Weights[k][l - 2][count - 1] -= piece[associatePlayer][selPiece]->getPos().x;//优先后排
							if (imagePos[count].x < piece[associatePlayer][selPiece]->getPos().x)//优先前进
								Weights[k][l - 2][count - 1] -= 1;
							else
								Weights[k][l - 2][count - 1] += 1;
							if ((selPiece == 0 && imagePos[count] == MAIN_HOME) || imagePos[count] == piece[mainPlayer][0]->getPos())//胜利，高优先级
								Weights[k][l - 2][count - 1] += 1000000;
							for (int m = 1; m < 5; m++)
							{
								if (imagePos[count] == piece[mainPlayer][m]->getPos())//吃子，一般优先级
									Weights[k][l - 2][count - 1] += 10000;
							}
							count++;
						}
					}
				}
			}
			/**/
			//下一回合
			for (int o = 0; o < 5; o++)
			{
				if (!piece[mainPlayer][o]->Enable())
				{
					continue;
				}
				for (int p = 0; p < 2; p++)
				{
					selPiece = o;
					selCard = p;
					//可移动位置
					int count = 1, sum = 0;
					for (int i = 1; i < 5; i++)
						image[i].SetPosition(-1000, -1000);
					if (selPiece > -1 && selCard > -1)//同时选中了卡片和棋子
					{
						sum = card[playerCard[selCard]]->getAvailable(&available[0], &available[1], &available[2], &available[3]);
						for (int i = 0; i < sum; i++)
						{
							available[i].x += piece[mainPlayer][selPiece]->getPos().x;
							available[i].y += piece[mainPlayer][selPiece]->getPos().y;
							if (available[i].x >= 0 && available[i].x <= 4 && available[i].y >= 0 && available[i].y <= 4)
							{
								int j = 0;
								for (j = 0; j < 5; j++)
									if (piece[mainPlayer][j]->getPos() == available[i] && piece[mainPlayer][j]->Enable())
										break;
								if (j == 5)
								{
									image[count].SetPosition(sf::Vector2i(COORDINATE.x + available[i].y * SIZE.x, COORDINATE.y + available[i].x * SIZE.y));
									imagePos[count] = available[i];
									if ((selPiece == 0 && imagePos[count] == ASSOCIATE_HOME) )//胜利，高优先级
										Weights[o][l - 2][count - 1] -= 10000000;
									for (int m = 1; m < 5; m++)
									{
										if (imagePos[count] == piece[associatePlayer][m]->getPos())//吃子，一般优先级
											Weights[o][l - 2][count - 1] -= 1000;
									}
									if (imagePos[count] == piece[associatePlayer][0]->getPos())
									{
										for (int n = 0; n < 2; n++)
										{
											for (int h = 0; h < 4; h++)
											{
												Weights[0][n][h] += 10000000;
											}
										}
									}
									count++;
								}
							}
						}



					}
				}
			}
			/**/
		}
	}
	selPiece = -1;
	selCard  = -1;
	int max = std::numeric_limits<int>::lowest();
	//system("cls");
	for(int i = 0;i < 5;i++)
		for (int j = 0; j < 2; j++)
		{
			for (int k = 0; k < 4; k++)
			{
				if (Weights[i][j][k] > 2000000000)
					continue;
				//printf("Weight[%d][%d][%d]: %d\n", i, j, k, Weights[i][j][k]);
				if (Weights[i][j][k] > max)
				{
					selPiece = i;
					selCard = j + 2;
					max = Weights[i][j][k];
				}
				else if (Weights[i][j][k] == max)
				{
					if (rand() % 10 > 5)
					{
						selPiece = i;
						selCard = j + 2;
					}
				}
			}
		}
	//printf("max:%d\n", max);

	//可移动位置
	int count = 1, sum = 0;
	for (int i = 1; i < 5; i++)
		image[i].SetPosition(-1000, -1000);
	if (selPiece > -1 && selCard > -1)//同时选中了卡片和棋子
	{
		sum = card[playerCard[selCard]]->getAvailable(&available[0], &available[1], &available[2], &available[3]);
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

	//执行操作(目标位置为imagePos[0])
	if (selCard != -1 && selPiece != -1)
	{
		image[0].SetPosition(piece[currentPlayer][selPiece]->getCoordinate());//绘制棋子选中框
		image[5].SetPosition(card[playerCard[selCard]]->getPos());//绘制卡牌选中框
		//棋子操作
		piece[currentPlayer][selPiece]->Move(imagePos[1]);
		for (int j = 0; j < 5; j++)
			if (piece[currentPlayer == mainPlayer ? associatePlayer : mainPlayer][j]->getPos() == imagePos[1])
				piece[currentPlayer == mainPlayer ? associatePlayer : mainPlayer][j]->SetEnable(false, FPS);
		//卡片操作
		int tmpIndex = -1, tmpVal;
		for (int j = 0; j < 5; j++)//找到selCard对应的playerCard的下标
			if (card[playerCard[j]]->getID() == card[playerCard[selCard]]->getID())
			{
				tmpIndex = j;
				break;
			}
		//交换位置
		card[playerCard[tmpCard]]->SetPos(tmpIndex, true);
		card[playerCard[selCard]]->SetPos(tmpCard, true);
		tmpVal = playerCard[tmpIndex];
		playerCard[tmpIndex] = playerCard[tmpCard];
		playerCard[tmpCard] = tmpVal;


		Reset();
	}

}

int Bot::Draw()
{
	if (currentPlayer == mainPlayer)
	{
		return 0;
	}
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