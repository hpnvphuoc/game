#pragma once
#include"object.h"

class brick:public object
{
	float height;
	float weight;
	int level;
	int score;
public:
	pos getPosition();
	void move(vector<object *>&list,  player &PLAYER, float time);
	float getHeight();
	float getWeight();
	string getObjectName();
	string getImglink();
	int getLevel();
	int getScore();

	//xet va cham voi banh
	bool conlisionBall(pos BallPos, float BallHeight, float BallWeight);
	// khoi tao thanh
	brick(int x, int y, int height, int weight, int level, int score, string imgLink);
	brick();
	~brick();
};

