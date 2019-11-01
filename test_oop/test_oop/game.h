#include<vector>
#include"ball.h"
#include <SFML/Graphics.hpp>
#include"bar.h"
#include"paddle.h"
#include"player.h"
#include"menu.h"
#include"info.h"
using namespace sf;
class game
{
	Menu main_Menu;
	info about_info;
	vector<object*> objArr;
	int checkScreen ;
public:
	
	void init();// khoi tao game
	void run(); // chay game 
	void render(RenderWindow &window); // render cac obj
	void objMove(); // upadate object position
};



