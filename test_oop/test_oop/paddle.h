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
	paddle(float x, float y, float height, float weight, string Imglink, float v,float a=1.0,int t=0);
	
	//virtual
	pos getPosition();
	void move(vector<object *>list,int t=0);
	float getHeight();
	float getWeight();
	string getObjectName();
	string getImglink();


	void moveUp(int t);
	void moveDown();
};

