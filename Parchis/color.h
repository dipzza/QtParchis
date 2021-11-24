#ifndef COLOR_H
#define COLOR_H

#include <iostream>

enum Color {Red, Green, Yellow, Blue};

constexpr const char* colorToString(Color color)
{
    switch (color)
    {
        case Color::Red: return "red";
        case Color::Yellow: return "yellow";
        case Color::Blue: return "blue";
        case Color::Green: return "green";
        default: throw std::invalid_argument("Unimplemented item");
    }
}

#endif // COLOR_H
