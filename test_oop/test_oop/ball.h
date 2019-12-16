#ifndef BALL_H
#define BALL_H
#include "object.h"
#include<vector>
class ball :public object{
	float height; 
	float weight;
	int r; // ban kinh trai banh
	float a; // a trong y=ax + b
	float b; // b trong y= ax+b
	int direction; // huong di chuyen - is up + is down
	float v; // van toc trai banh
public:
	//constructor
	ball();
	ball(int x, int y, int r, float a, float b, int direction, float v, float height, float weight, string imgLink);
	//virtual method viet lai cua class obj
	 pos getPosition();
	void move(vector<object *>&list, player &PLAYER, float time);
	float getHeight();
	float getWeight();
	string getObjectName();
	string getImglink();
	// 

	//method cua class ball
	// ham reset trai banh ve vi tri giua san sau khi ghi diem
	void reset();
	//ham kiem tra diem
	void CheckScore(vector<object *>list);

	//////////////////xet va cham void cac obj de banh doi huong//////////////////
	// xet va cham voi thanh tren
	void conlisionTopbar(pos TopbarPos, float TopbarHeight, float TopbarWeight);
	// xet va cham voi thanh duoi -> bi thua
	bool conlisionBottombar(pos BottombarPos, float bottombarHeight, float bottomWeight);
	// xet va cham voi thanh phai
	void conlisionRightbar(pos RightbarPos, float RightbarHeight, float RightbarWeight);
	// xet va cham voi thanh trai
	void conlisionLeftbar(pos LeftbarPos, float LeftbarHeight, float LeftbarWeight);
	// xet va cham voi thanh truot
	void conlisionPaddle(pos PaddlePos, float PaddleHeight, float PaddleWeight);
	// xet va cham voi tuong
	void conlisionWall(pos WallPos, float WallHeight, float WallWeight);
	// xet va cham voi gach
	bool conlisionBrick(pos BrickPos, float BrickHeight, float BrickWeight);
	////////////////////-----////////////////////////////////////

	// pha vo gach
	void breakBrick(int vitri, vector<object *>&list);
};

#endif



