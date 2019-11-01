#include "boardgame.h"



void boardgame::move(vector<object*> list)
{
}

pos boardgame::getPosition()
{
	return this->p;
}

float boardgame::getHeight()
{
	return this->height;
}

float boardgame::getWeight()
{
	return this->weight;
}

string boardgame::getObjectName()
{
	return "boardgame";
}

string boardgame::getImglink()
{
	return this->imgLink;
}

boardgame::boardgame(int x, int y, float height, float weight,string imglink)
{
	this->imgLink = imglink;
	this->p.x = x;
	this->p.y = y;
	this->height = height;
	this->weight = weight;
}

boardgame::boardgame()
{
}


boardgame::~boardgame()
{
}
