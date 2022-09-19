#include <iostream>
#include <string>
#include <windows.h>

#include "include/Player.h"
#include "include/Connect4Board.h"



int main()
{
    Player player1 { 'R' };
    Player player2 { 'Y' };
    Connect4Board game { player1, player2, 7, 6 };

    // The game loop
    while (game.stillPlaying())
    {

        system("cls");
        game.drawBoard();

        if (game.checkForWinner())
            break;

        int userMove { game.getNextMoveInput() };
        game.nextMove(userMove);
        game.nextPlayer();
    }

    std::cout << "\nWinner: " << game.getCurrentPlayer() << "\n";
    std::cout << "Game:   " << game.getState() << "\n";

    std::cout << "\nPress any key to exit...";
    int _pause {};
    std::cin >> _pause;


    return 0;
}
