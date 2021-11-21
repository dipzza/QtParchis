#include "dice.h"

Dice::Dice()
    : dist(1, 6)
{
    generator.seed(std::chrono::system_clock::now().time_since_epoch().count());
}

int Dice::roll()
{
    value = dist(generator);
    return value;
}

int Dice::getLastRoll()
{
    return value;
}
