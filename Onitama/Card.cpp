/*********************
*        卡片        *
*********************/
#include "Card.h"

int Card::selID = -1;

Card::Card()
{
	type = 0;
	image = Image(-1000, -1000, 141, 170, 141, 170, &tCard[0], "", 6);
	SetAvailable();//设置卡片可移动偏移
}

Card::Card(int _type)
{
	ID = objectID++;
	type = _type;
	player = 0;
	deltaRotation = 0;
	image = Image(-100, -100, 141, 170, 141, 170, &tCard[_type], "", 6);
	SetAvailable();//设置卡片可移动偏移
}

int Card::SetAvailable()//设置卡片可移动偏移
{
	//清空数据
	for (int i = 0; i < CARD_MAX_Y; i++)
		for (int j = 0; j < CARD_MAX_X; j++)
			available[i][j] = false;
	//设定可移动位置
	switch (type)
	{
	case 0:
		available[1][1] = true;
		available[2][1] = true;
		available[2][3] = true;
		available[3][3] = true;
		break;
	case 1:
		available[1][2] = true;
		available[3][1] = true;
		available[3][3] = true;
		break;
	case 2:
		available[0][2] = true;
		available[3][2] = true;
		break;
	case 3:
		available[1][3] = true;
		available[2][1] = true;
		available[2][3] = true;
		available[3][1] = true;
		break;
	case 4:
		available[1][0] = true;
		available[1][4] = true;
		available[3][1] = true;
		available[3][3] = true;
		break;
	case 5:
		available[1][2] = true;
		available[2][1] = true;
		available[3][2] = true;
		break;
	case 6:
		available[1][1] = true;
		available[2][3] = true;
		available[3][1] = true;
		break;
	case 7:
		available[1][2] = true;
		available[2][3] = true;
		available[3][2] = true;
		break;
	case 8:
		available[1][1] = true;
		available[1][3] = true;
		available[3][2] = true;
		break;
	case 9:
		available[1][3] = true;
		available[2][4] = true;
		available[3][1] = true;
		break;
	case 10:
		available[1][1] = true;
		available[2][0] = true;
		available[3][3] = true;
		break;
	case 11:
		available[1][1] = true;
		available[1][3] = true;
		available[2][1] = true;
		available[2][3] = true;
		break;
	case 12:
		available[1][2] = true;
		available[2][0] = true;
		available[2][4] = true;
		break;
	case 13:
		available[1][3] = true;
		available[2][1] = true;
		available[3][3] = true;
		break;
	case 14:
		available[1][1] = true;
		available[1][3] = true;
		available[3][1] = true;
		available[3][3] = true;
		break;
	case 15:
		available[1][2] = true;
		available[2][1] = true;
		available[2][3] = true;
		break;
	default:
		break;
	}
	return 0;
}

void Card::SetPos(int _cardID, bool isPlay)
{
	if(isPlay)
	{
		step = 60;
		switch (_cardID)//设置目标位置
		{
		case mainCard0:
			targetPos = sf::Vector2i(820, 600);
			player = 0;
			break;
		case mainCard1:
			targetPos = sf::Vector2i(980, 600);
			player = 0;
			break;
		case associateCard0:
			targetPos = sf::Vector2i(820, 200);
			player = 1;
			break;
		case associateCard1:
			targetPos = sf::Vector2i(980, 200);
			player = 1;
			break;
		case tmpCard:
			targetPos = sf::Vector2i(900, 400);
			player = 2;
			deltaRotation += 180;
			break;
		default:
			break;
		}
	}
	else
	{
		step = 0;
		switch (_cardID)//设置目标位置
		{
		case mainCard0:
			targetPos = sf::Vector2i(820, 600);
			player = 0;
			image.SetRotation(0);
			break;
		case mainCard1:
			targetPos = sf::Vector2i(980, 600);
			player = 0;
			image.SetRotation(0);
			break;
		case associateCard0:
			targetPos = sf::Vector2i(820, 200);
			player = 1;
			image.SetRotation(180);
			break;
		case associateCard1:
			targetPos = sf::Vector2i(980, 200);
			player = 1;
			image.SetRotation(180);
			break;
		case tmpCard:
			targetPos = sf::Vector2i(900, 400);
			player = 2;
			image.SetRotation(currentPlayer == mainPlayer ? 0 : 180.0f);
			break;
		default:
			break;
		}
	}
}

int Card::getID()//获取ID
{
	return ID;
}

int Card::getSelID()
{
	return selID;
}

sf::Vector2i Card::getPos()//获取坐标
{
	return image.GetPos();
}

int Card::getAvailable(sf::Vector2i *a, sf::Vector2i *b, sf::Vector2i *c, sf::Vector2i *d)//获取可移动位置
{
	int count = 0;
	sf::Vector2i *tmp[4] = { a,b,c,d };
	for(int i = 0;i < CARD_MAX_Y;i++)
		for (int j = 0; j < CARD_MAX_X; j++)
		{
			if (available[i][j])
			{
				(*tmp[count]).x = i - 2;
				(*tmp[count]).y = j - 2;
				count++;
			}
		}
	return count;
}

void Card::Update()
{
	if (!GameOver && currentPlayer == player && image.isSelected())
	{
		image.SetColor(sf::Color(255, 255, 55, 255));
		if (mouseLeftPressed)
		{
			soundSelect.play();
			selID = selID == ID ? -1 : ID;
			mouseLeftPressed = false;
		}
	}
	else
	{
		image.SetColor(sf::Color(255, 255, 255, 255));
	}





	//动画
	if (step == 0)
	{
		image.SetPosition(targetPos);
	}
	else
	{
		sf::Vector2i delta = (targetPos - image.GetPos()) / step;
		int deltaR = deltaRotation / step;
		deltaRotation -= deltaR;
		image.Rotate(deltaR);
		image.SetPosition(image.GetPos() + delta);
		step--;
	}
}

int Card::Draw()
{
	image.Draw();
	return 0;
}

void Card::Reset()//重置选中
{
	selID = -1;
}
