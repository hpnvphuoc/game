#include"game.h"
void main() {
	//game Ponggame;
	//Ponggame.init();
	//Ponggame.run();
	//paddle a(40, 684 / 2, 100, 25, "images/leftpaddle.png", 30);
	//a.moveUp();
	//cout << a.getPosition().y << endl;

	//a.moveUp();

	//cout << a.getPosition().y << endl;
	//a.moveUp();
	//cout << a.getPosition().y << endl;
	 
	RenderWindow window(VideoMode(1032, 684), "Pong Game!");
	while (window.isOpen())
	{

		////// draw  ///////
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
			// The escape key was pressed
			if (event.type == sf::Event::EventType::KeyPressed)
				cout << "Key is pressed" << endl;
			else {
				if (event.type == sf::Event::EventType::KeyReleased)
					cout << "Key is released";
			}

		}

	}
	system("pause");

}