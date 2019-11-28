#ifndef MENU_H_
#define MENU_H_

#include "pre.h"
#include "Screen.h"

class Menu {
    private:
        int choice;
        int highlight;
        string choices[4];

    public:
        void setChoice(int a) {
            choice = a;
        }
        int getChoice() {
            return choice;
        }
        void setHighLight(int a) {
            highlight = a;
        }
        int getHighLight() {
            return highlight;
        }

        Menu() {
            setChoice(0);
            setHighLight(0);
            choices[0] = "Human vs Human";
            choices[1] = "Human vs Com";
            choices[2] = "Intruction";
            choices[3] = "Quit";
        }
        ~Menu(){}

        int runMenu() {
            Screen screen;
            erase();
            refresh();

            FILE *file = fopen("title.txt", "r");
            char *str = new char[100];
            int count = 0;
            while (fgets(str, 100, file)) {
                mvaddstr(count++, 0, str);
            }

            while (true) {
                for (int i = 0; i < 4; i++) {
                    if (i == highlight) {
                        attron(A_REVERSE);
                    }
                    mvprintw(13 + i, 35, choices[i].c_str());
                    attroff(A_REVERSE);
                }

                choice = getch();
                switch (choice) {
                    case KEY_UP:
                        highlight--;
                        if(highlight == -1) {
                            highlight = 0;
                        }
                        break;

                    case KEY_DOWN:
                        highlight++;
                        if (highlight == 4) {
                            highlight = 3;
                        }
                        break;

                    default:
                        break;
                }

                if (choice == 10) {
                    break;
                }
            }
            endwin();
            return highlight;
        }
};

#endif // MENU_H_