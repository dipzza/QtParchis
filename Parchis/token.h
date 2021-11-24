#ifndef TOKEN_H
#define TOKEN_H

#include <vector>
#include "qobject.h"
#include "color.h"

class Cell;

class Token : public QObject {
    Q_OBJECT
    Q_PROPERTY(qint32 passed_cells READ getPassedCells WRITE setPassedCells NOTIFY positionChanged)
    Q_PROPERTY(int x_coordinate READ getX_coordinate WRITE setX_coordinate NOTIFY x_coordinateChanged)
    Q_PROPERTY(int y_coordinate READ getY_coordinate WRITE setY_coordinate NOTIFY y_coordinateChanged)


public:
    Cell *current_cell;

    Token();
    Token(unsigned int p_idx, enum Color p_color);


    bool move(unsigned int moves, std::vector<Cell *> boardCells, std::vector<Cell *> baseCells);
    Q_INVOKABLE int getBoardPosition();
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


    unsigned int getIdx() const;

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
