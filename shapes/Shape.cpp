#include "Shape.hpp"
#include <iostream>

void Shape::print() const
{
    std::cout << "Unknown Shape" << std::endl;
}

std::ostream& operator<< (std::ostream & os, Color color)
{
    switch (color)
    {
        case Color::RED:
            os << "RED";
            break;
        case Color::GREEN:
            os << "GREEN";
            break;
        case Color::BLUE:
            os << "BLUE";
            break;
        default:
            os << "UNKNOWN";
    }

    return os;
}
