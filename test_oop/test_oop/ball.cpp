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
	p.x = x; // toa do x
	p.y = y; // toa do y
	this->height = height; //  chieu cao
	this->weight = weight; // chieu dai
	this->a = float(a);  // goa toa do trong y=ax + b
	this->b = float(p.y) - float(a) * p.x; // b trong y=ax + b
	this->r = r; // ban kinh qua banh
	this->direction = direction;  // huong chay qua banh
	this->v = v;  // van toc qua banh
}


pos ball::getPosition()
{
	return this->p;
}

void ball::move(vector<object *>&list, player &PLAYER, float time)
{
	// TH nhat duoc vat pham speedUp thi tang toc do len 1.5
	if (PLAYER.getSpeedUp() == true) {
		p.x = p.x + v*1.5;
	}
	else {
		p.x = p.x + v;
	}
	p.y = a * p.x + b;
	int n = list.size();
	// xet va cham cac obj khac nhu trai, phai, gach , tuong
	for (int i = 0; i < n; i++) {
		// xet va cham voi thanh phai
		if (list[i]->getObjectName() == "rightbar") {
			conlisionRightbar(list[i]->getPosition(), list[i]->getHeight(), list[i]->getWeight());
		}
		// xet va cham voi thanh tren
		if (list[i]->getObjectName() == "topbar") {
			conlisionTopbar(list[i]->getPosition(), list[i]->getHeight(), list[i]->getWeight());
		}
		// xet va cham voi thanh ben trai
		if (list[i]->getObjectName() == "leftbar") {
			conlisionLeftbar(list[i]->getPosition(), list[i]->getHeight(), list[i]->getWeight());
		}
		// xet va cham voi thanh truot
		if (list[i]->getObjectName() == "playerpaddle") {
			conlisionPaddle(list[i]->getPosition(), list[i]->getHeight(), list[i]->getWeight());
		}
		//xet va cham voi thanh duoi -> neu dung thanh duoi la thua
		if (list[i]->getObjectName() == "bottombar") {
			if (conlisionBottombar(list[i]->getPosition(), list[i]->getHeight(), list[i]->getWeight()) == true) {
				PLAYER.setcheckENDGAME(true);
			}
		}
		// xet va cham voi obj "wall"
		if (list[i]->getObjectName() == "wall") {
			conlisionWall(list[i]->getPosition(), list[i]->getHeight(), list[i]->getWeight());
		}
		// xet va cham voi obj "brick"
		if (list[i]->getObjectName() == "brick") {
			if (conlisionBrick(list[i]->getPosition(), list[i]->getHeight(), list[i]->getWeight()) == true) {
				//this->breakBrick(i, list);
			}
		}
	}
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
	// xet xem phan tren cua qua banh co nho hon phan duoi cua thanh tren hay ko
	if (p.y - height/2 < TopbarPos.y+TopbarHeight/2) {
		//TH biet y
		int tempy = height / 2 + TopbarPos.y + TopbarHeight / 2; // gan tam y
		b = 2 * tempy - b; // tim b trong duong thang moi y= -ax +b'
		a = -a;
		v = v
			;
	}
}

bool ball::conlisionBottombar(pos BottombarPos, float bottombarHeight, float bottomWeight)
{
	// xet xem phan duoi cua qua banh co lon hon phan tren cua thanh duoi hay ko
	if (p.y + height / 2 > BottombarPos.y - bottombarHeight / 2) {
		return true; // tra ve true false de xet thua 
	}
	return false;
}

void ball::conlisionRightbar(pos RightbarPos, float RightbarHeight, float RightbarWeight)
{
	//xet xem ben phai cua trai banh co lon hon ben trai cua thanh phai hay ko
	if (p.x + weight / 2 > RightbarPos.x - RightbarWeight / 2) {
		if (p.y + height / 2 > RightbarPos.y - RightbarHeight / 2 && p.y - height / 2 < RightbarPos.y + RightbarHeight / 2) 
			{
				//TH da biet x
				int tempx = -weight / 2 + RightbarPos.x - RightbarWeight / 2; // gan tam x
				b = 2 * tempx*a + b;// tim b trong duong thang moi y= -ax +b'
				a = -a;
				v = -v; //do va cham phai lam x giam nen v doi dau
			}
		}
}
void ball::conlisionLeftbar(pos LeftbarPos, float LeftbarHeight, float LeftbarWeight)
{
	//xet xem ben trai cua trai banh co nho hon ben phai cua thanh trai hay ko
	if (p.x - weight / 2 < LeftbarPos.x + LeftbarWeight / 2) {
		if (p.y + height / 2 > LeftbarPos.y - LeftbarHeight / 2 && p.y - height / 2 < LeftbarPos.y + LeftbarHeight / 2) {
			//TH da biet x
			int tempx = weight / 2 + LeftbarPos.x + LeftbarWeight / 2;
			b = 2 * tempx*a + b;// tim b trong duong thang moi y= -ax +b'
			a = -a;
			v = -v ; // do va cham trai lam x tang nen v doi dau
		}
	}
	
}

void ball::conlisionPaddle(pos PaddlePos, float PaddleHeight, float PaddleWeight)
{
	//xet xem toa do y  cua trai banh co nam giua do cao cua thanh truot hay ko
	if (p.y + height / 2 > PaddlePos.y - PaddleHeight / 2 && p.y - height / 2 < PaddlePos.y + PaddleHeight) {
		// xet xem toa do x co nam giua thanh truot hay ko
		if (p.x + weight / 2 > PaddlePos.x - PaddleWeight / 2 && p.x - weight / 2 < PaddlePos.x + PaddleWeight / 2) {
			// TH biet y
			int tempy = -height / 2 + PaddlePos.y - PaddleHeight / 2; // gan tam y
			b = tempy * 2 - b;// tim b trong duong thang moi y= -ax +b'
			a = -a;
			v = v*1.1;  // tang van toc len 1.1
		}
	};
}

void ball::conlisionWall(pos WallPos, float WallHeight, float WallWeight)
{
	// xet va cham tren duoi trai phai giong nhu va cham voi top left right bottom right bar
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
	// xet va cham tren duoi trai phai giong nhu va cham voi top left right bottom right bar
	//va cham tren
	if (p.y + height / 2 > BrickPos.y - BrickHeight / 2 && p.y + height / 2 < BrickPos.y + BrickHeight / 2) {
		if (p.x > BrickPos.x - BrickWeight / 2 && p.x < BrickPos.x + BrickWeight / 2) {
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
	list.erase(list.begin() + vitri);
}


