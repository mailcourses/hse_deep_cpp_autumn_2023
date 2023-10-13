#include <iostream>

template <double N>
double foo()
{
    return N * 2;
}

int main()
{
    std::cout << foo<5.0>() << std::endl;
}
