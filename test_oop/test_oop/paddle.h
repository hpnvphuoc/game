#pragma once
#include"object.h"
#include <SFML/Graphics.hpp>
using namespace sf;
class paddle :public object
{
private:
	float height;
	float weight;
	float v, a;
	int time;

public:
	//constructor
	paddle(float x, float y, float height, float weight, string Imglink, float v,float a=1.0,int time=0);
	
	//virtual
	pos getPosition();
	void move(vector<object *>list);
	float getHeight();
	float getWeight();
	string getObjectName();
	string getImglink();


	void moveUp();
	void moveDown();
};

