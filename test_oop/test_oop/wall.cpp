#include "wall.h"



wall::wall(int x, int y, int height, int weight, string imgLink)
{
	//Khoi tao cac thuoc tinh
	this->p.x = x;
	this->p.y = y;
	this->height = height;
	this->weight = weight;
	this->imgLink = imgLink;
}

wall::wall()
{
}


wall::~wall()
{
}

pos wall::getPosition()
{
	return this->p;
}

void wall::move(vector<object*>& list, player &PLAYER, float time)
{
}

float wall::getHeight()
{
	return this->height;
}

float wall::getWeight()
{
	return this->weight;
}

string wall::getObjectName()
{
	return "wall";
}

string wall::getImglink()
{
	return this->imgLink;
}
