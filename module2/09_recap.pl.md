<!-- .slide: data-background="#111111" -->
# Podsumowanie

___

## Co pamiętasz z dzisiejszej sesji?

___

## Dziwactwa C++

* Lambda - trzeba dodać `mutable` na wypadek, gdybyś miał `[=]` na liście przechwytywania i chcesz zmodyfikować przechwycone elementy
* Lambda - `unique_ptr` na liście przechwytywania `a=std::move(a)`
* Spróbuj zaznaczyć tyle funkcji jako `constexpr` jak to możliwe