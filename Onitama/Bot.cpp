/*********************
*       指示框       *
*********************/
#include "Bot.h"

Bot::Bot()
{

}

Bot::Bot(int _player, Piece *_0master, Piece *_0servant1, Piece *_0servant2, Piece *_0servant3, Piece *_0servant4,
	Piece *_1master, Piece *_1servant1, Piece *_1servant2, Piece *_1servant3, Piece *_1servant4,
	Card **_card)
{
	player = _player;
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
	int max = std::numeric_limits<int>::lowest();
	int val = -1;
	time++;
	if (time == FPS * 2)
		time = FPS;
	if (selCard == -1)
		time = 0;
	if (isPlayingAnimation || currentPlayer != player)
		return;
	for (int k = 0; k < 5; k++)
	{
		if (!piece[player][k]->Enable())
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
			if (player == mainPlayer)
				selCard -= 2;
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
							if(player == associatePlayer)
								Weights[k][l - 2][count - 1] -= piece[player][selPiece]->getPos().x;//优先后排
							else
								Weights[k][l - 2][count - 1] += piece[player][selPiece]->getPos().x;//优先后排
							if (imagePos[count].x < piece[player == mainPlayer ? associatePlayer : mainPlayer][0]->getPos().x)//优先前进
							{
								if(player == associatePlayer)
									Weights[k][l - 2][count - 1] -= 5;
								else
									Weights[k][l - 2][count - 1] += 5;
							}
							else
							{
								if (player == associatePlayer)
									Weights[k][l - 2][count - 1] += 5;
								else
									Weights[k][l - 2][count - 1] -= 5;
							}
							if ((selPiece == 0 && player == associatePlayer ? (imagePos[count] == MAIN_HOME) : (imagePos[count] == ASSOCIATE_HOME)) || imagePos[count] == piece[player == mainPlayer ? associatePlayer : mainPlayer][0]->getPos())//胜利，高优先级
							{
								Weights[k][l - 2][count - 1] += 10000000;
								selPiece = k;
								selCard = l;
								val = count;
								if (player == mainPlayer)
									selCard -= 2;
								goto Label;
							}
							for (int m = 1; m < 5; m++)
							{
								if (imagePos[count] == piece[player == mainPlayer ? associatePlayer : mainPlayer][m]->getPos())//吃子，一般优先级
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
				if (!piece[player == mainPlayer ? associatePlayer : mainPlayer][o]->Enable())
				{
					continue;
				}
				for (int p = 0; p < 2; p++)
				{
					selPiece = o;
					selCard = p;
					if (player == mainPlayer)
						selCard += 2;
					//可移动位置
					int count = 1, sum = 0;
					for (int i = 1; i < 5; i++)
						image[i].SetPosition(-1000, -1000);
					if (selPiece > -1 && selCard > -1)//同时选中了卡片和棋子
					{
						sum = card[playerCard[selCard]]->getAvailable(&available[0], &available[1], &available[2], &available[3]);
						for (int i = 0; i < sum; i++)
						{
							if ((player == mainPlayer ? associatePlayer : mainPlayer) == associatePlayer)
								available[i] *= -1;
							available[i].x += piece[player == mainPlayer ? associatePlayer : mainPlayer][selPiece]->getPos().x;
							available[i].y += piece[player == mainPlayer ? associatePlayer : mainPlayer][selPiece]->getPos().y;
							if (available[i].x >= 0 && available[i].x <= 4 && available[i].y >= 0 && available[i].y <= 4)
							{
								int j = 0;
								for (j = 0; j < 5; j++)
									if (piece[player == mainPlayer ? associatePlayer : mainPlayer][j]->getPos() == available[i] && piece[player == mainPlayer ? associatePlayer : mainPlayer][j]->Enable())
										break;
								if (j == 5)
								{
									image[count].SetPosition(sf::Vector2i(COORDINATE.x + available[i].y * SIZE.x, COORDINATE.y + available[i].x * SIZE.y));
									imagePos[count] = available[i];
									if ((selPiece == 0 && imagePos[count] == ASSOCIATE_HOME))//胜利，高优先级
										Weights[o][l - 2][count - 1] -= 10000000;
									for (int m = 1; m < 5; m++)
									{
										if (imagePos[count] == piece[player][m]->getPos())//吃子，一般优先级
											Weights[o][l - 2][count - 1] -= 1000;
									}
									if (imagePos[count] == piece[player][0]->getPos())
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
					if (player == mainPlayer)
						selCard -= 2;
					val = k + 1;
					max = Weights[i][j][k];
				}
				else if (Weights[i][j][k] == max)
				{
					if (rand() % 10 > 7)
					{
						selPiece = i;
						selCard = j + 2;
						if (player == mainPlayer)
							selCard -= 2;
						val = k + 1;
					}
				}
			}
		}
	//printf("max:%d\n", max);

Label:
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
	imagePos[0] = imagePos[val];
	//执行操作(目标位置为imagePos[0])
	if (selCard != -1 && selPiece != -1)
	{
		image[0].SetPosition(piece[currentPlayer][selPiece]->getCoordinate());//绘制棋子选中框
		image[5].SetPosition(card[playerCard[selCard]]->getPos());//绘制卡牌选中框
		//棋子操作
		piece[currentPlayer][selPiece]->Move(imagePos[0]);
		for (int j = 0; j < 5; j++)
			if (piece[currentPlayer == mainPlayer ? associatePlayer : mainPlayer][j]->getPos() == imagePos[0])
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
	if (currentPlayer != player)
	{
		return 0;
	}
	for (int i = 0; i < 5; i++)
	{
		image[i].Draw();
	}
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