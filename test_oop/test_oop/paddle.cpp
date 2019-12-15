#include "paddle.h"




paddle::paddle(float x, float y, float height, float weight, string Imglink)
{
	this->p.x = x;
	this->p.y = y;
	this->height = height;
	this->weight = weight;
	this->imgLink = Imglink;
}

pos paddle::getPosition()
{
	return this->p;
}

void paddle::move(vector<object*>& list, player &PLAYER, float time)
{
	// di chuyen len xuong right paddle
	if (Keyboard::isKeyPressed(Keyboard::Left)) {
		if (this->getObjectName() == "playerpaddle") {
			this->moveLeft();
		}
	};
	if (Keyboard::isKeyPressed(Keyboard::Right)) {
		if (this->getObjectName() == "playerpaddle") {
			this->moveRight();
		}
	};
}


float paddle::getHeight()
{
	return this->height;
}

float paddle::getWeight()
{
	return this->weight;
}

string paddle::getObjectName()
{
	string tempObjName = "";
	bool checkName = false;
	for (int i = 0; i < this->imgLink.length(); i++) {
		if (this->imgLink[i] == '.') {
			return tempObjName;
		}
		if (checkName == true) {
			tempObjName = tempObjName + this->imgLink[i];
		}
		if (this->imgLink[i] == '/') {
			checkName = true;
		}
	}
}

string paddle::getImglink()
{
	return this->imgLink;
}

void paddle::PaddleAutoMove(vector<object*>& list, player& PLAYER, float time)
{
	for (int i = 0; i < list.size(); i++) {
		if (list[i]->getObjectName() == "ball") {
			if (list[i]->getPosition().x>p.x) {
				p.x = list[i]->getPosition().x;
				if (p.x + this->weight / 2 > 600) {
					p.x = 600 - this->weight / 2;
				}
			}
			else {
				if (list[i]->getPosition().x < p.x) {
					p.x = list[i]->getPosition().x;
					if (p.x - this->weight / 2 < 0) {
						p.x = this->weight / 2;
					}
				}
			}
		}
	}
}

void paddle::moveLeft()
{
	p.x = p.x - 15;
	if (p.x - this->weight / 2 < 0 ) {
		p.x =  this->weight / 2;
	}
}

void paddle::moveRight()
{
	p.x = p.x + 15;
	if (p.x + this->weight / 2 > 600) {
		p.x = 600 - this->weight / 2;
	}
}




