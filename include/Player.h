#ifndef INCLUDE_PLAYER_H
#define INCLUDE_PLAYER_H



class Player
{
private:
    static inline int s_id { 1 };
    int m_id {};

    bool m_playing { false };
    bool m_won { false };

    char m_symbol { ' ' };

public:
    Player(char symbol);
    ~Player();

    int getId() { return m_id; }
    void nowPlaying(bool p) { m_playing = p; }
    void setWin() { m_won = true; } 
    bool hasWon() { return m_won; }
    char getSymbol() { return m_symbol; }
};

#endif