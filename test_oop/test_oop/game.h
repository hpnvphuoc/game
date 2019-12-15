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
	Menu main_Menu;
	info about_info;
	vector<object*> objArr;
	vector<player> HighScore;
	vector<item>Listof_Item;
	player PLAYER;
	int checkScreen ;
	float time;
public:
	void init();// khoi tao game
	void run(); // chay game 
	void render(RenderWindow &window, bool IsComputer = false); // render cac obj
	void objMove(); // upadate object position
	void renderPlayerScore(RenderWindow &window); // hien player score
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
	void SortHighScore();//sap xep diem cua nguoi choi
	void Instruction();

	//constrcutor destructor
	game();
	~game();
};



