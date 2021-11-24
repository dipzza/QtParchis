#include "board.h"

Board::Board() :
    dice(Dice())
{

}

Board::Board(int n_players) :
    dice(Dice())
{
    if (n_players == 2) {
        players.push_back(new Player(Color::Red));
        players.push_back(new Player(Color::Yellow));
    } else {
        for (int i=0; i < n_players; ++i) {
            players.push_back(new Player(static_cast<Color>(i)));
        }
    }

    for(int i=0; i < n_players; ++i) {
        std::vector<Cell> color_cells;
        for(int j=0; j < 8; ++j) {
            color_cells.push_back(Cell());
        }
        base_cells.push_back(color_cells);
    }

    for(int i=0; i < BOARD_SIZE; ++i) {
        cells.push_back(Cell());
    }

    dice.roll();
}

Board::~Board()
{
    for (auto& player : players)
        delete player;
}

void Board::nextTurn()
{
    current_player_idx = (current_player_idx + 1) % players.size();
    dice.roll();
}

Dice &Board::getDice()
{
    return dice;
}

const std::vector<Player *> &Board::getPlayers() const
{
    return players;
}

const Player* Board::getCurrentPlayer() const
{
    return players.at(current_player_idx);
}

Color Board::getCurrentPlayerColor()
{
    return getCurrentPlayer()->getColor();
}
