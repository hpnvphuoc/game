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
	
	//virtual method viet lai cua class object
	pos getPosition();
	void move(vector<object *>&list, player &PLAYER, float time);
	float getHeight();
	float getWeight();
	string getObjectName();
	string getImglink();
	 //ham tu di chen thanh truoc
	void PaddleAutoMove(vector<object*>& list, player& PLAYER, float time);

	// di chuyen trai
	void moveLeft();
	// di chuyen phai
	void moveRight();
};

