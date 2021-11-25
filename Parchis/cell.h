#ifndef CELL_H
#define CELL_H

#include "token.h"
#include <vector>

class Token;

class Cell {
public:

    Token *first_token = nullptr;
    Token *second_token = nullptr;

    Cell();

    bool isBlocked() const;
    void addToken(Token *token);
    void removeToken(Token *token);
};

/**
 * @brief Checks if there is at least one bridge on a list of cells
 * @returns True if there is a brige, False otherwise
 */
bool hasBridge(const std::vector<Cell *> &cells);

#endif // CELL_H
