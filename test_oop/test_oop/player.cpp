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

void player::gainScore(int x)
{
	this->score = this->score + x;
}

void player::reset()
{
	this->name = "";
	this->score = 0;
	this->checkENDGAME = false;
	this->timeRemaining = 0;
	this->BallStatus = "";
}
