#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <memory>
#include "Shape.hpp"
#include "Rectangle.hpp"
#include "Square.hpp"
#include "Circle.hpp"

#include <chrono>     // Used to calculate execution time fibonacci
#include <iomanip>    // Used to calculate execution time fibonacci
#include <map>        // Used to structured bindings
#include <functional> // std::function

#include "addShape.hpp"

using namespace std;

auto sortByArea = [] (shared_ptr<Shape> first, shared_ptr<Shape> second) 
{    
    if(first == nullptr || second == nullptr)
        return false;
    return (first->getArea() < second->getArea());
};

auto perimeterBiggerThanX = [x = 20] (shared_ptr<Shape> s)
{
    if(s != nullptr)
        return (s->getPerimeter() > x);
    return false;
};

auto areaLessThanX = [x = 10](shared_ptr<Shape> s)
{
    if(s != nullptr)
        return (s->getArea() < x);
    return false;
};

void printCollectionElements(const Collection& collection)
{
    for (auto &el : collection)
    {
        if(el != nullptr)
            (el)->print();
    }
}

void printAreas(const Collection& collection)
{
    for(auto it = collection.begin(); it != collection.end(); ++it)
        if(*it != nullptr)
            cout << (*it)->getArea() << std::endl;
}

void findFirstShapeMatchingPredicate(const Collection& collection,
                                     std::function<bool(shared_ptr<Shape>)>predicate,
                                     std::string info)
{
    auto iter = std::find_if(collection.begin(), collection.end(), predicate);
    if(*iter != nullptr)
    {
        cout << "First shape matching predicate: " << info << endl;
        (*iter)->print();
    }
    else
    {
        cout << "There is no shape matching predicate " << info << endl;
    }
}

constexpr unsigned int fibonacci(unsigned int n)
{
    return (n <= 1) ? n : (fibonacci(n-1)+fibonacci(n-2));
}

int main()
{   
    std::cout << "alignof Circle: " << alignof(Circle) << std::endl;
    
    Collection shapes = 
    {
        make_shared<Circle>(2.0),
        make_shared<Circle>(3.0),
        nullptr,
        make_shared<Circle>(4.0),
        make_shared<Rectangle>(10.0, 5.0),
        make_shared<Square>(3.0),
        make_shared<Circle>(4.0),
    };
    
    shapes.push_back(make_shared<Circle>(Color::GREEN));

    // Used to 9. SFINAE (poziom ekspercki)
    addShape(shapes, make_shared<Rectangle>(8.56, 2.2));
    addShape(shapes, make_shared<Square>(4.23));
    // end code SFINAE
    
    printCollectionElements(shapes);

    cout << "Areas before sort: " << std::endl;
    printAreas(shapes);

    std::sort(shapes.begin(), shapes.end(), sortByArea);

    cout << "Areas after sort: " << std::endl;
    printAreas(shapes);

    auto square = make_shared<Square>(4.0);
    shapes.push_back(square);
    
    findFirstShapeMatchingPredicate(shapes, perimeterBiggerThanX, "perimeter bigger than 20");
    findFirstShapeMatchingPredicate(shapes, areaLessThanX, "area less than 10");

    // Used to calculate execution time fibonacci
    auto start = std::chrono::system_clock::now();
    fibonacci(45);
    auto stop = std::chrono::system_clock::now();
    std::chrono::duration<double> diff = stop - start;
    std::cout << "Fibonacci execution time: " << std::fixed << std::setprecision(6) << diff.count() << " seconds\n";
    // end code execution time fibonacci

    // Used to structured bindings
    std::map<shared_ptr<Shape>, double> map
    {
        {make_shared<Circle>(2.0), 2.0},
        {make_shared<Circle>(Color::RED), 3.3}
    };
    for (const auto& [key, value] : map)
    {
        key->print();
    }
    // end code structured bindings
    
    return 0;
}
