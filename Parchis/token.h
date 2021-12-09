#ifndef TOKEN_H
#define TOKEN_H

#include "color.h"
#include "cell.h"

#include <vector>
#include "qobject.h"


class Cell;

const int LAST_COMMON_BOARD_POS = 67;
const int LAST_BOARD_POS = 75;
const int MAX_PASSED_CELLS = 71;

class Token : public QObject {
    Q_OBJECT

public:
    Token();
    Token(unsigned int p_idx, enum Color p_color);

    /**
     * @brief Moves token to next_passed_cells
     * @param cells All cells that this token can go through ordered
     */
    Q_INVOKABLE void move(std::vector<Cell *> cells);
    /**
     * @brief Calculate next_passed_cells and next_board_position
     * @param dice_roll int value of the dice you would use
     * @param cells All cells that this token can go through ordered
     * @return True if the token can moves, False if it can't
     */
    bool calculateMove(int dice_roll, std::vector<Cell *> cells);
    void clearMoveCalculation();
    Q_INVOKABLE int calculateBoardPosition(int p_passed_cells) const;
    void reset();

    Q_INVOKABLE bool canMove() const;
    bool inNest() const;
    bool isFinished() const;

    Q_INVOKABLE int getBoardPosition() const;
    int getPassedCells() const;
    Q_INVOKABLE Color getColor() const {return color;}
    Q_INVOKABLE QString getColorStr() const {return colorToString(color);}
    Q_INVOKABLE unsigned int getIdx() const;
    int getNextBoardPosition() const;

private:
    const unsigned int idx;
    Cell *current_cell = nullptr;
    int passed_cells;
    int next_passed_cells;
    int next_board_position;
    Color color;


    Q_PROPERTY(int next_board_position READ getNextBoardPosition CONSTANT)
};

#endif // TOKEN_H
