/*********************
*        棋子        *
*********************/
#include "Piece.h"

Piece::Piece(int _type, bool _isMainPlayer, sf::Vector2i _position)
{
	enable = true;
	type = _type;
	isMainPlayer = (int)(!_isMainPlayer);
	position = _position;//棋盘坐标初始化
	coordinate = sf::Vector2i(COORDINATE.x + _position.x * SIZE.x, COORDINATE.y + _position.y * SIZE.y);//像素坐标初始化
	image = Image(coordinate.x, coordinate.y, sizePiece[type].x, sizePiece[type].y, type == 0 ? SIZE_MASTER_X : SIZE_SERVANT_X, type == 0 ? SIZE_MASTER_Y : SIZE_SERVANT_Y, &tPiece[isMainPlayer][type], "", 6);
}

int Piece::Move(sf::Vector2i delta)//棋子移动
{
	position = position + delta;//逻辑位置
	return 0;
}

sf::Vector2i Piece::getPos()//获取位置
{
	return position;
}

bool Piece::isHere(sf::Vector2i _position)//是否存在
{
	return (position == _position);
}

int Piece::Draw()
{
	image.Draw();
	return 0;
}

void Piece::Refresh()//刷新状态
{
	coordinate = sf::Vector2i(COORDINATE.x + position.x * SIZE.x, COORDINATE.y + position.y * SIZE.y);//像素坐标刷新
	image.SetPosition(coordinate);
}