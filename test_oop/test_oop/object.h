#ifndef OBJECT_H
#define OBJECT_H
#include<iostream>
#include<string>
#include<vector>
#include "player.h"
using namespace std;

class object
{
protected:
	pos p;
	string imgLink;
public:
	// ham chuyen dong
	virtual void move(vector<object *> &list, player &PLAYER,float time) = 0;
	// ham lay vi tri
	virtual pos getPosition() = 0;
	// ham lay chieu doc obj
	virtual float getHeight() = 0;
	//ham lay chieu ngang obj
	virtual float getWeight() = 0;
	//Ham lay ten obj
	virtual string getObjectName() = 0;
	// Ham lay link img
	virtual string getImglink() = 0;
	 object();
	~object();
};

#endif


