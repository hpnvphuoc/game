#include "ball.h"




ball::ball()
{
}

void ball::reset()
{
	//gan vi tri trai banh o giua ban
	p.x = 300;
	p.y = 580;
	// gan lai duong thang truoc khi thua
	a = -1;
	b = p.y - a * p.x;
	v = 3*v/abs(v);// gan lai toc do ban dau 7
}

void ball::CheckScore(vector<object *>list)
{
	//// ham tinh xem ghi diem chua
	//int n = list.size();
	//// neu trai banh qua bien ben trai
	//if (this->p.x < 0) {
	//	for (int i = 0; i < n; i++) {
	//			if (list[i]->getObjectName() == "Player_Right") {
	//				list[i]->move(list); //ghi diem
	//			}
	//		}
	//	this->reset();
	//}
	//// neu trai banh ben bien ben phai
	//if (this->p.x > 1032) {
	//	for (int i = 0; i < n; i++) {
	//		if (list[i]->getObjectName() == "Player_Left") {
	//			list[i]->move(list);// ghi diem
	//		}
	//	}
	//	this->reset();
	//}
}

ball::ball(int x, int y, int r, float a, float b, int direction, float v,float height,float weight, string imgLink)
{
	// khoi tao
	this->imgLink = imgLink;
	p.x = x;
	p.y = y;
	this->height = height;
	this->weight = weight;
	this->a = float(a);
	this->b = float(p.y) - float(a) * p.x;
	this->r = r;
	this->direction = direction;
	this->v = v;
}


pos ball::getPosition()
{
	return this->p;
}

void ball::move(vector<object *>&list, player &PLAYER, float time)
{
	// xet va cham trai phai tren duoi
	p.x = p.x + v;
	p.y = a * p.x + b;
	int n = list.size();
	for (int i = 0; i < n; i++) {
		if (list[i]->getObjectName() == "rightbar") {
			conlisionRightbar(list[i]->getPosition(), list[i]->getHeight(), list[i]->getWeight());
		}
		if (list[i]->getObjectName() == "topbar") {
			conlisionTopbar(list[i]->getPosition(), list[i]->getHeight(), list[i]->getWeight());
		}
		if (list[i]->getObjectName() == "leftbar") {

			conlisionLeftbar(list[i]->getPosition(), list[i]->getHeight(), list[i]->getWeight());
		}
		if (list[i]->getObjectName() == "playerpaddle") {
			conlisionPaddle(list[i]->getPosition(), list[i]->getHeight(), list[i]->getWeight());
		}
		//thua
		if (list[i]->getObjectName() == "bottombar") {
			if (conlisionBottombar(list[i]->getPosition(), list[i]->getHeight(), list[i]->getWeight()) == true) {
				PLAYER.setcheckENDGAME(true);
			}
		}
		if (list[i]->getObjectName() == "wall") {
			conlisionWall(list[i]->getPosition(), list[i]->getHeight(), list[i]->getWeight());
		}
		if (list[i]->getObjectName() == "brick") {
			if (conlisionBrick(list[i]->getPosition(), list[i]->getHeight(), list[i]->getWeight()) == true) {
				//this->breakBrick(i, list);
			}
		}
	}

	this->CheckScore(list);
	
}

float ball::getHeight()
{
	return this->height;
}

float ball::getWeight()
{
	return this->weight;
}

string ball::getObjectName()
{
	return "ball";
}

string ball::getImglink()
{
	return this->imgLink;
}

void ball::conlisionTopbar(pos TopbarPos, float TopbarHeight, float TopbarWeight)
{
	if (p.y - height/2 < TopbarPos.y+TopbarHeight/2) {
		int tempy = height / 2 + TopbarPos.y + TopbarHeight / 2;
		b = 2 * tempy - b;;
		a = -a;
		v = v ;
	}
}

bool ball::conlisionBottombar(pos BottombarPos, float bottombarHeight, float bottomWeight)
{
	if (p.y + height / 2 > BottombarPos.y - bottombarHeight / 2) {
		return true;
	}
	return false;
}

void ball::conlisionRightbar(pos RightbarPos, float RightbarHeight, float RightbarWeight)
{
	if (p.x + weight / 2 > RightbarPos.x - RightbarWeight / 2) {
		if (p.y + height / 2 > RightbarPos.y - RightbarHeight / 2 && p.y - height / 2 < RightbarPos.y + RightbarHeight / 2) 
			{
				int tempx = -weight / 2 + RightbarPos.x - RightbarWeight / 2;
				b = 2 * tempx*a + b;
				a = -a;
				v = -v;
			}
		}
}
void ball::conlisionLeftbar(pos LeftbarPos, float LeftbarHeight, float LeftbarWeight)
{
	if (p.x - weight / 2 < LeftbarPos.x + LeftbarWeight / 2) {
		if (p.y + height / 2 > LeftbarPos.y - LeftbarHeight / 2 && p.y - height / 2 < LeftbarPos.y + LeftbarHeight / 2) {
			int tempx = weight / 2 + LeftbarPos.x + LeftbarWeight / 2;
			b = 2 * tempx*a + b;
			a = -a;
			v = -v ;
		}
	}
	
}

void ball::conlisionPaddle(pos PaddlePos, float PaddleHeight, float PaddleWeight)
{
	if (p.y + height / 2 > PaddlePos.y - PaddleHeight / 2 && p.y - height / 2 < PaddlePos.y + PaddleHeight) {
		if (p.x + weight / 2 > PaddlePos.x - PaddleWeight / 2 && p.x - weight / 2 < PaddlePos.x + PaddleWeight / 2) {
			int tempy = -height / 2 + PaddlePos.y - PaddleHeight / 2;
			b = tempy * 2 - b;
			a = -a;
			v = v;
		}
	};
}

void ball::conlisionWall(pos WallPos, float WallHeight, float WallWeight)
{
	//va cham tren
	if (p.y + height / 2 > WallPos.y - WallHeight / 2 && p.y + height / 2 < WallPos.y + WallHeight / 2) {
		if (p.x  > WallPos.x - WallWeight / 2 && p.x  < WallPos.x + WallWeight / 2) {
			int tempy = -height / 2 + WallPos.y - WallHeight / 2;
			b = tempy * 2 - b ;
			a = -a;
			v = v;
		}
	};
	//va cham duoi
	if (p.y - height / 2 < WallPos.y + WallHeight / 2 && p.y - height / 2 > WallPos.y - WallHeight / 2) {
			if (p.x  > WallPos.x - WallWeight / 2 && p.x < WallPos.x + WallWeight / 2) {
				int tempy = height / 2 + WallPos.y + WallHeight / 2;
				b = 2 * tempy - b;
				a = -a;
				v = v;
		}
	}
	//va cham  mat phai
	if (p.x - weight / 2 < WallPos.x + WallWeight / 2 && p.x - weight / 2 > WallPos.x - WallWeight / 2){
		if (p.y  > WallPos.y - WallHeight / 2 && p.y  < WallPos.y + WallHeight / 2) {
			int tempx = weight / 2 + WallPos.x + WallWeight / 2;
			b = 2 * tempx*a + b;
			a = -a;
			v = -v;
		}
	}
	//va cham mat trai
	if (p.x + weight / 2 > WallPos.x - WallWeight / 2 && p.x + weight / 2 < WallPos.x + WallWeight / 2){
		if (p.y > WallPos.y - WallHeight / 2 && p.y < WallPos.y + WallHeight / 2) {
			int tempx = -weight / 2 + WallPos.x - WallWeight / 2;
			b = 2 * tempx*a + b;
			a = -a;
			v = -v;
		}
	}
}

bool ball::conlisionBrick(pos BrickPos, float BrickHeight, float BrickWeight)
{
	//va cham tren
	if (p.y + height / 2 > BrickPos.y - BrickHeight / 2 && p.y + height / 2 < BrickPos.y + BrickHeight / 2) {
		if (p.x > BrickPos.x - BrickWeight / 2 && p.x < BrickPos.x + BrickWeight / 2) {
			cout << "ball-tren"<<endl;
			int tempy = -height / 2 + BrickPos.y - BrickHeight / 2;
			b = tempy * 2 - b;
			a = -a;
			v = v;
			return true;
		}
	};
	//va cham duoi
	if (p.y - height / 2 < BrickPos.y + BrickHeight / 2 && p.y - height / 2 > BrickPos.y - BrickHeight / 2) {
		if (p.x > BrickPos.x - BrickWeight / 2 && p.x < BrickPos.x + BrickWeight / 2) {
			cout << "ball-duoi"<<endl;
			int tempy = height / 2 + BrickPos.y + BrickHeight / 2;
			b = 2 * tempy - b;
			a = -a;
			v = v;
			return true;
		}
	}
	//va cham  mat phai
	if (p.x - weight / 2 < BrickPos.x + BrickWeight / 2 && p.x - weight / 2 > BrickPos.x - BrickWeight / 2) {
		if (p.y > BrickPos.y - BrickHeight / 2 && p.y < BrickPos.y + BrickHeight / 2) {
			cout << "ball-phai"<<endl;
			int tempx = weight / 2 + BrickPos.x + BrickWeight / 2;
			b = 2 * tempx*a + b;
			a = -a;
			v = -v;
			return true;
		}
	}
	//va cham mat trai
	if (p.x + weight / 2 > BrickPos.x - BrickWeight / 2 && p.x + weight / 2 < BrickPos.x + BrickWeight / 2) {
		if (p.y > BrickPos.y - BrickHeight / 2 && p.y < BrickPos.y + BrickHeight / 2) {
			cout << "ball-trai"<<endl;
			int tempx = -weight / 2 + BrickPos.x - BrickWeight / 2;
			b = 2 * tempx*a + b;
			a = -a;
			v = -v;
			return true;
		}
	}
	return false;
}

void ball::breakBrick(int vitri, vector<object*>& list)
{
	cout << list.size() << endl;
	cout << vitri << endl;
	
	list.erase(list.begin() + vitri);
}


