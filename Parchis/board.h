#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include "qobject.h"

#include "color.h"
#include "dice.h"
#include "cell.h"
#include "player.h"
#include "board_positions.h"

const int BOARD_SIZE = 68;

class Board : public QObject
{
    Q_OBJECT
public:
    Board();
    Board(int n_players);
    ~Board();

    Q_INVOKABLE void clearMoves();
    Q_INVOKABLE void nextTurn();
    Q_INVOKABLE bool calculateMoves();

    Q_INVOKABLE int rollDie();
    Q_INVOKABLE int getLastRoll() const;
    const std::vector<Player *> &getPlayers() const;
    Q_INVOKABLE Color getCurrentPlayerColor() const;
    Q_INVOKABLE std::vector<Cell *> getCurrentPlayerCells() const;

private:
    std::vector<Cell *> cells;
    std::vector<std::vector<Cell *>> base_cells;
    std::vector<Player *> players;
    Dice dice;
    int current_player_idx;

    Player* getCurrentPlayer() const;
};

#endif // BOARD_H
