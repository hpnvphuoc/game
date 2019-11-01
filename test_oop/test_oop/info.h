#pragma once
#include <SFML/Graphics.hpp>
#include <Windows.h>
#include<string>
#include<iostream>
#include<vector>
using namespace std;
using namespace sf;
class info
{
	Font my_font;
	vector<Text> Info_list;
public:
	
	info();
	~info();
	// ve info
	void drawInfo(RenderWindow &window);
	// thoat info
	int exit_info();
};

