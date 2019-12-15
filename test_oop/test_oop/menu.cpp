#include "Menu.h"

int Menu::Optional_choose(Event e)
{
	//di chuyen len xuong

	//string keypress;
	//if (e.type == Event::KeyPressed) {
	//	if (e.key.code == sf::Keyboard::Up) {
	//		keypress = "UP";
	//		
	//	}
	//}
	//if (e.type == Event::KeyPressed) {
	//	if (e.key.code == sf::Keyboard::Down) {
	//		keypress = "DOWN";
	//		cout << keypress;
	//	}
	//}

	//Kiem tra option
	if (e.type == Event::KeyPressed) {
		if (e.key.code == sf::Keyboard::Up) {
			this->Optional = this->Optional -1 ;
			//ko cho chay qua 4
			if (this->Optional <0 ) {
				this->Optional = 0;
			}
		}
		if (e.key.code == sf::Keyboard::Down) {
			this->Optional = this->Optional + 1;
			//ko cho chay qua 3
			if (this->Optional > 3) {
				this->Optional = 3;
			}
		}
	}


	// chon play
	if (Keyboard::isKeyPressed(Keyboard::Enter) && this->Optional == 0) {
		return 0;
	}
	//chon high score 
	if (Keyboard::isKeyPressed(Keyboard::Enter) && this->Optional == 1) {
		return 1;
	}
	//chon instruction
	if (Keyboard::isKeyPressed(Keyboard::Enter) && this->Optional == 2) {
		return 2;
	}
	//chon exit
	if (Keyboard::isKeyPressed(Keyboard::Enter) && this->Optional == 3) {
		return 3;
	}
	//kochon
	return -1;
}

void Menu::drawMenuList(RenderWindow & window)
{
	//ve list menu gom cac infor
	int n = this->MenuList.size();
	this->update();
	window.clear();
	for (int i = 0; i < n; i++) {
		window.draw(this->MenuList[i]);
	}
	window.display();
}

void Menu::update()
{
	//update menu
	for (int i = 0; i < this->MenuList.size(); i++) {
		MenuList[i].setFillColor(sf::Color::Yellow);
		MenuList[i].setCharacterSize(50);
		if (i == this->Optional) {
			MenuList[i].setFillColor(sf::Color::White);
			MenuList[i].setCharacterSize(70);
		}
	}
}

Menu::Menu()
{
	//khoi tao menu
	my_font.loadFromFile("Assets/Font/MarkerFelt.ttf");
	sf::Text play_opt;
	this->MenuList.resize(4);
	MenuList[0].setFont(my_font);
	MenuList[0].setString("Play");
	MenuList[0].setFillColor(sf::Color::Yellow);
	MenuList[0].setCharacterSize(40);
	MenuList[0].setPosition(350, 150);

	MenuList[1].setFont(my_font);
	MenuList[1].setString("High Score");
	MenuList[1].setFillColor(sf::Color::Yellow);
	MenuList[1].setCharacterSize(40);
	MenuList[1].setPosition(350, 300);


	MenuList[2].setFont(my_font);
	MenuList[2].setString("Instruction");
	MenuList[2].setFillColor(sf::Color::Yellow);
	MenuList[2].setCharacterSize(40);
	MenuList[2].setPosition(350, 450);

	MenuList[3].setFont(my_font);
	MenuList[3].setString("Exit");
	MenuList[3].setFillColor(sf::Color::Yellow);
	MenuList[3].setCharacterSize(40);
	MenuList[3].setPosition(350, 600);
	this->Optional = 0;
}


Menu::~Menu()
{
}




