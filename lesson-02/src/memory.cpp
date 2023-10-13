#include <iostream>

int main()
{
    std::cout << "sizeof(int)=" << sizeof(int) << std::endl;
    std::cout << "sizeof(int32_t)=" << sizeof(int32_t) << std::endl;
    std::cout << "sizeof(int64_t)=" << sizeof(int64_t) << std::endl;
    {
        int* a = (int *)malloc(sizeof(int) * 10);
        a = (int *)realloc(a, sizeof(int) * 5);
        // ...
        //free(a);
    }
    // Memory leak
    return 0;
}
