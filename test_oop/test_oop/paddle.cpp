#include "paddle.h"




paddle::paddle(float x, float y, float height, float weight, string Imglink,float v,float a)
{
	this->p.x = x;
	this->p.y = y;
	this->height = height;
	this->weight = weight;
	this->imgLink = Imglink;
	this->v = v;
	this->a = a;
}

pos paddle::getPosition()
{
	return this->p;
}

void paddle::move(vector<object*> list,int t)
{
	if (Keyboard::isKeyPressed(Keyboard::Up)) {
		if (this->getObjectName() == "rightpaddle") {
			this->moveUp(t);
		}
	};
	if (Keyboard::isKeyPressed(Keyboard::Down)) {
		if (this->getObjectName() == "rightpaddle") {
			this->moveDown(t);
		}
	};
	if (Keyboard::isKeyPressed(Keyboard::W)) {
		if (this->getObjectName() == "leftpaddle") {
			this->moveUp(t);
		}
	};
	if (Keyboard::isKeyPressed(Keyboard::S)) {
		if (this->getObjectName() == "leftpaddle") {
			this->moveDown(t);
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

void paddle::moveUp(int t)
{
	p.y = p.y - (v+a*t);
	if (p.y-this->height / 2 < 0 + 13) {
		p.y = 0 + 13+this->height/2;
	}
}

void paddle::moveDown( int t)
{
	p.y = p.y + v+a*t;
	if (p.y + this->height / 2 >  684 - 13) {
		p.y = 684 - 13 - this->height / 2;
	}
}

