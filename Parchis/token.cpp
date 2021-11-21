#include "token.h"

bool Token::move(unsigned int moves, std::vector<Cell *> boardCells, std::vector<Cell *> baseCells) {
    setPassedCells(passed_cells + moves);
    return true;
}

int Token::passedCellsToBoardPosition() {
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

void Token::setPassedCells(int p_passed_cells) {
    passed_cells = p_passed_cells;
    emit positionChanged();
}
