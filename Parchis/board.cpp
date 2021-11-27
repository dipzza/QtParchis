#include "board.h"

Board::Board() :
    dice(Dice())
{

}

Board::Board(int n_players) :
    dice(Dice()), current_player_idx(0)
{
    // Initialize players
    if (n_players == 2) {
        players.push_back(new Player(Color::Red));
        players.push_back(new Player(Color::Yellow));
    } else {
        for (int i=0; i < n_players; ++i) {
            players.push_back(new Player(static_cast<Color>(i)));
        }
    }

    // Initialize board cells
    for(int i=0; i < n_players; ++i) {
        std::vector<Cell *> color_cells;
        for(int j=0; j < 7; ++j) {
            color_cells.push_back(new Cell());
        }
        color_cells.push_back(new Cell(8));
        base_cells.push_back(color_cells);
    }

    for(int i=0; i < BOARD_SIZE; ++i) {
        cells.push_back(new Cell());
    }

    // Initialize possible movements for first turn (Only valid to get out of nest)
    dice.roll();

    bool leaving_nest = false;

    if (dice.getLastRoll() == 5) {
        for (auto token : getCurrentPlayer()->getTokens()) {
            if (token->inNest()) {
                if (token->calculateMove(dice.getLastRoll(), getCurrentPlayerCells())) {
                    leaving_nest = true;
                }
            }
        }
    }

    if (!leaving_nest) {
        nextTurn();
    }
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
    // Clear last turn calculated moves
    for (auto token : getCurrentPlayer()->getTokens()) {
        token->clearMoveCalculation();
    }

    // Change to next player and roll the dice
    current_player_idx = (current_player_idx + 1) % players.size();
    dice.roll();

    // Calculate which moves can the current player do
    bool can_move = false;
    bool leaving_nest = false;

    if (dice.getLastRoll() == 5) {
        for (auto token : getCurrentPlayer()->getTokens()) {
            if (token->inNest()) {
                if (token->calculateMove(dice.getLastRoll(), getCurrentPlayerCells())) {
                    leaving_nest = true;
                    can_move = true;
                }
            }
        }
    }

    if (!leaving_nest) {
        for (auto token : getCurrentPlayer()->getTokens()) {
            if (token->calculateMove(dice.getLastRoll(), getCurrentPlayerCells())) {
                can_move = true;
            }
        }
    }

    if (!can_move) {
        nextTurn();
    }
}

const Dice &Board::getDice() const
{
    return dice;
}

const std::vector<Player *> &Board::getPlayers() const
{
    return players;
}

Player* Board::getCurrentPlayer() const
{
    return players.at(current_player_idx);
}

Color Board::getCurrentPlayerColor() const
{
    return getCurrentPlayer()->getColor();
}

std::vector<Cell *> Board::getCurrentPlayerCells() const
{
    std::vector<Cell *> color_cells = cells;
    color_cells.insert(color_cells.end(), base_cells[current_player_idx].begin(), base_cells[current_player_idx].end());
    return color_cells;
}
