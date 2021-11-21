#ifndef CELL_H
#define CELL_H

class Token;

class Cell {
public:

    Token *FirstToken = nullptr;
    Token *SecondToken = nullptr;

    Cell();

    bool isBlocked();
};

#endif // CELL_H
