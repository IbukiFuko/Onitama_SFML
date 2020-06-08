/*********************
*        卡片        *
*********************/
#include "Card.h"

Card::Card()
{
	type = 0;
	isMove = false;
	image = Image(-100, -100, 1, 1, 1, 1, &tCard[0], "", 6);
	SetAvailable();//设置卡片可移动偏移
}

Card::Card(int _type)
{
	type = _type;
	isMove = false;
	image = Image(100, 100, 1, 1, 1, 1, &tCard[_type], "", 6);
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

void Card::Update()
{

}

int Card::Draw()
{
	image.Draw();
	return 0;
}