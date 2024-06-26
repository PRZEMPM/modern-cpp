#include "Circle.hpp"
#include <cmath>
#include <numbers>
#include <iostream>

Circle::Circle(double r) : Shape(), r_(r) 
{}

Circle::Circle(const Circle & other) : Shape(other)
{
    r_ = other.getRadius();
}

double Circle::getPi() const
{
    return M_PI;
}

double Circle::getArea() const
{
    static_assert(M_PI != 3.14f, "M_PI jest równe 3.14");

    return M_PI * r_ * r_;
}

double Circle::getPerimeter() const
{
    return 2 * M_PI * r_;
}

double Circle::getRadius() const
{
    return r_;
}

void Circle::print() const
{
    std::cout << "Circle: radius: " << getRadius() << std::endl
              << "          area: " << getArea() << std::endl
              << "     perimeter: " << getPerimeter() << std::endl
              << "         color: " << color_ << std::endl;
}
