#include "token.h"
#include "board_positions.h"
#include <algorithm>

Token::Token() :
    idx(0), color(Red)
{

}

Token::Token(unsigned int p_idx, enum Color p_color) :
    idx(p_idx), color(p_color)
{
    setPassedCells(-1);
}

void Token::move(int new_passed_cells, std::vector<Cell *> cells) {
    if (current_cell != nullptr) {
        current_cell->removeToken(this);
    }
    Cell *goal_cell = cells.at(calculateBoardPosition(new_passed_cells));
    goal_cell->addToken(this);
    setCurrentCell(goal_cell);

    setPassedCells(new_passed_cells);

}

int Token::calculateMove(int dice_roll, std::vector<Cell *> cells)
{
    int new_passed_cells = -1;

    if(passed_cells == -1) {
        if (dice_roll == 5 && !cells.at(calculateBoardPosition(0))->isBlocked()) {
            new_passed_cells = 0;
        }
    } else {
        new_passed_cells = passed_cells + dice_roll;

        if (new_passed_cells > 75) {
            new_passed_cells = -1;
        } else {
            int current_position = getBoardPosition();
            int next_position = calculateBoardPosition(new_passed_cells);


            std::vector<Cell *> cells_to_go_through;

            if (next_position < current_position) {
                for (int i=current_position + 1; i <= LAST_COMMON_BOARD_POS; ++i) {
                    cells_to_go_through.push_back(cells[i]);
                }

                for (int i=0; i <= next_position; ++i) {
                    cells_to_go_through.push_back(cells[i]);
                }
            } else {
                cells_to_go_through = std::vector<Cell *>(cells.begin() + current_position + 1, cells.begin() + next_position + 1);
            }



            if (hasBridge(cells_to_go_through)) {
                new_passed_cells = -1;
            }
        }
    }

    return new_passed_cells;
}

int Token::getBoardPosition() {
    return calculateBoardPosition(passed_cells);
}

void Token::reset() {
    setPassedCells(-1);
    current_cell->removeToken(this);
    current_cell = nullptr;
}

int Token::getX_coordinate() const
{
    return x_coordinate;
}

void Token::setX_coordinate(int newX_coordinate)
{
    if (x_coordinate == newX_coordinate)
        return;
    x_coordinate = newX_coordinate;
    emit x_coordinateChanged();
}

int Token::getY_coordinate() const
{
    return y_coordinate;
}

void Token::setY_coordinate(int newY_coordinate)
{
    if (y_coordinate == newY_coordinate)
        return;
    y_coordinate = newY_coordinate;
    emit y_coordinateChanged();
}

unsigned int Token::getIdx() const
{
    return idx;
}

void Token::setPassedCells(int p_passed_cells) {
    passed_cells = p_passed_cells;
    setX_coordinate(BoardPositions::getXCoordinate(color, getBoardPosition(), idx));
    setY_coordinate(BoardPositions::getYCoordinate(color, getBoardPosition(), idx));
    emit positionChanged();
}

int Token::calculateBoardPosition(int p_passed_cells)
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
