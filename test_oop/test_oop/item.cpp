#include "item.h"



bool item::conlisionBall(pos BallPos, float BallHeight, float BallWeight)
{
	//va cham tren
	if (BallPos.y + BallHeight / 2 > p.y - height / 2 && BallPos.y + BallHeight / 2 < p.y + height / 2) {
		if (BallPos.x > p.x - weight / 2 && BallPos.x < p.x + weight / 2) {
			cout << "tren" << endl;
			return true;
		}
	};
	//va cham duoi
	if (BallPos.y - BallHeight / 2 < p.y + height / 2 && BallPos.y - BallHeight / 2 > p.y - height / 2) {
		if (BallPos.x > p.x - weight / 2 && BallPos.x < p.x + weight / 2) {
			cout << "duoi" << endl;
			return true;
		}
	}
	//va cham  mat phai
	if (BallPos.x - BallWeight / 2 < p.x + weight / 2 && BallPos.x - BallWeight / 2 > p.x - weight / 2) {
		if (BallPos.y > p.y - height / 2 && BallPos.y < p.y + height / 2) {
			cout << "phai" << endl;
			return true;
		}
	}
	//va cham mat trai
	if (BallPos.x + BallWeight / 2 > p.x - weight / 2 && BallPos.x + BallWeight / 2 < p.x + weight / 2) {
		if (BallPos.y > p.y - height / 2 && BallPos.y < p.y + height / 2) {
			cout << "trai" << endl;
			return true;
		}
	}
	return false;
}

item::item(int x, int y, int height, int weight, int level, int score, string imgLink)
{
	this->p.x = x;
	this->p.y = y;
	this->height = height;
	this->weight = weight;
	this->score = score;
	this->imgLink = imgLink;
}

item::item()
{
}


item::~item()
{
}

pos item::getPosition()
{
	return this->p;
}

void item::move(vector<object*>& list, player &PLAYER, float time)
{
}

float item::getHeight()
{
	return this->height;
}

float item::getWeight()
{
	return this->weight;
}

string item::getObjectName()
{
	return "item";
}

string item::getImglink()
{
	return this->imgLink;
}

int item::getScore()
{
	return this->score;
}
