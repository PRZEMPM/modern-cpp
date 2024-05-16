#pragma once

class Shape
{
public:
    virtual ~Shape() {}

    virtual double getArea() const = 0;
    virtual double getPerimeter() const = 0;
    virtual void print() const;

private: 
    enum class Color : unsigned char
    {
        RED = 0,
        GREEN = 1,
        BLUE = 2
    };
    
    Color color_ = Color::RED;
};
