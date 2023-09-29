#include <iostream>



void foo(float)
{
    std::cout << "foo(int8_t)" << std::endl;
}

void foo(double)
{
    std::cout << "foo(int64_t)" << std::endl;
}


int main()
{
    int n1 = 10; // int(const int&)
    int n2 = 20;
    n2 = n1; // operator=
    const int* p1 = &n1;
    // int const *p1 = &n1;
    int * const p2 = &n1;
    std::cout << "1) n1 = " << n1 << ", n2 = " << n2 << std::endl;
    // p2 = &n2; <-- compile error
    *p2 = 30;
    std::cout << "2) n1 = " << n1 << ", n2 = " << n2 << std::endl;
    // *p1 = 40; <-- compile error
    p1 = &n2;
    std::cout << "3) n1 = " << n1 << ", n2 = " << n2 << std::endl;

    /*
     * Ошибка компиляции.
     * int32_t tmp;
     * foo(tmp);
     */

     auto comp = [](int i) { return i % 2 == 0; };
}
