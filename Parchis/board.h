#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include "qobject.h"
#include "QQmlApplicationEngine"
#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <memory>

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
    Q_INVOKABLE void initialize(int n_players);
    Q_INVOKABLE void moveCurrentPlayerToken(int idx);
    Q_INVOKABLE int rollDie();

    Q_INVOKABLE Token* getToken(Color color, int idx);
    Q_INVOKABLE Color getCurrentPlayerColor() const;
    Q_INVOKABLE QString getState() const;

private:
    std::vector<Cell *> cells;
    std::vector<std::vector<Cell *>> base_cells;
    std::vector<Player *> players;
    std::vector<Player *> active_players;
    Dice dice;
    std::string state = "new_turn";
    int current_player_idx;

    void clearMoves();
    void nextTurn();
    bool calculateMoves();
    Player* getCurrentPlayer() const;
    std::vector<Cell *> getCurrentPlayerCells() const;
};

#endif // BOARD_H
