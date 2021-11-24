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

bool Token::move(unsigned int moves, std::vector<Cell *> boardCells, std::vector<Cell *> baseCells) {
    setPassedCells(passed_cells + moves);
    return true;
}

int Token::getBoardPosition() {
    if (passed_cells > 63) {
        return (passed_cells + 4);
    } else if (passed_cells == -1) {
        return (passed_cells - idx);
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
    passed_cells = 0;
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
    setX_coordinate(BoardPositions::getXCoordinate(color, getBoardPosition()));
    setY_coordinate(BoardPositions::getYCoordinate(color, getBoardPosition()));
    emit positionChanged();
}
