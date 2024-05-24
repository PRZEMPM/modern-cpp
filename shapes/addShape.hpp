#pragma once

#include <memory>
#include <type_traits> // std::is_base_of
#include <vector>
#include "Shape.hpp"

using Collection = std::vector<std::shared_ptr<Shape>>;

template <typename T>
using IsShape = std::enable_if_t<std::is_base_of<Shape, T>::value>;

template <typename T, typename = IsShape<T>>
void addShape(Collection& collection, std::shared_ptr<T> shape)
{
    collection.push_back(shape);
}
