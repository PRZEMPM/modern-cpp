<!-- .slide: data-background="#111111" -->
# Structured bindings

___

## Structured bindings

Inicjalizacja rozkładająca struktury, która umożliwia pisanie:
<!-- Ciężko mi znaleźć odpowiednik do de-structuring -->

```cpp
auto [ x, y, z ] = expr;
```

 gdzie typ `expr` to obiekty podobne do krotek, których elementy byłyby powiązane ze zmiennymi `x`, `y` i `z` (które deklaruje ta konstrukcja).

 Typem `expr` mogą być: `std::tuple`, `std::pair`, `std::array` i agregaty.

___
<!-- .slide: style="font-size: 0.95em" -->

## Structured bindings

```c++
using Coordinate = std::pair<int, int>;

Coordinate origin() {
    return Coordinate{0, 0};
}

const auto [ x, y ] = origin();
std::cout << "x: " << x << ", y: " << y;
```
<!-- .element: class="fragment fade-in" -->

```c++
std::unordered_map<std::string, int> mapping {
    {"a", 1},
    {"b", 2},
    {"c", 3}
};

// De-structure by reference.
for (const auto& [key, value] : mapping) {
    // Do something with key and value
}
```
<!-- .element: class="fragment fade-in" -->

___

## Zadanie

Stworzyć `std::map<shared_ptr<Shape>, double>` który zapamięta kształt i jego obwód.

Użyj structured bindings, aby iterować po tej kolekcji i wyświetlić informacje o kształcie (wywołaj funkcję `print()`) oraz obwodzie.