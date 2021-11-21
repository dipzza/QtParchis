#ifndef DICE_H
#define DICE_H

#include <random>
#include <chrono>

class Dice
{
public:
    Dice();
    int roll();
    int getLastRoll();
private:
    int value;
    std::default_random_engine generator;
    std::uniform_int_distribution<int> dist;
};

#endif // DICE_H
