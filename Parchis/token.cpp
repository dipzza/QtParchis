#include "token.h"
#include "board_positions.h"

Token::Token() :
    idx(0), color(Red)
{

}

Token::Token(unsigned int p_idx, enum Color p_color) :
    idx(p_idx), color(p_color)
{
    setPassedCells(-1);
}

void Token::move(int board_position, std::vector<Cell *> cells) {
    if (current_cell != nullptr) {
        current_cell->removeToken(this);
    }
    Cell *goal_cell = cells.at(board_position);
    goal_cell->addToken(this);
    setCurrentCell(goal_cell);

    setPassedCells(passed_cells + (board_position - getBoardPosition()));
}

int Token::calculateMove(int dice_roll, std::vector<Cell *> cells)
{
    int new_board_position = -1;

    if(passed_cells == -1) {
        if (dice_roll == 5 && !cells.at(0)->isBlocked()) {
            new_board_position = 0;
        }
    } else {
        new_board_position = getBoardPosition() + dice_roll;

        if (new_board_position > 75) {
            new_board_position = -1;
        } else {
            std::vector<Cell *> cells_to_go_through = std::vector<Cell *>(cells.begin() + getBoardPosition() + 1, cells.begin() + new_board_position + 1);

            if (hasBridge(cells_to_go_through)) {
                new_board_position = -1;
            }
        }
    }

    return new_board_position;
}

int Token::getBoardPosition() {
    if (passed_cells > 63) {
        return (passed_cells + 4);
    } else if (passed_cells == -1) {
        return (passed_cells);
    } else {
        switch(color) {
            case Color::Red:
                return (passed_cells + 38) % 68;
            case Color::Blue:
                return (passed_cells + 21) % 68;
            case Color::Yellow:
                return (passed_cells + 4);
            case Color::Green:
                return (passed_cells + 55) % 68;
            default:
                return -1;
                break;
        }
    }
}

void Token::reset() {
    passed_cells = -1;
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
