#include "pre.h"
#include "Screen.h"
#include "Control.h"
#include "Menu.h"
#include "Computer.h"

void humanVsHuman() {

    Player player1 = Player(1, heightPlayBox / 2 + 5);
    Player player2 = Player(98, heightPlayBox / 2 + 5);
    Ball ball = Ball(2, player1.getY());
    Control control;

    while (!quit) {
        Screen *screen = new Screen;
        control.input(player1, player2, ball);
        ball.logic(player1, player2);
        screen->draw(player1, player2, ball, 0);
        if (player1.getScore() == 3 || player2.getScore() == 3) {
            break;
        }
        delete screen;
    }

    endwin();

    if (quit == false) {
        player2.printWinner(player1);
    }

    quit = false;

    player1.~Player();
    player2.~Player();
    ball.~Ball();
}

void humanVsCom() {

    Player player1 = Player(1, heightPlayBox / 2 + 5);
    Computer player2 = Computer(98, heightPlayBox / 2 + 5);
    Ball ball = Ball(2, player1.getY());
    Control control;

    while (!quit) {
        Screen *screen = new Screen;
        control.input(player1, player2, ball);
        player2.runComputer(ball);
        ball.logic(player1, player2);
        screen->draw(player1, player2, ball, 1);
        if (player1.getScore() == 3 || player2.getScore() == 3) {
            break;
        }
        delete screen;
    }

    endwin();

    if (quit == false) {
        player2.printWinner(player1);
    }

    quit = false;

    player1.~Player();
    player2.~Computer();
    ball.~Ball();
}

int main(int argc, char const *argv[]) {
    // resize_term( 40, 41);
    // // is_term_resized(40, 40);
    // start_color();

    MENU: Menu menu;

    int a = menu.runMenu();
    switch (a) {
        // 0: play: human vs human
        case 0: {
            system("clear");
            humanVsHuman();
            cout << "\n\nBam phim bat ky de tiep tuc game\n";
            cin.ignore(1);
            // system( "read -n 1 -s -p \"Nhan phim bat ky de tiep tuc...\"" );
            endwin();
            menu.~Menu();
            goto MENU;
        } break;

        // 1: play: human vs com
        case 1: {
            system("clear");
            humanVsCom();
            cout << "\n\nBam phim bat ky de tiep tuc game\n";
            cin.ignore(1);
            // delete menu;
            endwin();
            menu.~Menu();
            // system( "read -n 1 -s -p \"Nhan phim bat ky de tiep tuc...\"");
            goto MENU;
        } break;

        // 2: intruction
        case 2: {
            system("clear");
            cout << "Player 1 dieu khien thanh do len xuong bang cac phim 'w' va 's' de hung bong.\n";
            cout << "Player 2 dieu khien thanh do len xuong bang cac phim mui ten len xuong de hung bong.\n";
            cout << "Bam phim'space' de giao bong\n";
            cout << "Khi mot trong hai nguoi co so diem bang 3 thi nguoi do thang va ket thuc game.\n";
            cout << "Trong luc choi game, bam phim 'q' de thoat game.\n";
            cout << "\n\nBam phim bat ky de tiep tuc game\n";
            cin.ignore(1);
            // delete menu;
            // system( "read -n 1 -s -p \"Nhan phim bat ky de tiep tuc...\"" );
            endwin();
            menu.~Menu();
            goto MENU;
        } break;

        // 3: quit
        case 3: {
            system("clear");
            menu.~Menu();
            return 0;
        } break;
    }

    return 0;
}
