#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include "qobject.h"

#include "color.h"
#include "dice.h"
#include "cell.h"
#include "player.h"

const int BOARD_SIZE = 68;

class Board : public QObject
{
    Q_OBJECT
public:
    Board();
    Board(int n_players);
    ~Board();

    Q_INVOKABLE void nextTurn();

    Dice &getDice();
    const std::vector<Player *> &getPlayers() const;
    const Player* getCurrentPlayer() const;
    Q_INVOKABLE Color getCurrentPlayerColor() const;
    Q_INVOKABLE const std::vector<Cell *> getCurrentPlayerCells() const;

private:
    std::vector<Cell *> cells;
    std::vector<std::vector<Cell *>> base_cells;
    std::vector<Player *> players;
    Dice dice;
    int current_player_idx;
};

#endif // BOARD_H
