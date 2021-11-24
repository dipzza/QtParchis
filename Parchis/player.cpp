#include "player.h"

Player::Player(Color p_color)
{
    color = p_color;
    for (int i=0; i < 4; ++i) {
        tokens.push_back(new Token(i, p_color));
    }
}

Player::~Player() {
    for (auto& token : tokens)
        delete token;
}

Color Player::getColor() const
{
    return color;
}

const std::vector<Token *> &Player::getTokens() const
{
    return tokens;
}


//Player::Player()
//{

//}
