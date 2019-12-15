#include<vector>
#include"ball.h"
#include <SFML/Graphics.hpp>
#include"bar.h"
#include"paddle.h"
#include"player.h"
#include"menu.h"
#include"info.h"
#include"wall.h"
#include"brick.h"
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
	player PLAYER;
	int checkScreen ;
	float time;
public:
	void init();// khoi tao game
	void run(); // chay game 
	void render(RenderWindow &window); // render cac obj
	void objMove(); // upadate object position
	void renderPlayerScore(RenderWindow &window); // hien player score
	void checkBrickIsExist();  // kiem tra xem con vien gach nao ko
	void saveScore(); // luu diem cua player lai
	void prepareForMap1(); //chuan bi cho map 1
	void Map1( );// choi map 1
	void showHighScore();// hien diem top 10 cao nhat len
	void SortHighScore();
	//constrcutor destructor
	game();
	~game();
};



