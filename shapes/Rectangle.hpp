#pragma once

#include "Shape.hpp"

class Rectangle : public Shape
{
public:
    Rectangle() = delete;
    Rectangle(double x, double y);
    Rectangle(const Rectangle & other);

    virtual double getArea() const override;
    virtual double getPerimeter() const override;
    virtual void print() const override;

    virtual double getX() const final;
    double getY() const;

private:
    double x_ = 1.0;
    double y_ = 1.0;
};
