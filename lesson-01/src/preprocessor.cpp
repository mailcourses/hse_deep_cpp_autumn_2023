#include <iostream>

#include "foo.hpp"
#include "boo.hpp"
#include "moo.hpp"

#define MAX(x, y) ( x > y ? x : y )
#define MULT(x, y) (x) * (y)

#define NAME(world) #world
#define JOIN(a, b) NAME(a##b)

int main()
{
/*
 * int a = 5;
 * std::cout << MAX(++a, 0) << std::endl; // a увеличится два раза!
 * std::cout << MAX(++a, 10) << std::endl; // а тут всего лишь один
 */
    int a = 5;
    MAX(++a, 0);
    MAX(++a, 10);
    MULT(a + 10, a - 4);
    moo();
    std::cout << MAX(++a, 0) << std::endl; // a увеличится два раза!
    //#line 100
    std::cout << "Hello, " << NAME(world) << " from "
              << __FILE__ << " and line #" << __LINE__
              << std::endl;
    int Helloworld = 100500;
    // TODO: сделать так, чтобы выводил макрос
    // "Helloworld", а не переменную.
    std::cout << JOIN(Hello, world) << std::endl;
    std::cout << square(1005, 100) << std::endl;
}

