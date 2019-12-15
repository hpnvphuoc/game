#include "brick.h"



bool brick::conlisionBall(pos BallPos, float BallHeight, float BallWeight)
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
			cout << "trai"<<endl;
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
				level--;
				PLAYER.gainScore(this->score);
				cout << PLAYER.getScore();
			}
		}
	}
	if (level == 2) {
		this->imgLink = "images/brick_2.png";
	}
	if (level == 1) {
		this->imgLink = "images/brick_1.png";
	}
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
