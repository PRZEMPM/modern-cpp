#pragma once

#include "Shape.hpp"

class Circle final : public Shape 
{
public:
    Circle() = delete;
    Circle(double r);
    Circle(const Circle & other) = default;

    double getArea() const override;
    double getPerimeter() const override;
    void print() const override;

    double getRadius() const;

private:
    double r_;
};
