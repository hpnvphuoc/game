#pragma once
#include"object.h"
#include <SFML/Graphics.hpp>
using namespace sf;
class paddle :public object
{
private:
	float height;
	float weight;
public:
	//constructor
	paddle(float x, float y, float height, float weight,string Imglink);
	
	//virtual
	pos getPosition();
	void move(vector<object *>&list, player &PLAYER, float time);
	float getHeight();
	float getWeight();
	string getObjectName();
	string getImglink();
	
	void PaddleAutoMove(vector<object*>& list, player& PLAYER, float time);

	// di chuyen len
	void moveLeft();
	// di chuyen xuong
	void moveRight();
};

