#ifndef PRE_H_
#define PRE_H_

#include "ncurses.h"
#include "iostream"
#include "string"
using namespace std;

#define wallChar1 '\xB2'
#define wallChar2 ':'
#define wallChar3 '|'
#define wallChar4 '-'
#define playerChar '\xB2'
#define ballChar 'o'
#define info1 "Truong DDH Khoa hoc Tu nhien - ĐHQG TP.HCM"
#define info2 "SV1: Nguyen Bao Long - MSSV: 18120201"
#define info3 "SV2: Pham Van Minh Phuong - MSSV: 18120227"

#define heightPlayBox 30
#define widthPlayBox 100

#define heightInfoBox 5

#define heightScoreBox 5

int speed = 100;

bool quit = false;

class pre
{
};

#endif // PRE_H_