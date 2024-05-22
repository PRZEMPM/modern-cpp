#pragma once

#include "Shape.hpp"

class Circle final : public Shape 
{
public:
    using Shape::Shape;
    Circle() = delete;
    Circle(double r);
    Circle(const Circle & other);

    [[deprecated("Function returns the old version of pi. Use the constant std::numbers::pi from the <numbers> library.")]] double getPi() const;
    double getArea() const override;
    double getPerimeter() const override;
    void print() const override;

    double getRadius() const;

private:
    double r_ = 1.0;
};
