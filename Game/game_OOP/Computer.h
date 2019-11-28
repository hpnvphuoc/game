#ifndef COMPUTER_H_
#define COMPUTER_H_

#include "Ball.h"
#include "Player.h"
#include "pre.h"
#include "unistd.h"
#include "time.h"

class Computer: public Player {
    public:
        Computer(int x, int y): Player(x, y){}
        ~Computer(){}

        // void runComputer(Ball &ball) {
        //     if(speed >=70){
        //             if(ball.getY() > getY() + 2 && ball.getX() > widthPlayBox / 2) {
        //                 setY(ball.getY() - 1);
        //             }
        //             if(ball.getY() < getY() - 2 && ball.getX() > widthPlayBox / 2) {
        //                 setY(ball.getY() + 1);
        //             }
        //     } 
        //     else {
        //         if(ball.getDir() == 3 && ball.getX() > widthPlayBox / 2) {
        //             if(getY() > 5 && getY() < 35) {
        //                 setY(getY() - 1);
        //             }

        //         } 
        //         else if (ball.getDir() == 4 && ball.getX() > widthPlayBox / 2) {
        //             if (getY() > 5 && getY() < 35) {
        //                 setY(getY() + 1);
        //             }
        //         }
        //     }
        // }

        void runComputer(Ball &ball) {
            // if (ball.getX() > widthPlayBox / 2 + widthPlayBox / 4 + widthPlayBox / 11 && (ball.getDir() == 3 || ball.getDir() == 4)) {
            //     if (ball.getY() > getY() && getY() != heightPlayBox + 5 - 3) {
            //         setY(getY() + 1);
            //     }
            //     else if (ball.getY() < getY() && getY() != 3 + 5) {
            //         setY(getY() - 1);
            //     }
            // }
        }

        void printWinner(Player player1) {
            system("clear");
            if (player1.getScore() == 3) {
                FILE *file = fopen("playerWon.txt", "r");
                char *str = new char[50];
                while (fgets(str, 50, file)) {
                    cout << str;
                }
                fclose(file);
            }
            else {
                FILE *file = fopen("computerWon.txt", "r");
                char *str = new char[50];
                while (fgets(str, 50, file)) {
                    cout << str;
                }
                fclose(file);
            }
        }
};

class Computer
{
};

#endif // COMPUTER_H_