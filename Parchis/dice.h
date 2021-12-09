#ifndef DICE_H
#define DICE_H

#include <random>
#include <chrono>

#include <qobject.h>

class Dice {
public:
    Dice();
    int roll();
    int getLastRoll() const;

private:
    int value;
    std::mt19937 generator;
    std::uniform_int_distribution<int> dist;
};

#endif // DICE_H
