#include "game.h"
void game::init()
{
	// khoi tao cac obj nhu ball paddle bar , ..
	int n = 20;
	object *temp = NULL;
	for (int i = 0; i < n; i++) {
		switch (i)
		{
		case 1:
			temp = new ball(300, 580, 10, -2, 0, 1, 2, 20, 20, "images/ball.png");
			this->objArr.push_back(temp);
			break;
		case 2:
			temp = new paddle(300, 600, 10, 150, "images/playerpaddle.png");
			this->objArr.push_back(temp);
			break;
		
		case 4:
			temp = new bar(5, 400, 800, 10, "images/leftbar.png");
			this->objArr.push_back(temp);
			break;
		case 5:
			temp = new bar(300, 795, 10, 600, "images/bottombar.png");
			this->objArr.push_back(temp);
			break;
		case 6:
			temp = new bar(595, 400, 800, 10, "images/rightbar.png");
			this->objArr.push_back(temp);
			break;
			////////////////Khoi tao brick//////////////////////
		case 7:
			temp = new brick(140, 100,50,80, 3,20, "images/brick_3.png");
			this->objArr.push_back(temp);
			break;
		case 8:
			temp = new brick(300, 100, 50, 80, 3, 20, "images/brick_3.png");
			this->objArr.push_back(temp);
			break;
		case 9:
			temp = new brick(460, 100, 50, 80, 3, 20, "images/brick_3.png");
			this->objArr.push_back(temp);
			break;
		case 10:
			temp = new brick(220, 150, 50, 80, 3, 20, "images/brick_3.png");
			this->objArr.push_back(temp);
			break;
		case 11:
			temp = new brick(380, 150, 50, 80, 3, 20, "images/brick_3.png");
			this->objArr.push_back(temp);
			break;
		case 12:
			temp = new brick(140, 200, 50, 80, 3, 20, "images/brick_3.png");
			this->objArr.push_back(temp);
			break;
		case 13:
			temp = new brick(300, 200, 50, 80, 3, 20, "images/brick_3.png");
			this->objArr.push_back(temp);
			break;
		case 14:
			temp = new brick(460, 200, 50, 80, 3, 20, "images/brick_3.png");
			this->objArr.push_back(temp);
			break;
		case 15:
			temp = new bar(300, 5, 10, 600, "images/topbar.png");
			this->objArr.push_back(temp);
			break;
		/*case 0:
			temp = new boardgame(1032/2,684/2,684,1032,"images/background.png");
			this->objArr.push_back(temp);
			break;
		case 1:
			temp = new player(632, 80, 72, 72, 0, "images/0.png");
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
			temp = new paddle(40,684/2,100,25,"images/leftpaddle.png");
			this->objArr.push_back(temp);
			break;
		case 7:
			temp = new paddle(1032-40, 684 / 2, 100, 25,"images/rightpaddle.png");
			this->objArr.push_back(temp);
			break;
		case 8:
			temp = new player(400,80,72,72,0, "images/0.png");
			this->objArr.push_back(temp);
			break;
		case 9:
			temp = new ball(1032 / 2, 684 / 2, 10, 0.32, 0, 1,5, 20, 20, "images/ball.png");
			this->objArr.push_back(temp);
			break;
		default:
			break;*/

		}
	}
	//khoi tao man hinh menu defaul = -1
}

void game::run()
{
	RenderWindow window(VideoMode(800	,800), "Pong Game!");
	window.setKeyRepeatEnabled(false);
	Clock clock;
	float timer = 0, delay = 0.01;
	while (window.isOpen())
	{
		////// draw  ///////
		Event e;
		while (window.pollEvent(e))
		{
			if (e.type == Event::Closed) {
				window.close();
			}
			if (checkScreen == -1) {
				this->main_Menu.drawMenuList(window);
				this->checkScreen = this->main_Menu.Optional_choose(e);
			}
			if (e.type == Event::KeyPressed && e.key.code == sf::Keyboard::Escape) {
				this->checkScreen = -1;
			}
		}

		if (checkScreen == 0) {
			round = 1;
			this->PLAYER.setPlayerType("Player");
			this->prepareForMap1();
			this->Map1();
		}
		// computer choi 
		if (this->checkScreen == 1) {
			this->showHighScore();
			
		}
		//high score
		if (this->checkScreen == 2) {
			this->Instruction();
		}
		if (3 == this->checkScreen) {
			window.close();
		}

		
		//Back lai man hinh chinh
		this->checkScreen = -1;
		
	}
		// Man hinh menu chinh

}

void game::render(RenderWindow& window, bool IsComputer)
{
	if (!IsComputer) {
		window.clear();
		//////////////////render info game//////////////////
		//reder score
		this->renderNumberofRound(window);
		this->renderPlayerScore(window);
		this->renderSpeedUpTime(window);
		this->renderDoubleTime(window);
		/////////////////


		// render cac object //
		int n = this->objArr.size(); // so object
		for (int i = 0; i < n; i++) {
			Texture tempTexture;
			pos tempPos;
			//Load hinh anh
			tempTexture.loadFromFile(this->objArr[i]->getImglink());
			tempTexture.setSmooth(true);
			//Set position object
			Sprite tempSprite(tempTexture);
			tempPos.x = this->objArr[i]->getPosition().x - this->objArr[i]->getWeight() / 2;
			tempPos.y = this->objArr[i]->getPosition().y - this->objArr[i]->getHeight() / 2;
			tempSprite.setPosition(tempPos.x, tempPos.y);
			window.draw(tempSprite);
		}
		window.display();
	}
	else {
		window.clear();
		//reder score
		this->renderPlayerScore(window);
		// render cac object
		int n = this->objArr.size(); // so object
		for (int i = 0; i < n; i++) {
			Texture tempTexture;
			pos tempPos;
			//Load hinh anh
			tempTexture.loadFromFile(this->objArr[i]->getImglink());
			tempTexture.setSmooth(true);
			//Set position object
			Sprite tempSprite(tempTexture);
			tempPos.x = this->objArr[i]->getPosition().x - this->objArr[i]->getWeight() / 2;
			tempPos.y = this->objArr[i]->getPosition().y - this->objArr[i]->getHeight() / 2;
			tempSprite.setPosition(tempPos.x, tempPos.y);
			window.draw(tempSprite);
		}
		window.display();

	}
	

}

void game::objMove()
{
	
	int n = this->objArr.size();
	//update cac chuyen dong obj
	for (int i = 0; i < n; i++)
	{
		this->objArr[i]->move(this->objArr,this->PLAYER,time);
	}
	
	//check xem co gach nao xoa chua
	int k = 0;
	while (k < n) {
		if (this->objArr[k]->getImglink() == "") {
			this->objArr.erase(objArr.begin() + k);
			n = this->objArr.size();
		}
		else {
			k++;
		}
		
	}
}

void game::renderPlayerScore(RenderWindow & window)
{

		Font my_font;
		my_font.loadFromFile("Assets/Font/MarkerFelt.ttf");
		sf::Text play_opt;
		//hien chu score
		Text Score;
		Score.setFont(my_font);
		Score.setString("SCORE ");
		Score.setFillColor(sf::Color::Yellow);
		Score.setCharacterSize(40);
		Score.setPosition(650, 100);

		//hien diem
		Text Player_Score;

		Player_Score.setFont(my_font);
		string getPlayerscore = to_string(this->PLAYER.getScore()); // chuyen tu so sang chuoi
		Player_Score.setString(getPlayerscore);
		Player_Score.setFillColor(sf::Color::Red);
		Player_Score.setCharacterSize(30);
		Player_Score.setPosition(690, 180);


		window.draw(Score);
		window.draw(Player_Score);
	
}

void game::renderSpeedUpTime(RenderWindow& window)
{

	Font my_font;
	my_font.loadFromFile("Assets/Font/MarkerFelt.ttf");
	sf::Text play_opt;
	//hien chu Speed up
	Text SpeedUp;
	SpeedUp.setFont(my_font);
	SpeedUp.setString("Speed up");
	SpeedUp.setFillColor(sf::Color::Yellow);
	SpeedUp.setCharacterSize(30);
	SpeedUp.setPosition(650, 300);

	//hien diem

	Text SpeedUptime;

	SpeedUptime.setFont(my_font);
	string getPlayerscore = to_string(10-this->PLAYER.getSpeedUpTime()); // chuyen tu so sang chuoi
	SpeedUptime.setString(getPlayerscore);
	SpeedUptime.setFillColor(sf::Color::Yellow);
	SpeedUptime.setCharacterSize(25);
	SpeedUptime.setPosition(670, 350);
	if (this->PLAYER.getSpeedUp() == true) {
		window.draw(SpeedUptime);
		window.draw(SpeedUp);
	}
}

void game::renderDoubleTime(RenderWindow& window)
{
	Font my_font;
	my_font.loadFromFile("Assets/Font/MarkerFelt.ttf");
	sf::Text play_opt;
	//hien chu Doutble Score
	Text Double;
	Double.setFont(my_font);
	Double.setString("Double Score");
	Double.setFillColor(sf::Color::Yellow);
	Double.setCharacterSize(30);
	Double.setPosition(650, 400);

	//hien diem

	Text Doubletime;

	Doubletime.setFont(my_font);
	string getPlayerscore = to_string(10 - this->PLAYER.getDoulbeTime()); // chuyen tu so sang chuoi
	Doubletime.setString(getPlayerscore);
	Doubletime.setFillColor(sf::Color::Yellow);
	Doubletime.setCharacterSize(25);
	Doubletime.setPosition(670, 450);
	if (this->PLAYER.getDoulbe() == true) {
		window.draw(Doubletime);
		window.draw(Double);
	}
}

void game::renderNumberofRound(RenderWindow& window)
{
	Font my_font;
	my_font.loadFromFile("Assets/Font/MarkerFelt.ttf");
	sf::Text play_opt;
	//hien chu Round
	Text Round;
	Round.setFont(my_font);
	Round.setString("Round");
	Round.setFillColor(sf::Color::Yellow);
	Round.setCharacterSize(30);
	Round.setPosition(650, 40);

	//hien diem

	Text RoundNumber;

	RoundNumber.setFont(my_font);
	string getPlayerscore = to_string(round); // chuyen tu so sang chuoi
	RoundNumber.setString(getPlayerscore);
	RoundNumber.setFillColor(sf::Color::Yellow);
	RoundNumber.setCharacterSize(30);
	RoundNumber.setPosition(750, 40);
		window.draw(Round);
		window.draw(RoundNumber);
}

bool game::checkBrickIsExist()
{
	int n = this->objArr.size();
	for (int i = 0; i < n; i++) {
		if (objArr[i]->getObjectName() == "brick") {
			return true;
		}
	}
	return false;
}

void game::saveScore()
{
	sf::RenderWindow window(sf::VideoMode(800, 800), "Pong Game");
	sf::Font font;
	font.loadFromFile("Assets/Font/MarkerFelt.ttf");
	sf::Event event;
	sf::String playerInput;
	//////////khoi tao cac text hien len khi save diem///////////
	sf::Text playerText("",font,30);
	sf::Text INPUTNAME("INPUT YOU NAME :", font, 30);
	Text YOUWIN("YOU WIN !!!!!!!!!", font, 30);
	Text YOULOSE("YOU LOSE !!!!!!!!!", font, 30);
	///////////set up vi tri/////////////////
	YOULOSE.setPosition(350, 100);
	YOUWIN.setPosition(350, 100);
	YOUWIN.setFillColor(sf::Color::Yellow);
	YOULOSE.setFillColor(sf::Color::Yellow);
	INPUTNAME.setPosition(50, 200);
	playerText.setPosition(300, 200);
	playerText.setFillColor(sf::Color::Red);
	////////////Nhap ten///////////////
	while (window.isOpen())
	{
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::TextEntered)
			{
				if (event.text.unicode < 128)
				{
					playerInput += event.text.unicode;
					playerText.setString(playerInput);
				}
			}
			//bam enter de luu ten
			if (Keyboard::isKeyPressed(Keyboard::Enter)) {
				this->PLAYER.setName(playerInput);
				this->HighScore.push_back(PLAYER);
				this->SortHighScore();
				this->PLAYER.reset();
				this->showHighScore();
				return;
			}
			// xoa ki tu
			if (Keyboard::isKeyPressed(Keyboard::Backspace))
			{
				int n = playerInput.getSize();// lay do dai cua chuoi nhap vao
				string s;// tao chuoi tam
				// chuoi nhap vao co do dai lon hon  = 1
				if (n > 0) {
					//tao chuoi moi co do dai n-1
					s.resize(n - 1);
					// gan lai chuoi moi
					for (int i = 0; i < n - 1; i++) {
						s[i] = playerInput[i];
					}
					//gan chuoi nhap vao bang chuoi moi
					playerInput = s;
				}
			}
			/*if (Keyboard::isKeyPressed(Keyboard::X)) {
				window.close();
				return;
			}*/
		}

		////////xuat ra //////////
		window.clear();
		//dieu kien hien chu YOU WIN
		if (this->PLAYER.getcheckENDGAME() == false) {
			window.draw(YOUWIN);
			//dieu kien hien chu YOU LOSE
		}else{
			window.draw(YOULOSE);
		}
		window.draw(INPUTNAME);
		window.draw(playerText);
		window.display();
	}
}

void game::prepareForMap1()
{
	//xoa het de tao cac obj moi
	this->objArr.clear();
	// khoi tao cac obj nhu ball paddle bar , ..
	int n = 20;
	object *temp = NULL;
	for (int i = 0; i < n; i++) {
		switch (i)
		{
		case 1:
			temp = new paddle(300, 600, 10, 150, "images/playerpaddle.png");
			this->objArr.push_back(temp);
			break;
		case 2:
			temp = new ball(300, 580, 10, -1.5, 0, 1, 2, 20, 20, "images/ball.png");
			this->objArr.push_back(temp);
			break;

		case 4:
			temp = new bar(5, 400, 800, 10, "images/leftbar.png");
			this->objArr.push_back(temp);
			break;
		case 5:
			temp = new bar(300, 795, 10, 600, "images/bottombar.png");
			this->objArr.push_back(temp);
			break;
		case 6:
			temp = new bar(595, 400, 800, 10, "images/rightbar.png");
			this->objArr.push_back(temp);
			break;
			////////////////Khoi tao brick//////////////////////
		case 7:
			temp = new brick(140, 100, 50, 80, 3, 20, "images/brick_3.png");
			this->objArr.push_back(temp);
			break;
		case 8:
			temp = new brick(300, 100, 50, 80, 3, 20, "images/brick_3.png");
			this->objArr.push_back(temp);
			break;
		case 9:
			temp = new brick(460, 100, 50, 80, 3, 20, "images/brick_3.png");
			this->objArr.push_back(temp);
			break;
		case 10:
			temp = new brick(220, 150, 50, 80, 3, 20, "images/brick_3.png");
			this->objArr.push_back(temp);
			break;
		case 11:
			temp = new brick(380, 150, 50, 80, 3, 20, "images/brick_3.png");
			this->objArr.push_back(temp);
			break;
		case 12:
			temp = new brick(140, 200, 50, 80, 3, 20, "images/brick_3.png");
			this->objArr.push_back(temp);
			break;
		case 13:
			temp = new brick(300, 200, 50, 80, 3, 20, "images/brick_3.png");
			this->objArr.push_back(temp);
			break;
		case 14:
			temp = new brick(460, 200, 50, 80, 3, 20, "images/brick_3.png");
			this->objArr.push_back(temp);
			break;
		case 16:
			temp = new bar(300, 5, 10, 600, "images/topbar.png");
			this->objArr.push_back(temp);
			break;
		}
	}

	//khoi tao player
	this->PLAYER.setScore(0);
	this->PLAYER.setcheckENDGAME(false);
	this->PLAYER.setDouble(false);
	this->PLAYER.setSpeedUp(false);
	//test
	this->addSpeedUpItem();
	//khoi tao man hinh menu defaul = -1
	this->checkScreen = -1;
}


void game::prepareForMap2()
{
	//xoa het de tao cac obj moi
	this->objArr.clear();
	// khoi tao cac obj nhu ball paddle bar , ..
	int n = 25;
	object *temp = NULL;
	for (int i = 0; i < n; i++) {
		switch (i)
		{
		case 1:
			temp = new paddle(300, 600, 10, 150, "images/playerpaddle.png");
			this->objArr.push_back(temp);
			break;
		case 2:
			temp = new ball(300, 580, 10, -2.5, 0, 1, 1, 20, 20, "images/ball.png");
			this->objArr.push_back(temp);
			break;

		case 4:
			temp = new bar(5, 400, 800, 10, "images/leftbar.png");
			this->objArr.push_back(temp);
			break;
		case 5:
			temp = new bar(300, 795, 10, 600, "images/bottombar.png");
			this->objArr.push_back(temp);
			break;
		case 6:
			temp = new bar(595, 400, 800, 10, "images/rightbar.png");
			this->objArr.push_back(temp);
			break;
			////////////////Khoi tao brick//////////////////////
		case 7:
			temp = new brick(180, 100, 50, 80, 3, 20, "images/brick_3.png");
			this->objArr.push_back(temp);
			break;
		case 8:
			temp = new brick(420, 100, 50, 80, 3, 20, "images/brick_3.png");
			this->objArr.push_back(temp);
			break;
		case 9:
			temp = new brick(100, 150, 50, 80, 3, 20, "images/brick_3.png");
			this->objArr.push_back(temp);
			break;
		case 10:
			temp = new brick(260, 150, 50, 80, 3, 20, "images/brick_3.png");
			this->objArr.push_back(temp);
			break;
		case 11:
			temp = new brick(340, 150, 50, 80, 3, 20, "images/brick_3.png");
			this->objArr.push_back(temp);
			break;
		case 12:
			temp = new brick(500, 150, 50, 80, 3, 20, "images/brick_3.png");
			this->objArr.push_back(temp);
			break;
		case 13:
			temp = new brick(100, 200, 50, 80, 3, 20, "images/brick_3.png");
			this->objArr.push_back(temp);
			break;
		case 14:
			temp = new brick(500, 200, 50, 80, 3, 20, "images/brick_3.png");
			this->objArr.push_back(temp);
			break;
		case 15:
			temp = new brick(180, 250, 50, 80, 3, 20, "images/brick_3.png");
			this->objArr.push_back(temp);
			break;
		case 16:
			temp = new brick(420, 250, 50, 80, 3, 20, "images/brick_3.png");
			this->objArr.push_back(temp);
			break;
		case 17:
			temp = new brick(260, 300, 50, 80, 3, 20, "images/brick_3.png");
			this->objArr.push_back(temp);
			break;
		case 18:
			temp = new brick(340, 300, 50, 80, 3, 20, "images/brick_3.png");
			this->objArr.push_back(temp);
			break;
		case 19:
			temp = new wall(300, 400, 50, 300, "images/wall_50x300.png");
			this->objArr.push_back(temp);
			break;
		case 20:
			temp = new bar(300, 5, 10, 600, "images/topbar.png");
			this->objArr.push_back(temp);
			break;
		}
	}
	//khoi tao player
	this->PLAYER.setcheckENDGAME(false);
	this->PLAYER.setDouble(false);
	this->PLAYER.setSpeedUp(false);
	//test
	this->addSpeedUpItem();
	//khoi tao man hinh menu defaul = -1
	this->checkScreen = -1;
}

void game::Map2()
{
	RenderWindow window(VideoMode(800, 800), "Pong Game!");
	Clock clock;
	float timer = 0, delay = 0.01;
	float itemTime = 0;
	bool checkPause = false;
	while (window.isOpen())
	{
		////// draw  ///////
		Event e;
		while (window.pollEvent(e))
		{
			if (e.type == Event::Closed)
				window.close();
			if (e.type == Event::KeyPressed) {
				if (e.key.code == sf::Keyboard::Escape) {
					window.close();
					return;
				}
				if (e.key.code == sf::Keyboard::Space) {
					checkPause = !checkPause;
				}
			}
		}
		if (checkPause == false) {
			float time = clock.getElapsedTime().asSeconds();
			clock.restart();
			timer += time;

			itemTime = itemTime + timer; // tinh time de hien item
			//tinh time cho Double Item
			if (PLAYER.getDoulbe() == true) {
				PLAYER.setDoubleTime(PLAYER.getDoulbeTime() + timer);
				if (PLAYER.getDoulbe() > 10) {
					this->PLAYER.setDouble(false);
					PLAYER.setDoubleTime(0);
				}
			}

			//tinh time cho SpeedUp Item
			if (PLAYER.getSpeedUp() == true) {
				PLAYER.setSpeedUpTime(PLAYER.getSpeedUpTime() + timer);
				if (PLAYER.getSpeedUpTime() > 10) {
					this->PLAYER.setSpeedUp(false);
					PLAYER.setSpeedUpTime(0);
				}
			}

			//tao item random moi 5 s
			if (itemTime > 5) {
				this->GenerateItem();
				itemTime = 0;
			}
			if (timer > delay) {
				this->objMove();
				timer = 0;
			}
			//xong man 2 qua man 3
			if (this->checkBrickIsExist() == false) {
				round++;
				this->prepareForMap3();
				this->Map3();
				window.close();
				return;
			};
			//bi thua
			if (PLAYER.getcheckENDGAME() == false) {
				this->render(window);
			}
			else {
				if (this->PLAYER.getTyperPlayer() != "Computer") {
					this->saveScore();
				}
				this->checkScreen = -1;
				PLAYER.setcheckENDGAME(false);
				window.close();
				return;
			}
		}
	}
}

void game::prepareForMap3()
{
	//xoa het de tao cac obj moi
	this->objArr.clear();
	// khoi tao cac obj nhu ball paddle bar , ..
	int n = 25;
	object *temp = NULL;
	for (int i = 0; i < n; i++) {
		switch (i)
		{
		case 1:
			temp = new paddle(300, 600, 10, 150, "images/playerpaddle.png");
			this->objArr.push_back(temp);
			break;
		case 2:
			temp = new ball(300, 580, 10, 1.5, 0, 1, 2, 20, 20, "images/ball.png");
			this->objArr.push_back(temp);
			break;

		case 4:
			temp = new bar(5, 400, 800, 10, "images/leftbar.png");
			this->objArr.push_back(temp);
			break;
		case 5:
			temp = new bar(300, 795, 10, 600, "images/bottombar.png");
			this->objArr.push_back(temp);
			break;
		case 6:
			temp = new bar(595, 400, 800, 10, "images/rightbar.png");
			this->objArr.push_back(temp);
			break;
			////////////////Khoi tao brick//////////////////////
		case 7:
			temp = new brick(300, 150, 50, 80, 3, 20, "images/brick_3.png");
			this->objArr.push_back(temp);
			break;
		case 8:
			temp = new brick(220, 200, 50, 80, 3, 20, "images/brick_3.png");
			this->objArr.push_back(temp);
			break;
		case 9:
			temp = new brick(380, 200, 50, 80, 3, 20, "images/brick_3.png");
			this->objArr.push_back(temp);
			break;
		case 10:
			temp = new brick(300, 250, 50, 80, 3, 20, "images/brick_3.png");
			this->objArr.push_back(temp);
			break;
		case 11:
			temp = new wall(140, 100, 50, 80, "images/wall_50x80.png");
			cout << temp->getPosition().x;
			this->objArr.push_back(temp);
			break;
		case 12:
			temp = new wall(460, 100, 50, 80, "images/wall_50x80.png");
			this->objArr.push_back(temp);
			break;
		case 13:
			temp = new wall(460, 300, 50, 80, "images/wall_50x80.png");
			this->objArr.push_back(temp);
			break;
		case 14:
			temp = new wall(140, 300, 50, 80, "images/wall_50x80.png");
			this->objArr.push_back(temp);
			break;
		case 20:
			temp = new bar(300, 5, 10, 600, "images/topbar.png");
			this->objArr.push_back(temp);
			break;
		}
	}
	//khoi tao player
	this->PLAYER.setScore(0);
	this->PLAYER.setcheckENDGAME(false);
	this->PLAYER.setDouble(false);
	this->PLAYER.setSpeedUp(false);
	//test
	this->addSpeedUpItem();
	//khoi tao man hinh menu defaul = -1
	this->checkScreen = -1;
}

void game::Map3()
{
	RenderWindow window(VideoMode(800, 800), "Pong Game!");
	Clock clock;
	float timer = 0, delay = 0.01;
	float itemTime = 0;
	bool checkPause = false;
	while (window.isOpen())
	{
		////// draw  ///////
		Event e;
		while (window.pollEvent(e))
		{
			if (e.type == Event::Closed)
				window.close();
			if (e.type == Event::KeyPressed) {
				if (e.key.code == sf::Keyboard::Escape) {
					window.close();
					return;
				}
				if (e.key.code == sf::Keyboard::Space) {
					checkPause = !checkPause;
				}
			}
		}
		if (checkPause == false) {
			float time = clock.getElapsedTime().asSeconds();
			clock.restart();
			timer += time;

			itemTime = itemTime + timer; // tinh time de hien item
			//tinh time cho Double Item
			if (PLAYER.getDoulbe() == true) {
				PLAYER.setDoubleTime(PLAYER.getDoulbeTime() + timer);
				if (PLAYER.getDoulbe() > 10) {
					this->PLAYER.setDouble(false);
					PLAYER.setDoubleTime(0);
				}
			}

			//tinh time cho SpeedUp Item
			if (PLAYER.getSpeedUp() == true) {
				PLAYER.setSpeedUpTime(PLAYER.getSpeedUpTime() + timer);
				if (PLAYER.getSpeedUpTime() > 10) {
					this->PLAYER.setSpeedUp(false);
					PLAYER.setSpeedUpTime(0);
				}
			}

			//tao item random moi 5 s
			if (itemTime > 5) {
				this->GenerateItem();
				itemTime = 0;
			}
			if (timer > delay) {
				this->objMove();
				timer = 0;
			}
			//xong man 3 xong game
			if (this->checkBrickIsExist() == false) {
				if (this->PLAYER.getTyperPlayer() != "Computer") {
					this->saveScore();
				}
				this->checkScreen = -1;
				PLAYER.setcheckENDGAME(false);
				window.close();
				return;
			};
			//bi thua
			if (PLAYER.getcheckENDGAME() == false) {
				this->render(window);
			}
			else {
				this->saveScore();
				this->checkScreen = -1;
				PLAYER.setcheckENDGAME(false);
				window.close();
				return;
			}
		}
	}
}

void game::Map1( )
{
	RenderWindow window(VideoMode(800, 800), "Pong Game!");
	Clock clock;
	float timer = 0, delay = 0.01;
	float itemTime=0;
	bool checkPause = false;
	while (window.isOpen())
	{
		////// draw  ///////
		Event e;
		while (window.pollEvent(e))
		{
			if (e.type == Event::Closed)
				window.close();
			if (e.type == Event::KeyPressed) {
				if (e.key.code == sf::Keyboard::Escape) {
					window.close();
					return;
				}
				if (e.key.code == sf::Keyboard::Space) {
					checkPause = !checkPause;
				}
			}
		}
		if (checkPause == false) {
			float time = clock.getElapsedTime().asSeconds();
			clock.restart();
			timer += time;

			itemTime = itemTime + timer; // tinh time de hien item
			//tinh time cho Double Item
			if (PLAYER.getDoulbe() == true) {
				PLAYER.setDoubleTime(PLAYER.getDoulbeTime() + timer);
				if (PLAYER.getDoulbe() > 10) {
					this->PLAYER.setDouble(false);
					PLAYER.setDoubleTime(0);
				}
			}

			//tinh time cho SpeedUp Item
			if (PLAYER.getSpeedUp() == true) {
				PLAYER.setSpeedUpTime(PLAYER.getSpeedUpTime() + timer);
				if (PLAYER.getSpeedUpTime() > 10) {
					this->PLAYER.setSpeedUp(false);
					PLAYER.setSpeedUpTime(0);
				}
			}

			//tao item random moi 5 s
			if (itemTime > 5) {
				this->GenerateItem();
				itemTime = 0;
			}
			if (timer > delay) {
				this->objMove();
				timer = 0;
			}
			//xong man 1 qua man 2
			if (this->checkBrickIsExist() == false) {
				round++;
				this->prepareForMap2();
				this->Map2();
				window.close();
				return;
			};
			//bi thua
			if (PLAYER.getcheckENDGAME() == false) {
				this->render(window);
			}
			//save score
			else {
				if (this->PLAYER.getTyperPlayer() != "Computer") {
					this->saveScore();
				}
				this->checkScreen = -1;
				PLAYER.setcheckENDGAME(false);
				window.close();
				return;
			}
		}
	}
}

void game::showHighScore()
{
	//sort lai highscore
	this->SortHighScore();
	//lay top 10
	int n = this->HighScore.size();
	int Top5;
	if (n > 5) {
		Top5 = 5;
	}
	else {
		Top5 = n;
	}

	// set Font
	Font my_font;
	my_font.loadFromFile("Assets/Font/MarkerFelt.ttf");
	sf::Text tempText; // text tam de render

	//hien thi 

	sf::RenderWindow window(sf::VideoMode(800, 800), "Pong Game");
	while (window.isOpen())
	{
		////// draw  ///////
		Event e;
		while (window.pollEvent(e))
		{
			if (e.type == Event::Closed)
				window.close();
			if (e.type == Event::KeyPressed) {
				if (e.key.code == sf::Keyboard::Escape) {
					this->checkScreen = -1;
					window.close();
					return;
				}
			}
		}
		//render RANK
		tempText.setFont(my_font);
		tempText.setString("RANK");
		tempText.setFillColor(sf::Color::Red);
		tempText.setCharacterSize(50);
		tempText.setPosition(350, 100);
		window.draw(tempText);
		//reder "NAME" && "SCORE" && TOP

		int pXName = 300, pXScore = 500, pXTOP = 100, pY = 200;

		//TOP
		tempText.setFont(my_font);
		tempText.setString("TOP");
		tempText.setFillColor(sf::Color::Red);
		tempText.setCharacterSize(40);
		tempText.setPosition(pXTOP, pY);
		window.draw(tempText);

		//NAME
		tempText.setFont(my_font);
		tempText.setString("NAME");
		tempText.setFillColor(sf::Color::Red);
		tempText.setCharacterSize(40);
		tempText.setPosition(pXName, pY);
		window.draw(tempText);
		//SCORE

		tempText.setFont(my_font);
		tempText.setString("SCORE");
		tempText.setFillColor(sf::Color::Red);
		tempText.setCharacterSize(40);
		tempText.setPosition(pXScore, pY);
		window.draw(tempText);
		//////////////////////////


		//render player name and score
		for (int i = 0; i < Top5; i++) {
			//	//dat lai toa do
			pY = pY + 70;

			// render TOP
			tempText.setFont(my_font);
			string TOP = to_string(i+1); // chuyen tu so sang chuoi
			tempText.setString(TOP);
			tempText.setFillColor(sf::Color::Yellow);
			tempText.setCharacterSize(30);
			tempText.setPosition(pXTOP + 10, pY);
			window.draw(tempText);

			//	//render player name
			tempText.setFont(my_font);
			tempText.setString(this->HighScore[i].getName());
			tempText.setFillColor(sf::Color::Yellow);
			tempText.setCharacterSize(30);
			tempText.setPosition(pXName, pY);
			window.draw(tempText);

			//	//render player score
			string getPlayerscore = to_string(this->HighScore[i].getScore()); // chuyen tu so sang chuoi
			tempText.setFont(my_font);
			tempText.setString(getPlayerscore);
			tempText.setFillColor(sf::Color::Yellow);
			tempText.setCharacterSize(30);
			tempText.setPosition(pXScore, pY);
			window.draw(tempText);
		}


		window.display();
		// thoat show highscore
	}
		
}

void game::SortHighScore()
{
	int n = this->HighScore.size();
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (this->HighScore[i].getScore() < this->HighScore[j].getScore()) {
				player tempPlayer= this->HighScore[i];
				this->HighScore[i] = this->HighScore[j];
				this->HighScore[j] = tempPlayer;
			}
		}
	}
}


void game::ItemPushBack(item tempItem)
{
	this->Listof_Item.push_back(tempItem);
}

void game::addSpeedUpItem()
{
	object *temp = NULL;
	int x = rand() % 500 + 50;
	int y = 0;
	int height = 30;
	int weight = 30;
	int score = 50;
	int v = 3;
	string IMGlink="images/SpeedUp.png";
	temp = new item(x, y, height, weight,v, score, IMGlink);
	this->objArr.push_back(temp);
}

void game::addDoubleItem()
{
	object *temp = NULL;
	int x = rand() % 500 + 50;
	int y = 0;
	int height = 30;
	int weight = 30;
	int score = 50;
	int v = 3;
	string IMGlink = "images/Double.png";
	temp = new item(x, y, height, weight, v, score, IMGlink);
	this->objArr.push_back(temp);
}

void game::addScoreUpItem()
{
	object *temp = NULL;
	int x = rand() % 500 + 50;
	int y = 0;
	int height = 30;
	int weight = 30;
	int score = 50;
	int v = 3;
	string IMGlink = "images/ScoreUp.png";
	temp = new item(x, y, height, weight, v, score, IMGlink);
	this->objArr.push_back(temp);
}

void game::addScoreDownItem()
{
	object *temp = NULL;
	int x = rand() % 650 + 50;
	int y = 0;
	int height = 30;
	int weight = 30;
	int score = -50;
	int v = 3;
	string IMGlink = "images/ScoreDown.png";
	temp = new item(x, y, height, weight, v, score, IMGlink);
	this->objArr.push_back(temp);
}

void game::GenerateItem()
{
	int random = ((rand() % 10 + 1) - 1) % 4;
	/*
		randdom = 0 thi tao ra speedUp
		randdom = 1 thi tao ra Double
		randdom = 2 thi tao ra ScoreUp
		randdom = 3 thi tao ra ScoreDown

	*/
	if (random == 0) {
		this->addSpeedUpItem();
	}
	if (random == 1) {
		this->addDoubleItem();
	}
	if (random == 2) {
		this->addScoreUpItem();
	}
	if (random == 3) {
		this->addScoreDownItem();
	}
}
void game::Instruction()
{
	sf::RenderWindow window(sf::VideoMode(800, 800), "Instruction");
	while (window.isOpen())
	{
		////// draw  ///////
		Event e;
		while (window.pollEvent(e))
		{
			if (e.type == Event::Closed)
				window.close();
			if (e.type == Event::KeyPressed) {
				//chay game map 1 do computer play
				this->PLAYER.setPlayerType("Computer");
				this->prepareForMap1();
				this->Map1();

				if (e.key.code == sf::Keyboard::Escape) {
					window.close();
					return;
				}
			}
		}

		Font my_font;
		my_font.loadFromFile("Assets/Font/MarkerFelt.ttf");
		sf::Text tempText1;
		tempText1.setFont(my_font);
		tempText1.setString("USE LEFT AND RIGHT ARROW TO MOVE THE PADDLE IN ORDER TO CATCH BALL");
		tempText1.setFillColor(sf::Color::Red);
		tempText1.setCharacterSize(25);
		tempText1.setPosition(15, 200);
		window.draw(tempText1);

		sf::Text tempText2;
		tempText2.setFont(my_font);
		tempText2.setString("ALL OF BRICKS ARE BROKEN, YOU WIN. CAN'T CATCH THE BALL,YOU LOSE");
		tempText2.setFillColor(sf::Color::Red);
		tempText2.setCharacterSize(25);
		tempText2.setPosition(15, 300);
		window.draw(tempText2);

		sf::Text tempText3;
		tempText3.setFont(my_font);
		tempText3.setString("PRESS ANY KEY TO SEE HOW TO PLAY");
		tempText3.setFillColor(sf::Color::Red);
		tempText3.setCharacterSize(25);
		tempText3.setPosition(15, 400);
		window.draw(tempText3);
		window.display();
	}
}

game::game()
{
	ifstream fileInput("data/highscore.txt");
	if (fileInput.fail())
	{
		std::cout << "Failed to open this file!" << endl;
		return;
	}
	char temp[255];
	int score;
	player tempPlayer;
	string SScore;
	while (!fileInput.eof())
	{
		fileInput.getline(temp, 255);
		tempPlayer.setName(temp);
		fileInput.getline(temp, 255);
		 SScore= temp;
		 score = stoi(SScore);
		tempPlayer.setScore(score);
		this->HighScore.push_back(tempPlayer);
	}
	fileInput.close();
	this->checkScreen = -1;
}

game::~game()
{
	fstream outfile;
	outfile.open("data/highscore.txt", ios::out);
	int n = this->HighScore.size();
	int Top10;
	if (n > 10) {
		Top10 = 10;
	}
	else {
		Top10 = n;
	}
	for (int i = 0; i < Top10; i++) {
		outfile << this->HighScore[i].getName()<<endl;
		if (i != Top10 - 1) {
			outfile << this->HighScore[i].getScore() << endl;
		}
		else {
			outfile << this->HighScore[i].getScore() ;
		}
	}
}


