#ifndef TOKEN_H
#define TOKEN_H

#include <vector>
#include "qobject.h"
#include "color.h"

class Cell;

class Token : public QObject {
    Q_OBJECT
    Q_PROPERTY(qint32 passed_cells READ getPassedCells WRITE setPassedCells NOTIFY positionChanged)

public:
    Cell *current_cell;

    Token(unsigned int p_idx, enum Color p_color)
        :  idx(p_idx), color(p_color) {}


    bool move(unsigned int moves, std::vector<Cell *> boardCells, std::vector<Cell *> baseCells);
    Q_INVOKABLE int passedCellsToBoardPosition();
    void reset();

    void setCurrentCell(Cell *c) {current_cell = c;}
    Cell *& getCell() {return current_cell;}
    Q_INVOKABLE Color getColor() {return color;}
    int getPassedCells(){return passed_cells;}

signals:
    void positionChanged();

private:
    const unsigned int idx;
    int passed_cells = -1;
    Color color;

    void setPassedCells(int p_passed_cells);
};

#endif // TOKEN_H
