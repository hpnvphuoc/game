#pragma once
#include<string>
#include<iostream>
using namespace std;

class player
{
	string name;
	string TypePlayer;
	int mapLevel;
	int score;
	bool checkENDGAME;
	bool Double;
	bool SpeedUp;
	float SpeedUpTime;
	float DoubleTime;
public:
	///////get cac thuoc tinh////////
	string getName(); 
	int getScore();
	bool getcheckENDGAME(); 
	bool getSpeedUp();
	bool getDoulbe();
	float getDoulbeTime();
	float getSpeedUpTime();
	string getTyperPlayer();

	////////set cac thuoc tinh////////
	void setName(string name);
	void setScore(int score);
	void setcheckENDGAME(bool check);
	void setSpeedUp(bool check);
	void setDouble(bool check);
	void setDoubleTime(float x);
	void setSpeedUpTime(float x);
	string setPlayerType(string x);
	//////////ham tinh diem/////////
	void gainScore(int x);
	//ham reset lai khi player thua hoac thang
	void reset();
	// con-destructor
	player(string, string,int,bool,bool,bool,float,float);
	player();
};

