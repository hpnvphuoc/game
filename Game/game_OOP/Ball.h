#ifndef BALL_H_
#define BALL_H_

#include "pre.h"
#include "Player.h"

class Ball {
    private:
        double x, y;
        int dir;

    public:
        double getX() {
            return x;
        }
        double getY() {
            return y;
        }
        void setX(double a) {
            x = a;
        }
        void setY(double a) {
            y = a;
        }
        void setDir(int a) {
            dir = a;
        }
        int getDir() {
            return dir;
        }

        Ball(double x, double y) {
            setX(x);
            setY(y);
            setDir(3);
        }
        ~Ball(){}

        void drawBall(double x, double y) {
            mvaddch(y, x, 'o');
        }

        // xử lý đường đi của bóng trong mode human vs human
        void logic(Player &player1, Player &player2) {
            /*
            * 3 - Right Up
            * 4 - Right down
            * 5 - Left Up
            * 6 - Left down
            * 
            *      5 left-up _______________________ right-up 3
            *               |                       |
            *               |                       |
            *               |                       |
            *               |                       |
            *               |_______________________|
            *      6 left-down                       right-down 4
            */

            // bóng chạm biên của player1 or chạm thanh đỡ của player1
            if (getX() == player1.getX() + 1 || getX() == player1.getX()) {  
                // nếu bóng nằm trên thanh đỡ
                if (getY() <= player1.getY() + 2 && getY() >= player1.getY() - 2) {  
                    if (getDir() == 5) {
                        setDir(3);
                    } 
                    else if (getDir() == 6) {
                        setDir(4);
                    }
                    if(speed > 20){
                        speed -= 10;
                    }
                }
            }
            // bóng chạm biên của player2 or chạm thanh đỡ của player2
            if(getX() == player2.getX() - 1  || getX() == player2.getX()) {
                // nếu bóng nằm trên thanh đỡ
                if(getY() <= player2.getY() + 2 && getY() >= player2.getY() - 2) {
                    if(getDir() == 3) {
                        setDir(5);
                    } 
                    else if (getDir() == 4) {
                        setDir(6);
                    }
                    if(speed > 20){
                        speed -= 10;
                    }
                }
            }

            // nếu bóng chạm biên dưới (+5 bởi vì chiều cao của ô chứa điểm = 5)
            if(getY() == heightPlayBox - 1 + 5) {
                if (getDir() == 6)
                    setDir(5);
                else
                    setDir(3);
            }

            // nếu bóng chạm biên trên
            if(getY() == 5 + 1) {
                if(getDir() == 5) {
                    setDir(6);
                }
                else {
                    setDir(4);
                }
            }

            // nếu bóng chạm được vào biên trái thì player2 ăn điểm 
            if(getX() == 0) {
                player2.setScore(player2.getScore() + 1);
                player1.setPlayerServe(true);
                speed = 100;
            }

            // nếu bóng chạm được vào biên phải thì player1 ăn điểm
            if(getX() == widthPlayBox) {
                player1.setScore(player1.getScore() + 1);
                player2.setPlayerServe(true);
                speed = 100;
            }

            // nếu là lượt chơi của player1 thì đặt bóng vào vị trí của player1
            if(player1.getPlayerServe()) {
                setX(player1.getX() + 1);
                setY(player1.getY());
            }

            // nếu là lượt chơi của player2 thì đặt bóng vào vị trí của player2
            if(player2.getPlayerServe()) {
                setX(player2.getX() - 1);
                setY(player2.getY());
            }

            // Vị trí bóng 
            if(!player1.getPlayerServe() || !player2.getPlayerServe()) {
                float x, y;
                x = 1;
                y = 1;

                if(getDir() == 3) {
                    setX(getX() + x);
                    setY(getY() - y);
                }
                if(getDir() == 4) {
                    setX(getX() + x);
                    setY(getY() + y);
                }
                if(getDir() == 5) {
                    setX(getX() -x);
                    setY(getY() -y);
                }
                if(getDir() == 6) {
                    setX(getX() - x);
                    setY(getY() + y);
                }
            }
        }
};
#endif // BALL_H_