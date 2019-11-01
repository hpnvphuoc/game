#include "Menu.h"




int Menu::Optional_choose()
{
	//di chuyen len xuong
	if (Keyboard::isKeyPressed(Keyboard::Up)) {
		this->Optional = this->Optional - 1;
		// ko cho chay qua 0
		if (this->Optional < 0) {
			this->Optional = 0;
		}
	}
	if (Keyboard::isKeyPressed(Keyboard::Down)) {
		this->Optional = this->Optional + 1;
		//ko cho chay qua 1
		if (this->Optional > 1) {
			this->Optional = 1;
		}
	}
	// chon play
	if (Keyboard::isKeyPressed(Keyboard::Enter) && this->Optional == 0) {
		return 0;
	}
	//chon about
	if (Keyboard::isKeyPressed(Keyboard::Enter) && this->Optional == 1) {
		return 1;
	}
	//kochon
	return -1;
}

void Menu::drawMenuList(RenderWindow & window)
{
	//ve list menu gom play va about
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
		MenuList[i].setFillColor(sf::Color::Red);
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
	this->MenuList.resize(3);
	MenuList[0].setFont(my_font);
	MenuList[0].setString("Play");
	MenuList[0].setFillColor(sf::Color::Red);
	MenuList[0].setCharacterSize(50);
	MenuList[0].setPosition(450, 200);


	MenuList[1].setFont(my_font);
	MenuList[1].setString("About");
	MenuList[1].setFillColor(sf::Color::Red);
	MenuList[1].setCharacterSize(50);
	MenuList[1].setPosition(450, 200 + 200);

	this->Optional = 0;
}


Menu::~Menu()
{
}




