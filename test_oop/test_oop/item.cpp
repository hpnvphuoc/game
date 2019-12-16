#include "item.h"





bool item::conlisionPaddle(pos PaddlePos, float PaddleHeight, float PaddleWeight)
{
	//xet xem toa do y  cua trai banh co nam giua do cao cua thanh truot hay ko
	if (p.y + height / 2 > PaddlePos.y - PaddleHeight / 2 && p.y - height / 2 < PaddlePos.y + PaddleHeight) {
		// xet xem toa do x co nam giua thanh truot hay ko
		if (p.x + weight / 2 > PaddlePos.x - PaddleWeight / 2 && p.x - weight / 2 < PaddlePos.x + PaddleWeight / 2) {
			return true;
		}
	};
	return false;
}

bool item::conlisionBottombar(pos BottombarPos, float bottombarHeight, float bottomWeight)
{
	// p.y cua item vuot qua mat tren cua thanh duoi
	if (p.y + height / 2 > BottombarPos.y - bottombarHeight / 2) {
		return true;
	}
	return false;
}

string item::getItemType()
{
	// lay loai item duoi vao imglink
	string s = this->imgLink;
	string ItemType="";
	bool checkStart=false;
	int k = 0;
	// lay tu ki tu "/" den ki tu '.'
	// vi du data/ScoreUp.txt - > ScoreUP
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '.') {
			checkStart = false;
		}
		if (checkStart == true) {
			ItemType = ItemType+ s[i];
			k++;
		}
		if (s[i] == '/') {
			checkStart = true;
		}
	}
	return ItemType;
}

item::item(int x, int y, int height, int weight,int v, int score, string imgLink)
{
	this->p.x = x;
	this->p.y = y;
	this->height = height;
	this->weight = weight;
	this->score = score;
	this->imgLink = imgLink;
	this->v = v;
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
	//di chuyen roi xuong
	this->p.y = this->p.y + v;
	//xet va cham voi paddle
	int n = list.size();
	for (int i = 0; i < n; i++) {
		//gap thanh paddle
		if (list[i]->getObjectName() == "playerpaddle") {
			if (conlisionPaddle(list[i]->getPosition(), list[i]->getHeight(), list[i]->getWeight()) == true) {
				//nhap item vao player
				if (this->getItemType() == "Double") {
					PLAYER.setDouble(true);
					PLAYER.setDoubleTime(0);
				}
				if (this->getItemType() == "SpeedUp") {
					PLAYER.setSpeedUp(true);
					PLAYER.setSpeedUpTime(0);
				}
				if (this->getItemType() == "ScoreUp") {

					PLAYER.gainScore(this->getScore());
				}
				if (this->getItemType() == "ScoreDown") {
					PLAYER.gainScore(this->getScore());
				}
				this->imgLink = "";
			}
		}
		//gap day
		if (list[i]->getObjectName() == "bottombar") {
			if (conlisionBottombar(list[i]->getPosition(), list[i]->getHeight(), list[i]->getWeight()) == true) {
				this->imgLink = "";
			}
		}
	}
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
