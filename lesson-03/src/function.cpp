#include <iostream>
#include <vector>
#include <functional>

using MoveFunction = std::function<void (int& x, int& y)>;

void moveLeft(int &x, int &y)
{
    std::cout << "moveLeft" << std::endl;
}

//MoveFunction getRandomDirection() { ... }

class FunctorDirection
{
public:
    void operator()(int&x, int&y)
    {
        std::cout << "FunctorDirection::operator()" << std::endl;
    }
};

int main()
{
    FunctorDirection fd;
    std::vector<MoveFunction> trajectory =
    {
        [](int& x, int& y) {
            std::cout << "lambda<void(int&, int&)>" << std::endl;
        },
        moveLeft,
        fd
    };

    int x = 0;
    int y = 0;
    for (MoveFunction& func : trajectory)
    {
        func(x, y);
    }
}
