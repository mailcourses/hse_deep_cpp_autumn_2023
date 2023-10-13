#include <iostream>

#include "vector.hpp"

template<class Container, class Index>
auto authAndAccess(const Container& c, Index i) -> decltype(c[i])
{
    // authorize();
    return c[0];
}

template<class T, class U>
auto min(T a, U b) -> decltype(a+b)
{
    return a < b ? a : b;
}

constexpr int sum(int a, int b)
{
    return a + b;
}

void func() {
   // значение переменной будет посчитано на этапе компиляции.
   constexpr int c = sum(5, 12);
   // c = 100; <-- compilation error
}

int main()
{
    auto c = {1,2,3}; // c -> std::initializer_list
    mystd::my_vector<std::string> sv;
    mystd::my_vector<int64_t> iv;

    authAndAccess(sv, 100);
    authAndAccess(iv, 5);

    std::cout << min(10, 5) << std::endl;
    std::cout << min(10, 1.5) << std::endl;
    auto res = min(15.5, 2);
    //std::string s = res;
    //
    func();
}
