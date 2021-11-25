#include "board.h"

Board::Board() :
    dice(Dice())
{

}

Board::Board(int n_players) :
    dice(Dice()), current_player_idx(-1)
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
        std::vector<Cell *> color_cells;
        for(int j=0; j < 8; ++j) {
            color_cells.push_back(new Cell());
        }
        base_cells.push_back(color_cells);
    }

    for(int i=0; i < BOARD_SIZE; ++i) {
        cells.push_back(new Cell());
    }

    nextTurn();
}

Board::~Board()
{
    for (auto& player : players)
        delete player;

    for (auto& cell : cells)
        delete cell;

    for (auto& vec : base_cells) {
        for (auto& cell : vec) {
            delete cell;
        }
    }
}

void Board::nextTurn()
{
    current_player_idx = (current_player_idx + 1) % players.size();
    dice.roll();

    bool can_move = false;
    for (auto token : getCurrentPlayer()->getTokens()) {
        if (token->calculateMove(dice.getLastRoll(), getCurrentPlayerCells()) != -1) {
            can_move = true;
        }
    }
    if (!can_move) {
        nextTurn();
    }
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

Color Board::getCurrentPlayerColor() const
{
    return getCurrentPlayer()->getColor();
}

const std::vector<Cell *> Board::getCurrentPlayerCells() const
{
    std::vector<Cell *> color_cells = cells;
    int idx = static_cast<int>(getCurrentPlayerColor());
    color_cells.insert(color_cells.end(), base_cells[idx].begin(), base_cells[idx].end());
    return color_cells;
}
