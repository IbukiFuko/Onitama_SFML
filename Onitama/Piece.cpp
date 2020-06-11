/*********************
*        棋子        *
*********************/
#include "Piece.h"

int Piece::selID = -1;

Piece::Piece()
{
	Piece(0, true, sf::Vector2i(0, 0));
}

Piece::Piece(int _type, bool _isMainPlayer, sf::Vector2i _position)
{
	ID = objectID++;
	enable = true;
	type = _type;
	if (_isMainPlayer)
		player = mainPlayer;
	else
		player = associatePlayer;
	position = _position;//棋盘坐标初始化
	coordinate.x = COORDINATE.x + _position.y * SIZE.x;
	coordinate.y = COORDINATE.y + _position.x * SIZE.y;
	image = Image(coordinate.x, coordinate.y, type == 0 ? tSIZE_MASTER_X : tSIZE_SERVANT_X, type == 0 ? tSIZE_MASTER_X : tSIZE_SERVANT_X, type == 0 ? SIZE_MASTER_X : SIZE_SERVANT_X, type == 0 ? SIZE_MASTER_Y : SIZE_SERVANT_Y, &tPiece[player][type], "", 6);
	Refresh();
}

int Piece::Move(sf::Vector2i delta)//棋子移动
{
	position = position + delta;//逻辑位置
	Refresh();
	return 0;
}

sf::Vector2i Piece::getPos()//获取位置
{
	return position;
}

sf::Vector2i Piece::getCoordinate()//获取坐标
{
	return coordinate;
}

int Piece::getID()//获取ID
{
	return ID;
}

int Piece::getSelID()
{
	return selID;
}

bool Piece::IsHere(sf::Vector2i _position)//是否存在
{
	return (position == _position);
}

bool Piece::Enable()
{
	return enable;
}

void Piece::Update()
{
	if (!enable)
		return;
	if (1 && image.isSelected(sf::Color(255, 255, 55, 255)))
	{
		if (mouseLeftPressed)
		{
			selID = selID == ID ? -1 : ID;
			printf("\r%s:%s                            ", player == mainPlayer ? "mainPlayer" : "associatePlayer", type == 0 ? "Master" : "Servant");
			mouseLeftPressed = false;
		}
	}
}

int Piece::Draw()
{
	if (!enable)
		return -1;
	image.Draw();
	return 0;
}

void Piece::Refresh()//刷新状态
{
	coordinate.x = COORDINATE.x + position.y * SIZE.x;
	coordinate.y = COORDINATE.y + position.x * SIZE.y;
	image.SetPosition(coordinate);
}