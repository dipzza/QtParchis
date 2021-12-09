#include "board.h"

Board::Board() :
    dice(Dice())
{

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

void Board::initialize(int n_players)
{
    // Initialize all players
    for (int i=0; i < 4; ++i) {
        players.push_back(new Player(static_cast<Color>(i)));
    }

    // Save active ones
    if (n_players == 2) {
        active_players.push_back(players.at(Color::Red));
        active_players.push_back(players.at(Color::Yellow));
    } else {
        for (int i=0; i < n_players; ++i) {
            active_players.push_back(players.at(i));
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

    current_player_idx = active_players.size() - 1;
}

void Board::clearMoves() {
    for (auto token : getCurrentPlayer()->getTokens()) {
        token->clearMoveCalculation();
    }
}

void Board::nextTurn()
{
    current_player_idx = (current_player_idx + 1) % active_players.size();
}

int Board::rollDie()
{
    return dice.roll();
}

Token* Board::getToken(Color color, int idx)
{
    return players.at(color)->getTokens().at(idx);
}

bool Board::calculateMoves()
{
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

    return can_move;
}

void Board::moveCurrentPlayerToken(int idx)
{
    getCurrentPlayer()->moveToken(idx, getCurrentPlayerCells());
}

int Board::getLastRoll() const
{
    return dice.getLastRoll();
}

Player* Board::getCurrentPlayer() const
{
    return active_players.at(current_player_idx);
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
