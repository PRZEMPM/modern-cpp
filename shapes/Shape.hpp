#pragma once

#include <iostream>

enum class Color : unsigned char
{
    RED = 0,
    GREEN = 1,
    BLUE = 2
};

std::ostream& operator<< (std::ostream & os, Color color);

class Shape
{
protected: 
    Color color_ = Color::RED;

public:
    Shape(Color c) : color_(c) {}
    Shape() {}

    Shape(const Shape& ref)
    {
        color_ = ref.color_;
    }

    virtual ~Shape() {}

    virtual double getArea() const = 0;
    virtual double getPerimeter() const = 0;
    virtual void print() const;
};

