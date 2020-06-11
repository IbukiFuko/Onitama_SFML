/*********************
*        按钮        *
*********************/
#include "Image.h"

Image::Image()
{
}

Image::Image(int x, int y, int width, int height, int sizeX, int sizeY, sf::Texture *texture, std::string str, int size)//构造函数
{
	flag = false;
	rotation = 0;
	SetPosition(x, y);
	SetSize(width, height);
	SetSprite(texture, sizeX, sizeY);
	SetText(str, size);
	
	flag = true;
	Refresh();
}

int Image::SetPosition(int x,int y)//设置位置
{
	position = sf::Vector2i(x, y);
	Refresh();
	return 0;
}

int Image::SetPosition(sf::Vector2i _position)
{
	position = _position;
	Refresh();
	return 0;
}

int Image::SetSize(int width, int height)//设置大小
{
	imageWidth = width;
	imageHeight = height;
	Refresh();
	return 0;
}
int Image::SetSprite(sf::Texture *texture, int sizeX, int sizeY)//设置纹理
{
	sImage.setTexture(*texture);
	spriteWidth = sizeX;
	spriteHeight = sizeY;
	Refresh();
	return 0;
}

int Image::SetText(std::string str, int size)//设置文字
{
	strLength = str.size();
	strSize = size;
	Text = sf::Text(str, font, size);
	Refresh();
	return 0;
}

int Image::Rotate()//旋转
{
	rotation++;
	Refresh();
	return 0;
}

int Image::Rotate(int _delta)
{
	for (int i = 0; i < _delta; i++)
		Rotate();
	return 0;
}

int Image::SetRotation(float _rotation)//设置旋转
{
	rotation = _rotation;
	Refresh();
	return 0;
}

int Image::Draw()//绘制按钮
{
	window.draw(sImage);
	window.draw(Text);
	return 0;
}

sf::Vector2i Image::GetPos()//获取位置
{
	
	return position;
}

sf::Vector2i Image::GetSize()//获取大小
{
	return sf::Vector2i(imageWidth, imageHeight);
}

float Image::GetRotation()//获取旋转
{
	return rotation;
}

sf::Sprite Image::GetSprite()//获取图像
{
	return sImage;
}

bool Image::isSelected()//鼠标是否选中
{
	if (mousePos.x >= position.x - imageWidth / 2.0f && mousePos.x <= position.x + imageWidth / 2.0f
		&& mousePos.y >= position.y - imageHeight / 2.0f && mousePos.y <= position.y + imageHeight / 2.0f)
	{
		sImage.setColor(sf::Color(255, 255, 0, 255));
		return true;
	}
	else
	{
		sImage.setColor(sf::Color(255, 255, 255, 255));
		return false;
	}
}

void Image::Refresh()//刷新状态
{
	if (!flag)
		return;
	sImage.setOrigin(spriteWidth / 2.0f, spriteHeight / 2.0f);
	sImage.setPosition(1.0f * position.x, 1.0f * position.y);
	sImage.setScale(1.0f * imageWidth / spriteWidth, 1.0f * imageHeight / spriteHeight);
	if (rotation >= 360)
		rotation -= 360;
	sImage.setRotation(rotation);
	Text.setPosition(position.x - strSize*strLength/4.0f, position.y - strSize*2/3.0f);
	Text.setRotation(rotation);
}