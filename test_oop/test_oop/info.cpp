#include "info.h"



info::info()
{
	// Khoi tao thong tin info
	my_font.loadFromFile("Assets/Font/MarkerFelt.ttf");
	sf::Text play_opt;
	this->Info_list.resize(6);
	Info_list[0].setFont(my_font);
	Info_list[0].setString("Brick Break Game!!!");
	Info_list[0].setFillColor(sf::Color::Red);
	Info_list[0].setCharacterSize(50);
	Info_list[0].setPosition(300, 100);

	Info_list[1].setFont(my_font);
	Info_list[1].setString("The author :");
	Info_list[1].setFillColor(sf::Color::Red);
	Info_list[1].setCharacterSize(50);
	Info_list[1].setPosition(300, 150);

	Info_list[2].setFont(my_font);
	Info_list[2].setString("+ Pham Tong Binh Minh");
	Info_list[2].setFillColor(sf::Color::Red);
	Info_list[2].setCharacterSize(50);
	Info_list[2].setPosition(350, 250);

	Info_list[3].setFont(my_font);
	Info_list[3].setString("+ Nguyen Van Phuoc");
	Info_list[3].setFillColor(sf::Color::Red);
	Info_list[3].setCharacterSize(50);
	Info_list[3].setPosition(350, 300);

	Info_list[4].setFont(my_font);
	Info_list[4].setString("Press X to exit");
	Info_list[4].setFillColor(sf::Color::Red);
	Info_list[4].setCharacterSize(50);
	Info_list[4].setPosition(300, 400);

}


info::~info()
{
}

void info::drawInfo(RenderWindow &window)
{
	// render info list
	int n = this->Info_list.size();
	window.clear();
	for (int i = 0; i < n; i++) {
		window.draw(this->Info_list[i]);
	}
	window.display();
}

int info::exit_info()
{
	//thoat neu click nut X
	if (Keyboard::isKeyPressed(Keyboard::X) ) {
		return -1;
	}
	return 1;
}
