#pragma once
#include"object.h"
class bar:public object
{
	float height;
	float weight;
public:
	 pos getPosition();
	void move(vector<object *>list);
	float getHeight();
	float getWeight();
	string getObjectName();
	string getImglink();

	bar(int x, int y, int height, int weight, string imgLink);
	bar();
	~bar();
};

