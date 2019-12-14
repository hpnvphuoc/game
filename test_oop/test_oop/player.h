#pragma once
#include"object.h"
class player:public object 
{
private:
	float height;
	float weight;
	int score;
public:
	//constructor
	player(float x, float y, float height, float weight,int score, string Imglink);

	//virtual
	pos getPosition();
	void move(vector<object *>list,int t=0);
	float getHeight();
	float getWeight();
	string getObjectName();
	string getImglink();

	void Score();
};

