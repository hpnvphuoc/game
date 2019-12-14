#include "bar.h"



bar::bar()
{
}


bar::~bar()
{
}

pos bar::getPosition()
{
	return this->p;
}

void bar::move(vector<object*> List,int t)
{
	
}

float bar::getHeight()
{
	return this->height;
}

float bar::getWeight()
{
	return this->weight;
}

string bar::getObjectName()
{
	string tempObjName="";
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

string bar::getImglink()
{
	return this->imgLink;
}


bar::bar(int x, int y, int height, int weight, string imgLink)
{
	this->p.x = x;
	this->p.y = y;
	this->height = height;
	this->weight = weight;
	this->imgLink = imgLink;
}
