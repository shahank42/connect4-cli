#ifndef INCLUDE_CONNECT4BOARD_H
#define INCLUDE_CONNECT4BOARD_H

#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <limits>
#include <cctype>
#include <sstream>
#include <algorithm>
#include <windows.h>

#include "Player.h"



class Connect4Board
{
private:

    bool m_playing { true };
    bool m_invalidMoveFlag { false };

    int m_width { 7 };
    int m_height { 6 };    


    Player m_playerOne {'R'};
    Player m_playerTwo {'Y'};

    std::string m_state {};

    int m_currentPlayer { };    // 0 => Player 1, 1 => Player 2

    std::array<std::vector<char>, 7> m_columns {};


    bool checkValidNextMove(int col);
    void updateBoardStructure();
    void dropAtColumn(int col);
    
public:
    Connect4Board(Player& playerOne, Player& playerTwo, int width, int height);
    ~Connect4Board();

    void drawBoard();
    void clearBoard();
    bool play();
    bool checkForWinner();
    int getNextMoveInput();
    void nextMove(int col);
    bool checkPlayerWon(Player& player);

    bool stillPlaying() { return m_playing; }
    bool checkGameDraw() { return (static_cast<int>(m_state.length()) == 42); }
    char getCurrentPlayer() { return ((m_currentPlayer == 0) ? m_playerOne.getSymbol() : m_playerTwo.getSymbol()); }
    char getWinningPlayer() { return (m_playerTwo.hasWon() ? m_playerTwo.getSymbol() : m_playerOne.getSymbol()); }
    void nextPlayer() { ++m_currentPlayer %= 2; }
    std::string getState() { return m_state; }
};

#endif // CONNECT4BOARD_H
