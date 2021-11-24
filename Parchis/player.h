#ifndef PLAYER_H
#define PLAYER_H

#include <vector>
#include "token.h"

class Player
{
public:
    Player();
    Player(Color p_color);
    ~Player();


    Color getColor() const;


    const std::vector<Token *> &getTokens() const;

private:
    Color color;
    std::vector<Token *> tokens;
    unsigned int finishedPawns = 0;
};

#endif // PLAYER_H
