#ifndef OBJECT_H
#define OBJECT_H
#include<iostream>
#include<string>
#include<vector>
using namespace std;
struct pos
{
	float x, y;
};
class object
{
protected:
	pos p;
	string imgLink;
public:
	virtual void move(vector<object *>list) = 0;
	virtual pos getPosition() = 0;
	virtual float getHeight() = 0;
	virtual float getWeight() = 0;
	virtual string getObjectName() = 0;
	virtual string getImglink() = 0;
	 object();
	~object();
};

#endif


