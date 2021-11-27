#include "cell.h"

Cell::Cell() :
    blocking_size(2)
{}

Cell::Cell(unsigned int p_blocking_size) :
    blocking_size(p_blocking_size)
{}

bool hasBridge(const std::vector<Cell *> &cells) {
    bool has_bridge = false;

    for (const auto cell : cells) {
        if (cell->isBlocked()) {
            has_bridge = true;
        }
    }

    return has_bridge;
}

bool Cell::isBlocked() const {
    return tokens.size() == blocking_size;
}

void Cell::addToken(Token *token)
{
    tokens.push_front(token);
}

void Cell::removeToken(Token *token)
{
    tokens.remove(token);
}
