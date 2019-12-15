#pragma once
#include"object.h"
class wall :public object
{
	float height;
	float weight;
public:
	pos getPosition();
	void move(vector<object *>&list, player &PLAYER, float time);
	float getHeight();
	float getWeight();
	string getObjectName();
	string getImglink();
	// khoi tao thanh
	wall(int x, int y, int height, int weight, string imgLink);
	wall();
	~wall();
	
};

