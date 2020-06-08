/*********************
*        棋子        *
*********************/
#include "Piece.h"

Piece::Piece()
{
	Piece(0, true, sf::Vector2i(0, 0));
}

Piece::Piece(int _type, bool _isMainPlayer, sf::Vector2i _position)
{
	enable = true;
	type = _type;
	isMainPlayer = _isMainPlayer;
	position = _position;//棋盘坐标初始化
	coordinate.x = COORDINATE.x + _position.y * SIZE.x;
	coordinate.y = COORDINATE.y + _position.x * SIZE.y;
	image = Image(coordinate.x, coordinate.y, type == 0 ? tSIZE_MASTER_X : tSIZE_SERVANT_X, type == 0 ? tSIZE_MASTER_X : tSIZE_SERVANT_X, type == 0 ? SIZE_MASTER_X : SIZE_SERVANT_X, type == 0 ? SIZE_MASTER_Y : SIZE_SERVANT_Y, &tPiece[isMainPlayer?0:1][type], "", 6);
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

}

int Piece::Draw()
{
	image.Draw();
	return 0;
}

void Piece::Refresh()//刷新状态
{
	coordinate.x = COORDINATE.x + position.y * SIZE.x;
	coordinate.y = COORDINATE.y + position.x * SIZE.y;
	image.SetPosition(coordinate);
}