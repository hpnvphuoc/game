#ifndef PLAYER_H_
#define PLAYER_H_

#include "pre.h"

class Player {
    private:
        int x, y, score;
        bool playerServe;

    public:
        bool getPlayerServe() {
            return playerServe;
        }
        void setPlayerServe(bool a) {
            playerServe = a;
        }
        int getX() { 
            return x; 
        }
        int getY() { 
            return y; 
        }
        void setX(int a) {
            x = a;
        }
        void setY(int a) {
            y = a;
        }
        int getScore() {
            return score;
        }
        void setScore(int a) {
            score = a;
        }

        Player(int x, int y) {
            setX(x);
            setY(y);
            setScore(0);
            setPlayerServe(false);
        }
        ~Player(){}

        void drawPlayer(int y, int x) {
            mvaddch(y + 2, x, wallChar1);
            mvaddch(y + 1, x, wallChar1);
            mvaddch(y, x, wallChar1);
            mvaddch(y - 1, x, wallChar1);
            mvaddch(y - 2, x, wallChar1);
        }

        void printWinner(Player player1) {
            system("clear");
            if (player1.getScore() == 3) {
                FILE *file = fopen("player1Won.txt", "r");
                char *str = new char[50];
                while (fgets(str, 50, file)) {
                    cout << str;
                }
                fclose(file);
            }
            else {
                FILE *file = fopen("player2Won.txt", "r");
                char *str = new char[50];
                while (fgets(str, 50, file)) {
                    cout << str;
                }
                fclose(file);
            }
        }
};

class Player
{
};

#endif //  PLAYER_H_