#include "player.h"

string player::getName()
{
	return this->name;
}

int player::getScore()
{
	return this->score;
}

bool player::getcheckENDGAME()
{
	return this->checkENDGAME;
}

bool player::getSpeedUp()
{
	return this->SpeedUp;
}

bool player::getDoulbe()
{
	return this->Double;
}

float player::getDoulbeTime()
{
	return this->DoubleTime;
}

float player::getSpeedUpTime()
{
	return this->SpeedUpTime;
}

void player::setName(string name)
{
	this->name = name;
}

void player::setScore(int score)
{
	this->score =  score;
}

void player::setcheckENDGAME(bool check)
{
	this->checkENDGAME = check;
}

void player::setSpeedUp(bool check)
{
	this->SpeedUp = check;
}

void player::setDouble(bool check)
{
	this->Double = check;
}

void player::setDoubleTime(float x)
{
	this->DoubleTime = x;
}

void player::setSpeedUpTime(float x)
{
	this->SpeedUpTime = x;
}


void player::gainScore(int x)
{
	if (this->Double == true) {
		this->score = this->score + 2*x;
	}
	else
	{
		this->score = this->score +  x;
	}
}



void player::reset()
{
	this->name = "";
	this->score = 0;
	this->checkENDGAME = false;
}

player::player(string name,string playerType , int score, bool checkENDGAME, bool SpeedUp, bool Double,float DoubleTime,float SpeedUpTime)
{
	this->name = name;
	this->TypePlayer=playerType;
	this->checkENDGAME = checkENDGAME;
	this->score = score;
	this->Double = Double;
	this->SpeedUp = SpeedUp;
	this->DoubleTime = DoubleTime;
	this->SpeedUpTime= SpeedUpTime;
}

player::player()
{
}
