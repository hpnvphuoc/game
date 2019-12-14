#include "game.h"



void game::init()
{
	int n = 10;
	object *temp = NULL;
	for (int i = 0; i < n; i++) {
		switch (i)
		{
		case 0:
			temp = new boardgame(1032/2,684/2,684,1032,"images/background.png");
			this->objArr.push_back(temp);
			break;
		case 1:
			temp = new ball(1032 / 2, 684 / 2, 10, 0.32, 0, 1, 5, 20, 20, "images/ball.png");
			this->objArr.push_back(temp);
			break;
		case 2:
			temp = new bar(1032 / 2, 13 / 2, 13, 1032, "images/topbar.png");
			this->objArr.push_back(temp);
			break;
		case 3:
			temp = new bar(13 / 2, 684 / 2, 684, 13, "images/leftbar.png");
			this->objArr.push_back(temp);
			break;
		case 4:
			temp = new bar(1032 / 2, 684 - 13 / 2, 13, 1032, "images/bottombar.png");
			this->objArr.push_back(temp);
			break;
		case 5:
			temp = new bar(1032 - 13 / 2, 684 / 2, 684, 13, "images/rightbar.png");
			this->objArr.push_back(temp);
			break;
		case 6:
			temp = new paddle(40,684/2,100,25,"images/leftpaddle.png",30,2);
			this->objArr.push_back(temp);
			break;
		case 7:
			temp = new paddle(1032-40, 684 / 2, 100, 25,"images/rightpaddle.png",30,1);
			this->objArr.push_back(temp);
			break;
		case 8:
			temp = new player(400,80,72,72,0, "images/0.png");
			this->objArr.push_back(temp);
			break;
		case 9:
			temp = new player(632, 80, 72, 72, 0, "images/0.png");
			this->objArr.push_back(temp);
			break;
		default:
			break;
		}
	}
	
}

void game::run()
{
	RenderWindow window(VideoMode(1032	,684), "Pong Game!");
	Clock clock;
	float timer = 0, delay = 0.01;
	int t = 0;
	while (window.isOpen())
	{

		////// draw  ///////
		Event e;
		while (window.pollEvent(e))
		{
			if (e.type == Event::Closed)
				window.close();
		}

		float time = clock.getElapsedTime().asSeconds();
		clock.restart();
		timer += time;
		if (timer > delay) {
			if (e.type == sf::Event::EventType::KeyPressed) {
				t++;
				if (t > 30) t = 30;
			}
			else {
				if (e.type == sf::Event::EventType::KeyReleased) {
					t--;
					if (t < 0) t = 0;
				}
					
			}
			this->objMove(t);
		}
		this->render(window);
	}
}

void game::render(RenderWindow& window)
{
	window.clear();
	//this->SpriteArr.clear();
	int n = this->objArr.size(); // so object
	for (int i = 0; i < n; i++) {
		Texture tempTexture;
		pos tempPos;
		//Load hinh anh
		tempTexture.loadFromFile(this->objArr[i]->getImglink());
		//Set position object
		Sprite tempSprite (tempTexture);
		tempPos.x = this->objArr[i]->getPosition().x - this->objArr[i]->getWeight() / 2;
		tempPos.y = this->objArr[i]->getPosition().y - this->objArr[i]->getHeight() / 2;
		tempSprite.setPosition(tempPos.x, tempPos.y);
		window.draw(tempSprite);
	}
	window.display();

}

void game::objMove(int t)
{
	
	int n = this->objArr.size();
	
	for (int i = 0; i < n; i++)
	{
		this->objArr[i]->move(this->objArr,t);
	}
}

