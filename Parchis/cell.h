#ifndef CELL_H
#define CELL_H

#include "token.h"
#include <list>
#include <vector>

class Token;

class Cell {
public:
    Cell();
    Cell(unsigned int p_blocking_size);

    bool isBlocked() const;
    void addToken(Token *token);
    void removeToken(Token *token);
private:
    std::list<Token *> tokens;
    unsigned int blocking_size;
};

/**
 * @brief Checks if there is at least one bridge on a list of cells
 * @returns True if there is a brige, False otherwise
 */
bool hasBridge(const std::vector<Cell *> &cells);

#endif // CELL_H
