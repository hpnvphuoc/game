#ifndef BALL_H
#define BALL_H
#include"object.h"
#include<vector>
#include"ball.h";
#include"boardgame.h"
#include"bar.h"
class ball :public object{
	float height;
	float weight;
	int r;
	float a;
	float b;
	int direction;
	float v;
public:
	ball();
	ball(int x, int y, int r, float a, float b, int direction, float v, float height, float weight, string imgLink);
	//virtual
	 pos getPosition();
	void move(vector<object *>list);
	float getHeight();
	float getWeight();
	string getObjectName();
	string getImglink();

	//method
	void reset();
	string CheckScore();
	void conlisionTopbar(pos TopbarPos, float TopbarHeight, float TopbarWeight);
	void conlisionBottombar(pos BottombarPos, float bottombarHeight, float bottomWeight);
	void conlisionRightbar(pos RightbarPos, float RightbarHeight, float RightbarWeight);
	void conlisionLeftbar(pos LeftbarPos, float LeftbarHeight, float LeftbarWeight);
};

#endif



