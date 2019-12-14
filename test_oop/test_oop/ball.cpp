#include "ball.h"




ball::ball()
{
}

void ball::reset()
{
	p.x = 1032 / 2;
	p.y = 684 / 2;
	b = p.y - a * p.x;
	v = 5;
}

string ball::CheckScore()
{
	if (this->p.x < 0) {
		this->reset();
	}
	if (this->p.x > 1032) {
		this->reset();
	}
	return "";
}

ball::ball(int x, int y, int r, float a, float b, int direction, float v,float height,float weight, string imgLink)
{
	this->imgLink = imgLink;
	p.x = x;
	p.y = y;
	this->height = height;
	this->weight = weight;
	this->a = float(a);
	this->b = float(p.y) - float(a) * p.x;
	this->r = r;
	this->direction = direction;
	this->v = v;
}


pos ball::getPosition()
{
	return this->p;
}

void ball::move(vector<object *>list,int t)
{
	p.x = p.x + v;
	p.y = a * p.x + b;
	int n = list.size();
	for (int i = 0; i < n; i++) {
		if (list[i]->getObjectName() == "rightpaddle") {
			conlisionRightbar(list[i]->getPosition(), list[i]->getHeight(), list[i]->getWeight());
		}
		if (list[i]->getObjectName() == "topbar") {
			conlisionTopbar(list[i]->getPosition(), list[i]->getHeight(), list[i]->getWeight());
		}
		if (list[i]->getObjectName() == "leftpaddle") {

			conlisionLeftbar(list[i]->getPosition(), list[i]->getHeight(), list[i]->getWeight());
		}
		if (list[i]->getObjectName() == "bottombar") {
			conlisionBottombar(list[i]->getPosition(), list[i]->getHeight(), list[i]->getWeight());
		}
	}
	this->CheckScore();
	
}

float ball::getHeight()
{
	return this->height;
}

float ball::getWeight()
{
	return this->weight;
}

string ball::getObjectName()
{
	return "ball";
}

string ball::getImglink()
{
	return this->imgLink;
}

void ball::conlisionTopbar(pos TopbarPos, float TopbarHeight, float TopbarWeight)
{
	if (p.y - height/2 < TopbarPos.y+TopbarHeight/2) {
		int tempy = height / 2 + TopbarPos.y + TopbarHeight / 2;
		b = 2 * tempy - b;;
		a = -a;
		v = v * 1.1;
	}
}

void ball::conlisionBottombar(pos BottombarPos, float bottombarHeight, float bottomWeight)
{
	if (p.y + height / 2 > BottombarPos.y - bottombarHeight / 2) {
		int tempy = -height / 2 + BottombarPos.y - bottombarHeight / 2;
		b = tempy * 2 - b;
		a = -a;
		v = v * 1.1;
	};
}

void ball::conlisionRightbar(pos RightbarPos, float RightbarHeight, float RightbarWeight)
{
	if (p.x + weight / 2 > RightbarPos.x - RightbarWeight / 2) {
		if (p.y + height / 2 > RightbarPos.y - RightbarHeight / 2 && p.y - height / 2 < RightbarPos.y + RightbarHeight / 2) {
			int tempx =- weight / 2 + RightbarPos.x - RightbarWeight / 2;
			b = 2 * tempx*a + b;
			a = -a;
			v = -v * 1.1;
		}
	}
	
}

void ball::conlisionLeftbar(pos LeftbarPos, float LeftbarHeight, float LeftbarWeight)
{
	if (p.x - weight / 2 < LeftbarPos.x + LeftbarWeight / 2) {
		if (p.y + height / 2 > LeftbarPos.y - LeftbarHeight / 2 && p.y - height / 2 < LeftbarPos.y + LeftbarHeight / 2) {
			int tempx = weight / 2 + LeftbarPos.x + LeftbarWeight / 2;
			b = 2 * tempx*a + b;
			a = -a;
			v = -v * 1.1;
		}
	}
	
}


