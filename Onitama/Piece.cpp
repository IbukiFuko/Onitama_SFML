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
	time = 0;
	delay = -1;
	if (_isMainPlayer)
		player = mainPlayer;
	else
		player = associatePlayer;
	position = _position;//棋盘坐标初始化
	coordinate.x = COORDINATE.x + _position.y * SIZE.x;
	coordinate.y = COORDINATE.y + _position.x * SIZE.y;
	image = Image(coordinate.x, coordinate.y, type == 0 ? tSIZE_MASTER_X : tSIZE_SERVANT_X, type == 0 ? tSIZE_MASTER_X : tSIZE_SERVANT_X, type == 0 ? SIZE_MASTER_X : SIZE_SERVANT_X, type == 0 ? SIZE_MASTER_Y : SIZE_SERVANT_Y, &tPiece[player][type], "", 6);
	size = image.GetSize();
	isPlaying = false;
	Refresh();
}

int Piece::Move(sf::Vector2i newPos)//棋子移动
{
	time = FPS;
	position = newPos;
	coordinate.x = COORDINATE.x + position.y * SIZE.x;
	coordinate.y = COORDINATE.y + position.x * SIZE.y;
	isPlaying = true;
	isPlayingAnimation = true;
	soundMove.play();
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

void Piece::SetEnable(bool _flag)//设置可用
{
	enable = _flag;
}

void Piece::SetEnable(bool _flag, int _delay)//设置可用
{
	tEnable = _flag;
	delay = _delay;
}

bool Piece::Enable()
{
	return enable;
}

void Piece::Update()
{
	if (!enable)
		return;
	if (!isPlayingAnimation)
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
	}
	else if(isPlaying)//播放动画
	{
		if (time == 0)
		{
			Refresh();
			currentPlayer = currentPlayer == mainPlayer ? associatePlayer : mainPlayer;//切换当前玩家
			isPlayingAnimation = false;
			isPlaying = false;
			//soundNewTurn.play();
		}
		else
		{
			sf::Vector2i deltaSize;
			if (time > FPS / 2)
			{
				deltaSize = (sf::Vector2i((int)(size.x * 1.5), (int)(size.y * 1.5)) - image.GetSize()) / (time - FPS / 2);
				image.SetSize((image.GetSize() + deltaSize).x, (image.GetSize() + deltaSize).y);
			}
			else
			{
				deltaSize = (image.GetSize() - size) / time;
				image.SetSize((image.GetSize() - deltaSize).x, (image.GetSize() - deltaSize).y);
			}
			sf::Vector2i delta = (coordinate - image.GetPos()) / time;
			image.SetPosition(image.GetPos() + delta);
			time--;
		}
	}

	if (delay != -1)
	{
		if (delay > 0)
		{
			delay--;
		}
		else if (delay == 0)
		{
			enable = tEnable;
			soundEat.play();
			delay = -1;
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

void Piece::Reset()//重置选中
{
	selID = -1;
}

void Piece::Refresh()//刷新状态
{
	coordinate.x = COORDINATE.x + position.y * SIZE.x;
	coordinate.y = COORDINATE.y + position.x * SIZE.y;
	image.SetPosition(coordinate);
	image.SetSize(size.x, size.y);
}