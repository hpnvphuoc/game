#include<vector>
#include"ball.h"
#include <SFML/Graphics.hpp>
#include"bar.h"
#include"paddle.h"
#include"menu.h"
#include"info.h"
#include"wall.h"
#include"brick.h"
//#include"item.h"
#include"item.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include<fstream>
using namespace sf;
class game
{
	Menu main_Menu; // hien man hinh menu chinh
	info about_info; // hien instructor
	vector<object*> objArr; // cac object trong game
	vector<player> HighScore; // hien highscore
	player PLAYER; // player dang choi
	int checkScreen ; // check xem dang o man hinh nao
	float time;           // time cua game
	int round; // check man choi
public:
	void init();// khoi tao game
	void run(); // chay game 
	void render(RenderWindow &window, bool IsComputer = false); // render cac obj
	void objMove(); // upadate object position

	/////////render info ingame//////////
	void renderPlayerScore(RenderWindow &window); // hien player score
	void renderSpeedUpTime(RenderWindow& window);// hien TG cua item speed up
	void renderDoubleTime(RenderWindow& window);// hien TG cua item speed up
	void renderNumberofRound(RenderWindow& window);
	///////////////////////////////////////

	bool checkBrickIsExist();  // kiem tra xem con vien gach nao ko
	void saveScore(); // luu diem cua player lai
	////////////////cac map ///////////////////////
								////map1////
	void prepareForMap1(); //chuan bi cho map 1
	void Map1( );// choi map 1
								////map2////
	void prepareForMap2(); //chuan bi cho map 1
	void Map2();//
								////map3////
	void prepareForMap3(); //chuan bi cho map 1
	void Map3();//

	void showHighScore();// hien diem top 10 cao nhat len
	void ItemPushBack(item tempItem);


	//Ham them item
	void addSpeedUpItem();
	void addDoubleItem();
	void addScoreUpItem();
	void addScoreDownItem();
	void GenerateItem();
	/////
	void SortHighScore();//sap xep diem cua nguoi choi
	void Instruction(); // huong dan game

	//constrcutor destructor
	game();
	~game();
};



