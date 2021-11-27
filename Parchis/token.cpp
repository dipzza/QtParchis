#include "token.h"
#include <algorithm>

Token::Token() :
    idx(0), next_passed_cells(-1), color(Red)
{}

Token::Token(unsigned int p_idx, enum Color p_color) :
    idx(p_idx), next_passed_cells(-1), color(p_color)
{
    passed_cells = -1;
}

void Token::move(std::vector<Cell *> cells) {
    if (current_cell != nullptr) {
        current_cell->removeToken(this);
    }
    Cell *goal_cell = cells.at(calculateBoardPosition(next_passed_cells));
    goal_cell->addToken(this);
    current_cell = goal_cell;

    passed_cells = next_passed_cells;
}

bool Token::calculateMove(int dice_roll, std::vector<Cell *> cells)
{
    next_passed_cells = -1;

    if(passed_cells == -1) {
        if (dice_roll == 5 && !cells.at(calculateBoardPosition(0))->isBlocked()) {
            next_passed_cells = 0;
        }
    } else {
        int new_next_passed_cells = passed_cells + dice_roll;

        if (new_next_passed_cells <= MAX_PASSED_CELLS) {
            std::vector<Cell *> cells_to_go_through;

            for (int i=passed_cells + 1; i <= new_next_passed_cells; ++i) {
                cells_to_go_through.push_back(cells[calculateBoardPosition(i)]);
            }

            if (!hasBridge(cells_to_go_through)) {
                next_passed_cells = new_next_passed_cells;
            }
        }
    }
    next_board_position = calculateBoardPosition(next_passed_cells);
    return canMove();
}

void Token::clearMoveCalculation() {
    next_passed_cells = -1;
    next_board_position = -1;
}

int Token::getBoardPosition() const {
    return calculateBoardPosition(passed_cells);
}

void Token::reset() {
    passed_cells = -1;
    current_cell->removeToken(this);
    current_cell = nullptr;
}

unsigned int Token::getIdx() const
{
    return idx;
}

int Token::getNextBoardPosition() const
{
    return next_board_position;
}

int Token::calculateBoardPosition(int p_passed_cells) const
{
    if (p_passed_cells > 63) {
        return (p_passed_cells + 4);
    } else if (p_passed_cells == -1) {
        return (p_passed_cells);
    } else {
        switch(color) {
            case Color::Red:
                return (p_passed_cells + 38) % 68;
            case Color::Blue:
                return (p_passed_cells + 21) % 68;
            case Color::Yellow:
                return (p_passed_cells + 4);
            case Color::Green:
                return (p_passed_cells + 55) % 68;
            default:
                return -1;
                break;
        }
    }
}

bool Token::canMove() const {
    return next_passed_cells != -1;
}

bool Token::inNest() const {
    return passed_cells == -1;
}
