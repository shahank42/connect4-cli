#include "../include/Connect4Board.h"



// Constructor initializes the Connect 4 board every time when a Connect4Board
// object is intialized.
Connect4Board::Connect4Board(Player& playerOne, Player& playerTwo, int width, int height)
    : m_playerOne { playerOne }, m_playerTwo { playerTwo }, m_width { width }, m_height { height }
{
    for (auto& column : m_columns)
    {
        column.resize(m_height);
        column = {};
    }
}


Connect4Board::~Connect4Board()
{

}


// Checks to see if there are more coins in a column than the maximum amount
// it can hold, for every single column.
bool Connect4Board::checkValidNextMove(int col)
{
    std::string newState {};
    for (int colNum { 1 }; colNum < (m_width + 1); ++colNum)
    {
        newState =  (m_state + std::to_string(col));
        int currColCount { static_cast<int>(std::count(newState.begin(), newState.end(), (colNum + '0'))) };

        if (currColCount > m_height)
            return false;
    }

    return true;
}


// Places coin in the provided column and updates the board
void Connect4Board::nextMove(int col)
{
    m_state += std::to_string(col);
    updateBoardStructure();
}


// Set each column of the board to an empty vector
void Connect4Board::clearBoard()
{
    for (auto& column : m_columns)
        column = {};
}


// Updates the display of the board according to the state string
void Connect4Board::updateBoardStructure()
{
    clearBoard();

    for (int i {}; i < m_state.length(); ++i)
        m_columns.at(m_state[i] - '0' - 1).push_back( ((i % 2) == 0) ? m_playerOne.getSymbol() : m_playerTwo.getSymbol() );
}


// Check the 2-D board matrix to see if the indicated player has indeed four in
// a row, a column or a diagonal
bool Connect4Board::checkPlayerWon(Player& player)
{
    char sym { player.getSymbol() };

    // horizontal check
    for (int j { }; j < (m_height - 3); ++j)
        for (int i { }; i < m_width; ++i)
            if ( (m_columns[i][j] == sym) && (m_columns[i][j+1] == sym) && (m_columns[i][j+2] == sym) && (m_columns[i][j+3] == sym) )
                return true;

    // vertical check
    for (int i { }; i < (m_width - 3); ++i)
        for (int j { }; j < m_height; ++j)
            if ( (m_columns[i][j] == sym) && (m_columns[i+1][j] == sym) && (m_columns[i+2][j] == sym) && (m_columns[i+3][j] == sym) )
                return true;

    // ascending diagonal check
    for (int i { 3 }; i < m_width; ++i)
        for (int j { 0 }; j < (m_height - 3); ++j)
            if ( (m_columns[i][j] == sym) && (m_columns[i-1][j+1] == sym) && (m_columns[i-2][j+2] == sym) && (m_columns[i-3][j+3] == sym) )
                return true;

    // descending diagonal check
    for (int i { 3 }; i < m_width; ++i)
        for (int j { 3 }; j < m_height; ++j)
            if ( (m_columns[i][j] == sym) && (m_columns[i-1][j-1] == sym) && (m_columns[i-2][j-2] == sym) && (m_columns[i-3][j-3] == sym) )
                return true;

    return false;
}


// Draw the board to the terminal through an ASCII rendition
void Connect4Board::drawBoard()
{
    for (int row { static_cast<int>(m_columns[0].capacity()) }; row-- > 0; )
    {
        for (int col {}; col < m_columns.size(); ++col)
        {
            if (m_columns[col][row])
                std::cout << "(" << m_columns[col][row] << ")";
            else
                std::cout << " . ";
        }

        std::cout << "\n";
    }

    std::cout << "\n";

    for (int i {}; i < m_columns.size(); ++i)
        std::cout << " " << (i + 1) << " ";

    std::cout << "\n";
}


// This entire function handles the prompt for getting the input, along with
// error validation.
int Connect4Board::getNextMoveInput()
{
    std::string userColString {};
    int userCol {};
    
    while (true)
    {
        std::cout << "\n" << getCurrentPlayer() << "> ";
        std::cin >> userColString;

        if (!std::cin || std::cin.fail() || std::cin.eof() || (userColString.find_first_not_of("0123456789") != std::string::npos))
        {
            std::cerr << "What are you even typing? Let's try that again.";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        std::string::size_type st;

        try
        {
            userCol = std::stoi(userColString, &st);
        }
        catch (const std::out_of_range& err)
        {
            std::cerr << "Don't go and overflow the memory! Let's try that again.";
            continue;
        }


        if ((userCol < 1) || (userCol > m_width))
        {
            std::cerr << "Invalid column number! Let's try that again.";
            continue;
        }

        if (!checkValidNextMove(userCol))
        {
            std::cerr << "No more room in column " << userCol << "! Let's try that again.";
            continue;
        }

        break;
    }


    return userCol;
}


// Checks both players to see if any of them have won the game
// in the current state of the board.
bool Connect4Board::checkForWinner()
{
    if (checkPlayerWon(m_playerOne) || checkPlayerWon(m_playerTwo))
    {
        nextPlayer();
        return true;
    }

    return false;
}