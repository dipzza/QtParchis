#ifndef DICE_H
#define DICE_H

#include <random>
#include <chrono>

#include <qobject.h>

class Dice : public QObject {
    Q_OBJECT
public:
    Dice();
    int roll();
    Q_INVOKABLE int getLastRoll() const;

private:
    int value;
    std::mt19937 generator;
    std::uniform_int_distribution<int> dist;
};

#endif // DICE_H
