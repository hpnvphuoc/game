#ifndef SCREEN_H_
#define SCREEN_H_

#include "pre.h"
#include "Player.h"
#include "Ball.h"

class Screen {
    protected:
        void setup() {
            // Init ncurses
            initscr();
            cbreak();
            noecho();
            curs_set(0);
            keypad(stdscr, TRUE);
            timeout(speed);
        }
    public:
        Screen() {
            setup();
        }

        void draw(Player player1, Player player2, Ball ball, int mode) {
            erase();
            // refresh();

            mvprintw(37, 30, "%s", info1);
            mvprintw(38, 30, "%s", info2);
            mvprintw(39, 30, "%s", info3);

            for (int i = 0; i < heightScoreBox; i++) {
                for (int j = 0; j < 10; j++) {
                    mvaddch(i, j, 'x');
                    mvaddch(i, j + 40, 'x');
                    mvaddch(i, j + 50, 'x');
                    mvaddch(i, j + 90, 'x');
                }
                mvaddch(i, 0, wallChar3);
                mvaddch(i, 10, wallChar3);
                mvaddch(i, 39, wallChar3);
                mvaddch(i, 60, wallChar3);
                mvaddch(i, 89, wallChar3);
                mvaddch(i, 99, wallChar3);
            }

            for (int i = 0; i < heightPlayBox; i++) {
                mvaddch(i + 5, 0, wallChar3);
                mvaddch(i + 5, widthPlayBox / 2, wallChar2);
                mvaddch(i + 5, 99, wallChar3);
            }

            for (int i = 0; i < heightInfoBox; i++) {
                for (int j = 0; j < 20; j++) {
                    mvaddch(i + 35, j, 'x');
                    mvaddch(i + 35, j + 80, 'x');
                }
                mvaddch(i + 35, 0, wallChar3);
                mvaddch(i + 35, 99, wallChar3);
                mvaddch(i + 35, 20, wallChar3);
                mvaddch(i + 35, 79, wallChar3);
            }

            // erase();
            refresh();

            for (int i = 0; i < widthPlayBox; i++) {
                mvaddch(0, i, wallChar1);
                mvaddch(5, i, wallChar4);
                mvaddch(35, i, wallChar4);
                mvaddch(40, i, wallChar1);
            }

            if (mode == 0) {
                mvprintw(3, 20, "Player1: %i", player1.getScore());
                mvprintw(3, 70, "Player2: %i", player2.getScore());
            }
            else if (mode == 1) {
                mvprintw(3, 20, "Player: %i", player1.getScore());
                mvprintw(3, 70, "Computer: %i", player2.getScore());
            }

            player1.drawPlayer(player1.getY(), player1.getX());
            player2.drawPlayer(player2.getY(), player2.getX());
            ball.drawBall(ball.getX(), ball.getY());
        }
};
#endif // SCREEN_H_