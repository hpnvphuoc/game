#pragma once
#include <SFML/Graphics.hpp>
#include <Windows.h>
#include<string>
#include<iostream>
#include<vector>
using namespace std;
using namespace sf;
class Menu
{
	Font my_font;
	vector<Text> MenuList;
	int Optional;
public:
	// chon menu
	int Optional_choose(Event e);
	//render menulist
	void drawMenuList(RenderWindow &window);
	// update de biet dang chon play hay reset
	void update();
	Menu();
	~Menu();
};

