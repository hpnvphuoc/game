#pragma once
#include"object.h"
class item :public object
{
	float height;
	float weight;
	int score;
	int v;
public:
	pos getPosition();
	void move(vector<object *>&list, player &PLAYER, float time);
	float getHeight();
	float getWeight();
	string getObjectName();
	string getImglink();
	int getScore();

	//xet va cham voi thanh
	bool conlisionPaddle(pos PaddlePos, float PaddleHeight, float PaddleWeight);
	//xet va cham voi day
	bool conlisionBottombar(pos BottombarPos, float bottombarHeight, float bottomWeight);
	string getItemType();
	// khoi tao item
	item(int x, int y, int height, int weight, int v,int score, string imgLink);
	item();
	~item();
};

