#pragma once
#include "object.h"
class boardgame:public object
{
	float height;
	float weight;
public:
	//virtual method viet lai cua class obj
	 void move(vector<object *>&list, player &PLAYER, float time) ;
	 pos getPosition() ;
	 float getHeight() ;
	 float getWeight() ;
	 string getObjectName() ;
	 string getImglink();
	 //con-de structor
	 boardgame(int x, int y, float height, float weight,string imglink);
	 boardgame();
	~boardgame();
};

