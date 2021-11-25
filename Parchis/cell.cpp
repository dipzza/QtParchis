#include "cell.h"

Cell::Cell() {

}

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
    return !(first_token == nullptr || second_token == nullptr);
}

void Cell::addToken(Token *token)
{
    if (first_token == nullptr) {
        first_token = token;
    } else if (second_token == nullptr) {
        second_token = token;
    } else {
        throw "Adding token to a full cell";
    }
}

void Cell::removeToken(Token *token)
{
    if (first_token == token) {
        first_token = nullptr;
    } else if (second_token == token) {
        second_token = nullptr;
    } else {
        throw  "Removing token from cell that doesn't exist";
    }
}
