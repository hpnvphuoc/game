#ifndef CONTROL_H_
#define CONTROL_H_

#include "Player.h"
#include "pre.h"
#include "Ball.h"
#include "Computer.h"

class Control {
    private:
        int ch;

    public:
        void input(Player &player1, Player &player2, Ball &ball) {
            ch = getch();
            switch(ch) {
                case KEY_UP: {
                    if(player2.getY() != 3 + 5) {
                        player2.setY(player2.getY() - 1);
                    }
                } break;
                case KEY_DOWN: {
                    if(player2.getY() != heightPlayBox + 5 - 3) {
                        player2.setY(player2.getY() + 1);
                    }
                } break;

                case 'w': {
                    if(player1.getY() != 3 + 5) {
                        player1.setY(player1.getY() - 1);
                    }
                } break;
                case 's': {
                    if(player1.getY() != heightPlayBox + 5 - 3) {
                        player1.setY(player1.getY() + 1);
                    }
                } break;

                case ' ': {
                    if(player1.getPlayerServe()) {
                        player1.setPlayerServe(false);
                        ball.setDir(3);
                    }
                    else if(player2.getPlayerServe()) {
                        player2.setPlayerServe(false);
                        ball.setDir(6);
                    }
                } break;

                case 'q': {
                    quit = true;
                } break;
            }
        }

        void input(Player &player1, Computer &com, Ball &ball) {
            ch = getch();
            switch (ch) {
                case 'w': {
                    if(player1.getY() != 3 + 5) {
                        player1.setY(player1.getY() - 1);
                    }
                } break;
                case 's': {
                    if(player1.getY() != heightPlayBox + 5 - 3) {
                        player1.setY(player1.getY() + 1);
                    }
                } break;

                case ' ': {
                    if(player1.getPlayerServe()) {
                        player1.setPlayerServe(false);
                        ball.setDir(3);
                    }
                } break;

                case 'q': {
                    quit = true;
                } break;
            }
            if(com.getPlayerServe()) {
                com.setPlayerServe(false);
                ball.setDir(6);
            }
        }
};

class Control
{
};

#endif // CONTROL_H_