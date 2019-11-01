#include "player.h"




player::player(float x, float y, float height, float weight, int score, string Imglink)
{
	this->p.x = x;
	this->p.y = y;
	this->height = height;
	this->weight = weight;
	this->score = score;
	this->imgLink = Imglink;
}

pos player::getPosition()
{
	return this->p;
}

void player::move(vector<object*> list)
{
	int n = list.size();
	for (int i = 0; i < n; i++) {
		// ben trai ghi diem
		if (list[i]->getObjectName() == "ball") {
			if (this->getObjectName() == "Player_Left"
				&& list[i]->getPosition().x > 1032){
				this->Score();
			}
			// ben phai ghi diem
			if (this->getObjectName() == "Player_Right"
				&& list[i]->getPosition().x < 0 ) {
				this->Score();
			}
		}
	}
}

float player::getHeight()
{
	return this->height;
}

float player::getWeight()
{
	return this->weight;
}

string player::getObjectName()
{
	if (this->p.x < 1032 / 2) {
		return "Player_Left";
	}
	else
	{
		return "Player_Right";
	}
}

string player::getImglink()
{
	return this->imgLink;
}

void player::Score()
{
	score = score + 1;
	this->imgLink = "";
	this->imgLink =this->imgLink+ "images/" + char(48 + score) + ".png";
	cout << "--" << this->imgLink << endl;
}

