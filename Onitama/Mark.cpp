/*********************
*       指示框       *
*********************/
#include "Mark.h"

Mark::Mark(Piece *_0master, Piece *_0servant1, Piece *_0servant2, Piece *_0servant3, Piece *_0servant4,
		   Piece *_1master, Piece *_1servant1, Piece *_1servant2, Piece *_1servant3, Piece *_1servant4)
{
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

	image[0] = Image(-100, -100, 1, 1, 1, 1, &tMark[0], "", 6);
	for(int i = 1; i < 5; i++)
		image[i] = Image(-100, -100, 1, 1, 1, 1, &tMark[1], "", 6);
}

void Mark::Update()
{

}

int Mark::Draw()
{
	for (int i = 0; i < 5; i++)
	{
		image[i].Draw();
	}
	return 0;
}

void Mark::Refresh()//刷新状态
{
	
}