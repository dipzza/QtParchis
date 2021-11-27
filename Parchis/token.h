#ifndef TOKEN_H
#define TOKEN_H

#include "color.h"
#include "cell.h"

#include <vector>
#include "qobject.h"

// Board positions for a token are defined as follows
// -1 : Hasn't left the nest
// 0 to 67 : Common positions on the board that are marked 1 to 68
// 68 to 75 : Specific home positions of the token color

class Cell;

const int LAST_COMMON_BOARD_POS = 67;
const int LAST_BOARD_POS = 75;

class Token : public QObject {
    Q_OBJECT
    Q_PROPERTY(qint32 passed_cells READ getPassedCells WRITE setPassedCells NOTIFY positionChanged)
    Q_PROPERTY(int x_coordinate READ getX_coordinate WRITE setX_coordinate NOTIFY x_coordinateChanged)
    Q_PROPERTY(int y_coordinate READ getY_coordinate WRITE setY_coordinate NOTIFY y_coordinateChanged)


public:
    Cell *current_cell = nullptr;

    Token();
    Token(unsigned int p_idx, enum Color p_color);


    /**
     * @brief Moves token to the specified board position
     * @param board_position Global board position of the board
     * @param goal_cell Cell where the token ends up after moving
     */
    Q_INVOKABLE void move(int new_board_position, std::vector<Cell *> cells);

    /**
     * @brief Calculates to which position will the token move with a diceroll, if any
     * @param dice_roll int value of the dice you would use
     * @param cells All cells that this token can go through ordered
     * @return Global board position the token would move to, -1 if it's not a valid move
     */
    Q_INVOKABLE int calculateMove(int dice_roll, std::vector<Cell *> cells);
    Q_INVOKABLE int getBoardPosition();
    Q_INVOKABLE int calculateBoardPosition(int p_passed_cells);
    void reset();

    void setCurrentCell(Cell *c) {current_cell = c;}
    Cell *& getCell() {return current_cell;}
    Q_INVOKABLE Color getColor() {return color;}
    Q_INVOKABLE QString getColorStr() {return colorToString(color);}
    int getPassedCells(){return passed_cells;}

    int getX_coordinate() const;
    void setX_coordinate(int newX_coordinate);
    int getY_coordinate() const;
    void setY_coordinate(int newY_coordinate);


    Q_INVOKABLE unsigned int getIdx() const;

signals:
    void positionChanged();
    void x_coordinateChanged();
    void y_coordinateChanged();

private:
    const unsigned int idx;
    int passed_cells;
    Color color;

    int x_coordinate;
    int y_coordinate;

    void setPassedCells(int p_passed_cells);
};

#endif // TOKEN_H
