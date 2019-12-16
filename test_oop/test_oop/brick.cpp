#include "brick.h"



bool brick::conlisionBall(pos BallPos, float BallHeight, float BallWeight)
{
	// xet va cham tren duoi trai phai giong nhu va cham voi top left right bottom right bar
	//va cham tren
	if (BallPos.y + BallHeight / 2 > p.y - height / 2 && BallPos.y + BallHeight / 2 < p.y + height / 2) {
		if (BallPos.x > p.x - weight / 2 && BallPos.x < p.x + weight / 2) {
			return true;
		}
	};
	//va cham duoi
	if (BallPos.y - BallHeight / 2 < p.y + height / 2 && BallPos.y - BallHeight / 2 > p.y - height / 2) {
		if (BallPos.x > p.x - weight / 2 && BallPos.x < p.x + weight / 2) {
			return true;
		}
	}
	//va cham  mat phai
	if (BallPos.x - BallWeight / 2 < p.x + weight / 2 && BallPos.x - BallWeight / 2 > p.x - weight / 2) {
		if (BallPos.y > p.y - height / 2 && BallPos.y < p.y + height / 2) {
			return true;
		}
	}
	//va cham mat trai
	if (BallPos.x + BallWeight / 2 > p.x - weight / 2 && BallPos.x + BallWeight / 2 < p.x + weight / 2) {
		if (BallPos.y > p.y - height / 2 && BallPos.y < p.y + height / 2) {
			return true;
		}
	}
	return false;
}

brick::brick(int x, int y, int height, int weight, int level, int score, string imgLink)
{
	this->p.x = x;
	this->p.y = y;
	this->height = height;
	this->weight = weight;
	this->level= level;
	this->score = score;
	this->imgLink = imgLink;
}

brick::brick()
{
}


brick::~brick()
{
}

pos brick::getPosition()
{
	return this->p ;
}

void brick::move(vector<object*>& list, player &PLAYER, float time)
{
	int n = list.size();
	for (int i = 0; i < n; i++) {
		if (list[i]->getObjectName() == "ball") {
			//xd cham vao banh 
			if (conlisionBall(list[i]->getPosition(), list[i]->getHeight(), list[i]->getWeight()) == true) {
				level--; // giam level vien gach
				PLAYER.gainScore(this->score);  // tang diem cho nguoi choi
			}
		}
	}
	// load hinh anh moi
	if (level == 2) {
		this->imgLink = "images/brick_2.png";
	}
	if (level == 1) {
		this->imgLink = "images/brick_1.png";
	}
	// neu hinh anh =='' thi xoa vien gach
	if (level == 0) {
		this->imgLink = "";
	}
}

float brick::getHeight()
{
	return this->height;
}

float brick::getWeight()
{
	return this->weight;
}

string brick::getObjectName()
{
	return "brick";
}

string brick::getImglink()
{
	return this->imgLink;
}

int brick::getLevel()
{
	return this->level;
}

int brick::getScore()
{
	return this->score;
}
