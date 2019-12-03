#pragma once
#include "object.h"
class boardgame:public object
{
	float height;
	float weight;
public:
	//virtual
	 void move(vector<object *>list) ;
	 pos getPosition() ;
	 float getHeight() ;
	 float getWeight() ;
	 string getObjectName() ;
	 string getImglink();

	 boardgame(int x, int y, float height, float weight,string imglink);
	 boardgame();
	~boardgame();
};

