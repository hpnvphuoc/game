#pragma once
#include<string>
#include<iostream>
using namespace std;
struct pos
{
	float x, y;
};
class player
{
	string name;
	int score;
	bool checkENDGAME;
	float timeRemaining;
	string BallStatus;
public:
	string getName();
	int getScore();
	bool getcheckENDGAME(); 
	void setName(string name);
	void setScore(int score);
	void setcheckENDGAME(bool check);
	void gainScore(int x);
	void reset();
};

